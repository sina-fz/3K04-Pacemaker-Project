import asyncio
import websockets
import json
import struct
import serial
import math # for ekg testing 
import time

connected = set()
device_connected = {}  # Track connection state per websocket



class PacemakerInputs_template:
    def __init__(self):
        self.port = "COM8" #CHANGE TO COM3
        self.baudrate = 115200
        self.ser = serial.Serial(self.port, baudrate=self.baudrate, timeout=1)
        #self.ser = serial.serial_for_url("loop://",baudrate=self.baudrate, timeout=1) # for testing

        self.write_busy = False

        self.ready_for_EKG = False

        self.serial_lock = asyncio.Lock()
        self.ekg_writer_task = None
        self.ekg_start_time = None  # Track when EKG streaming started for relative timestamps

        self.waiting_for_device_info = False  # Flag to prevent other tasks from consuming device info response
        self.serialNum = 0
        self.deviceID = 0

        self.mode = 0
        self.lowerRateLimit = 0
        self.upperRateLimit = 0
        self.maximumSensorRate = 0
        self.fixedAVDelay = 0
        self.dynamicAVDelay = 0
        self.minimumDynamicAVDelay = 0
        self.sensedAVDelayOffset = 0
        self.atrialAmplitudeRegulated = 0
        self.ventricularAmplitudeRegulated = 0
        self.atrialAmplitudeUnregulated = 0
        self.ventricularAmplitudeUnregulated = 0
        self.atrialPulseWidth = 0
        self.ventricularPulseWidth = 0
        self.atrialSensitivity = 0
        self.ventricularSensitivity = 0
        self.ventricularRefractoryPeriod = 0
        self.atrialRefractoryPeriod = 0
        self.pvarp = 0
        self.pvarpExtension = 0
        self.hysteresisRateLimit = 0
        self.rateSmoothing = 0
        self.atrMode = 0
        self.atrDuration = 0
        self.atrFallbackTime = 0
        self.ventricularBlanking = 0
        self.activityThreshold = 0
        self.reactionTime = 0
        self.responseFactor = 0
        self.recoveryTime = 0

        self.atrDetect = 0
        self.ventDetect = 0
        self.timestamp = 0

        self.modedict = {"AOO": 100, "VOO": 200, "AAI": 112, "VVI": 222, "AOOR": 1000, "AAIR": 1120, "VOOR": 2000, "VVIR": 2220, "DDDR": 3330}

    def mapData(self,message):
        in_data = json.loads(message)                                                     

        for key, value in in_data.items():
            if hasattr(self, key):  # check if the attribute exists
                setattr(self, key, value)


        for key, value in self.modedict.items():
            if(self.mode == key):
                self.mode = value

        if(not isinstance(self.mode,int)):
            self.mode = 0            

        print("Selected mode: ", self.mode) 
        if self.ser.is_open:
            print("Port is open and sending data")
            self.sendData()
        
    # Sends parameters to pacemaker via serial
    def sendData(self):
        if not self.ser.is_open:
            try:
                # For loopback connections, we need to recreate the serial object
                # self.ser = serial.serial_for_url("loop://", baudrate=self.baudrate, timeout=1)
                self.ser.open()
                print("Opened Serial Comm Port")
            except serial.SerialException as e:
                print(f"Serial failure on reopen: {e}")
        try:
            self.write_busy = True

            # Start of packet 
            packet = bytearray()
            packet.append(0x16)  # SYNC byte 1
            packet.append(0x55)  # Function code byte 2

            packet.extend(struct.pack('<I', int(self.mode))) # bytes 3-6
            packet.extend(struct.pack('<I', int(self.upperRateLimit))) # bytes 7-10
            packet.extend(struct.pack('<I', int(self.lowerRateLimit))) # bytes 11-14

            packet.extend(struct.pack('<f', float(self.atrialAmplitudeUnregulated))) # bytes 15-18

            packet.extend(struct.pack('<d', float(self.atrialPulseWidth))) # bytes 19-26

            packet.extend(struct.pack('<f', float(self.ventricularAmplitudeUnregulated))) #bytes 27-30

            packet.extend(struct.pack('<d', float(self.ventricularPulseWidth))) #bytes 31-38

            packet.extend(struct.pack('<I', int(self.atrialRefractoryPeriod))) #bytes 39-42
            packet.extend(struct.pack('<I', int(self.pvarp))) #bytes 43-46
            packet.extend(struct.pack('<I', int(self.hysteresisRateLimit))) #bytes 47-50

            packet.extend(struct.pack('<d', float(self.rateSmoothing))) #bytes 51-58
            packet.extend(struct.pack('<d', float(self.rateSmoothing))) #bytes 59-66
            
            packet.extend(struct.pack('<f', float(self.atrialSensitivity))) #bytes 67-70
            packet.extend(struct.pack('<f', float(self.ventricularSensitivity))) #bytes 71-74

            packet.extend(struct.pack('<I', int(self.ventricularRefractoryPeriod))) #bytes 75-78
            packet.extend(struct.pack('<I', int(self.activityThreshold))) #bytes 79-82
            packet.extend(struct.pack('<I', int(self.reactionTime))) #bytes 83-86
            packet.extend(struct.pack('<I', int(self.responseFactor))) #bytes 87-90
            packet.extend(struct.pack('<I', int(self.recoveryTime))) #bytes 91-94
            packet.extend(struct.pack('<I', int(self.maximumSensorRate))) #bytes 95-98

            if(self.hysteresisRateLimit == 0):
                packet.extend(struct.pack('<B', 0)) #byte 99
            else:
                packet.extend(struct.pack('<B', 1)) #byte 99

            self.ser.write(packet)
            self.ser.flush()

            self.write_busy = False

            print("Parameters sent to pacemaker")

        except serial.SerialException as e:
            print(f"Serial error: {e}")
            self.close()
            return None
        
    # send request for device info via serial
    def sendDeviceInfoRequest(self):
        if not self.ser.is_open:
            try:
                # For loopback connections, we need to recreate the serial object
                #self.ser = serial.serial_for_url("loop://", baudrate=self.baudrate, timeout=1)
                self.ser.open()
                print("Opened serial comm port for device info request")
            except serial.SerialException as e:
                print(f"Serial failure on open: {e}")
                return False
        
        # Clear any stale data in the buffer
        try:
            if self.ser.in_waiting > 0:
                self.ser.reset_input_buffer()
                print(f"Cleared {self.ser.in_waiting} bytes from input buffer")
        except:
            pass
            
        try:
            self.write_busy = True
            # Set flag to prevent other tasks from consuming the response
            self.waiting_for_device_info = True
            
            # start of packet (request handhshake)
            packet = bytearray(99)
            packet[0] = 0x16  # SYNC byte 1
            packet[1] = 0x45  # Function code byte 2
            packet[2] = 1 # Flag enable for serial handshake byte 3

            self.ser.write(packet)
            self.ser.flush()

            self.write_busy = False
            print("Handshake Requested")

            return True
        except serial.SerialException as e:
            print(f"Serial error: {e}")
            self.waiting_for_device_info = False
            self.close()
            return False


    # waits for device info response from pacemaker via serial
    async def awaitDeviceInfoResponse(self, websocket):
        timeout = 5.0  # 5 second timeout
        start_time = asyncio.get_event_loop().time()
        
        while True:
            # Check for timeout
            if asyncio.get_event_loop().time() - start_time > timeout:
                print("Device info response timeout")
                self.waiting_for_device_info = False
                return None
                
            if not self.ser.is_open:
                print("Serial port closed during device info wait")
                self.waiting_for_device_info = False
                return None
            try:
                in_waiting = self.ser.in_waiting
                if in_waiting >= 99:
                    print(f"Found {in_waiting} bytes waiting, reading device info response...")
                    response_packet = self.ser.read(99)
                    
                    # Check header bytes for device info response (await handshake)
                    if not(response_packet[0] == 0x16 and response_packet[1] == 0x29):
                        # invalid packet, but port still active, keep looping
                        await asyncio.sleep(0.0001)
                        continue
                    
                    # Extract two uint32 values (little-endian)
                    self.serialNum = struct.unpack('<I', response_packet[2:6])[0]
                    self.deviceID  = struct.unpack('<I', response_packet[6:10])[0]

                    print("Device Serial Number:", self.serialNum)
                    print("Model #: ", self.deviceID)
                    print("Received device info from pacemaker")
                    
                    # Clear flag now that we got the response
                    self.waiting_for_device_info = False
                    
                    # NEEDS TO BE IMPLEMENTED TO UNPACK DEVICE INFO
                    device_serial_number = self.serialNum
                    device_model = self.deviceID
                    
                    
                    # Send device info to frontend
                    device_info = {
                        "type": "DEVICE_INFO",
                        "serialNumber": device_serial_number,
                        "deviceModel": device_model,
                        "connected": True
                    }
                    await websocket.send(json.dumps(device_info))
                    return device_info
                        
            except serial.SerialException as e:
                print(f"Serial error during device info wait: {e}")
                self.waiting_for_device_info = False
                self.close()
                return None
            except Exception as e:
                print(f"Unexpected error during device info wait: {e}")

            await asyncio.sleep(0.01)

    async def ekg_request_loop(self):
        """Send EKG request packets every 10 ms until cancelled."""
        try:
            while True:
                await self.sendEKGRequest(start=True)
                await asyncio.sleep(0.0001)
        except asyncio.CancelledError:
            await self.sendEKGRequest(start=False)
            print("EKG request loop stopped")


    async def sendEKGRequest(self, start=True):
        async with self.serial_lock:
            try:
                packet = bytearray(99)
                packet[0] = 0x16
                packet[1] = 0x36
                packet[2] = 1 if start else 0

                self.ser.write(packet)
                self.ser.flush()
                self.ready_for_EKG = True
                return True

            except serial.SerialException:
                self.ready_for_EKG = False
                return False

    # waits for EKG data from pacemaker via serial
    async def awaitEKGData(self, websocket):
        # Initialize start time for relative timestamps (milliseconds since stream start)
        if self.ekg_start_time is None:
            self.ekg_start_time = time.time()
        
        while True: # infinte loop while streaming is active
            if not self.ser.is_open:
                print("=== EKG LOOP ENDED: Serial port closed ===")
                self.ekg_start_time = None  # Reset start time when stream ends
                return
            try:
                if self.ser.in_waiting >= 99:
                    packet = self.ser.read(99)
                    # Check header bytes for EKG data
                    if not(packet[0] == 0x16 and packet[1] == 0x20):
                        await asyncio.sleep(0.0001)
                        continue
                
                    # Extract packet
                    self.atrDetect = struct.unpack('<f', packet[2:6])[0]
                    self.ventDetect  = struct.unpack('<f', packet[6:10])[0]
                    
                    # Calculate relative timestamp in milliseconds since stream started
                    current_time = time.time()
                    if self.ekg_start_time is None:
                        self.ekg_start_time = current_time
                    relative_time_ms = (current_time - self.ekg_start_time) * 1000
                    
                    # Send EKG data to frontend with relative timestamp
                    ekg_data = {
                        "type": "ekg",
                        "Atrial": [{"x": relative_time_ms, "y": self.atrDetect}],
                        "Ventricular": [{"x": relative_time_ms, "y": self.ventDetect}]
                    }
                    await websocket.send(json.dumps(ekg_data))
                    print(f"EKG Data: Atrial={self.atrDetect:.2f}, Ventricular={self.ventDetect:.2f}, Time={relative_time_ms:.2f}ms")
                    
            except serial.SerialException as e:
                print(f"Serial error: {e}")
                self.close()
                # print("=== EKG LOOP ENDED: Serial error ===") #remove this later
                return

            await asyncio.sleep(0.001)

    # waits for echoed parameters to verify them with sent parameters
    async def awaitEchoedParameters(self, websocket):
        while True:
            if not self.ser.is_open:
                 return
            try:
                # Skip reading if waiting for device info response
                if self.waiting_for_device_info:
                    await asyncio.sleep(0.0001)
                    continue
                
                # Wait for 99-byte echo packet (same size as sent packet)
                if self.ser.in_waiting >= 99:
                    packet = self.ser.read(99)
                    # Check header bytes for echo packet
                    if not (packet[0] == 0x16 and packet[1] == 0x39):
                        await asyncio.sleep(0.0001)
                        continue

                    print("Received echoed parameters from pacemaker")
                    # Unpack echoed parameters from packet
                    echoed_mode                = struct.unpack('<I', packet[2:6])[0]
                    echoed_upperRateLimit      = struct.unpack('<I', packet[6:10])[0]
                    echoed_lowerRateLimit      = struct.unpack('<I', packet[10:14])[0]

                    echoed_atrialAmplitudeUnregulated  = struct.unpack('<f', packet[14:18])[0]
                    echoed_atrialPulseWidth            = struct.unpack('<d', packet[18:26])[0]

                    echoed_ventricularAmplitudeUnregulated = struct.unpack('<f', packet[26:30])[0]
                    echoed_ventricularPulseWidth           = struct.unpack('<d', packet[30:38])[0]

                    echoed_atrialRefractoryPeriod  = struct.unpack('<I', packet[38:42])[0]
                    echoed_pvarp                   = struct.unpack('<I', packet[42:46])[0]
                    echoed_hysteresisRateLimit     = struct.unpack('<I', packet[46:50])[0]

                    echoed_rateSmoothing_up = struct.unpack('<d', packet[50:58])[0]
                    echoed_rateSmoothing_down = struct.unpack('<d', packet[58:66])[0]  # duplicate in pack

                    echoed_atrialSensitivity       = struct.unpack('<f', packet[66:70])[0]
                    echoed_ventricularSensitivity  = struct.unpack('<f', packet[70:74])[0]

                    echoed_ventricularRefractoryPeriod = struct.unpack('<I', packet[74:78])[0]
                    echoed_activityThreshold           = struct.unpack('<I', packet[78:82])[0]
                    echoed_reactionTime                = struct.unpack('<I', packet[82:86])[0]
                    echoed_responseFactor              = struct.unpack('<I', packet[86:90])[0]
                    echoed_recoveryTime                = struct.unpack('<I', packet[90:94])[0]
                    echoed_maximumSensorRate           = struct.unpack('<I', packet[94:98])[0]
                    
                    verification_result = self.verifyParameters(echoed_mode, echoed_upperRateLimit, echoed_lowerRateLimit, echoed_atrialAmplitudeUnregulated, echoed_atrialPulseWidth, 
                                                                echoed_ventricularAmplitudeUnregulated, echoed_ventricularPulseWidth,echoed_atrialRefractoryPeriod,echoed_pvarp,echoed_hysteresisRateLimit,
                                                                echoed_rateSmoothing_up, echoed_rateSmoothing_down, echoed_atrialSensitivity, echoed_ventricularSensitivity, echoed_ventricularRefractoryPeriod,
                                                                echoed_activityThreshold, echoed_reactionTime, echoed_responseFactor, echoed_recoveryTime, echoed_maximumSensorRate)
                    verification_result = True # assume true before unpacking just for testing (will implement line above after unpacking)
                    if verification_result:
                        print("Parameters verified successfully")
                        # Send verification success to frontend
                        verification_message = {
                            "type": "PARAMETER_VERIFICATION",
                            "status": "verified",
                            "message": "Parameters received and verified"
                        }
                        await websocket.send(json.dumps(verification_message))
                    else:
                        print("Parameter verification failed")
                        # Send verification failure to frontend
                        verification_message = {
                            "type": "PARAMETER_VERIFICATION",
                            "status": "failed",
                            "message": "Parameter mismatch detected"
                        }
                        await websocket.send(json.dumps(verification_message))

            except serial.SerialException as e:
                print(f"Serial error in parameter verification: {e}")
                self.close()
                return

            await asyncio.sleep(0.01)

    def verifyParameters(self, echoed_mode, echoed_upperRateLimit, echoed_lowerRateLimit,
                        echoed_atrialAmplitudeUnregulated, echoed_atrialPulseWidth,
                        echoed_ventricularAmplitudeUnregulated, echoed_ventricularPulseWidth,
                        echoed_atrialRefractoryPeriod, echoed_pvarp, echoed_hysteresisRateLimit,
                        echoed_rateSmoothing_up, echoed_rateSmoothing_down, echoed_atrialSensitivity, echoed_ventricularSensitivity,
                        echoed_ventricularRefractoryPeriod, echoed_activityThreshold,
                        echoed_reactionTime, echoed_responseFactor, echoed_recoveryTime,
                        echoed_maximumSensorRate):
        
        # Compare sent and received values
        # return False on first mismatch of parameter values
        if echoed_mode != self.mode:
            return False
        elif echoed_upperRateLimit != self.upperRateLimit:
            return False
        elif echoed_lowerRateLimit != self.lowerRateLimit:
            return False
        elif echoed_atrialRefractoryPeriod != self.atrialRefractoryPeriod:
            return False
        elif echoed_pvarp != self.pvarp:
            return False
        elif echoed_hysteresisRateLimit != self.hysteresisRateLimit:
            return False
        elif echoed_ventricularRefractoryPeriod != self.ventricularRefractoryPeriod:
            return False
        elif echoed_activityThreshold != self.activityThreshold:
            return False
        elif echoed_reactionTime != self.reactionTime:
            return False
        elif echoed_responseFactor != self.responseFactor:
            return False
        elif echoed_recoveryTime != self.recoveryTime:
            return False
        elif echoed_maximumSensorRate != self.maximumSensorRate:
            return False
        elif echoed_atrialAmplitudeUnregulated != self.atrialAmplitudeUnregulated:
            return False
        elif echoed_atrialPulseWidth != self.atrialPulseWidth:
            return False
        elif echoed_ventricularAmplitudeUnregulated != self.ventricularAmplitudeUnregulated:
            return False
        elif echoed_ventricularPulseWidth != self.ventricularPulseWidth:
            return False
        elif echoed_rateSmoothing_up != self.rateSmoothing:
            return False
        elif echoed_rateSmoothing_down != self.rateSmoothing:
            return False
        # elif echoed_atrialSensitivity != self.atrialSensitivity:
            # return False
        # elif echoed_ventricularSensitivity != self.ventricularSensitivity:
            # return False
        return True

    def close(self):
        if hasattr(self, 'ser') and self.ser.is_open:
            self.ser.close()
            print("Serial port closed")

class ECGData_template:
    def __init__(self):            
        self.AtrDetect = 0
        self.VentDetect = 0
        self.AtrPulse = 0
        self.VentPulse = 0
        self.Time = 0


PacemakerInputs = PacemakerInputs_template()
ECGData = ECGData_template()


async def handler(websocket):
    global PacemakerInputs
    global ECGData

    try:
        connected.add(websocket)
        device_connected[websocket] = False  # Initially not connected to device
        #egm_task = asyncio.create_task(egm_simulator(websocket))
        ekg_task = None  # Track EKG streaming task
        verification_task = asyncio.create_task(PacemakerInputs.awaitEchoedParameters(websocket))
        
        async for message in websocket:
            # Try to parse as JSON for structured messages
            try:
                data = json.loads(message)
                msg_type = data.get("type")
                
                if msg_type == "CONNECT_REQUEST":
                    # Send device info request to pacemaker

                    request_sent = PacemakerInputs.sendDeviceInfoRequest()

                    if request_sent:
                        # Wait for device info response
                        device_info = await PacemakerInputs.awaitDeviceInfoResponse(websocket)
                        
                        if device_info:
                            device_connected[websocket] = True
                            response = {
                                "type": "CONNECTION_STATUS",
                                "state": "Connected"
                            }
                            await websocket.send(json.dumps(response))
                            print("Device connected")
                        else:
                            # Connection failed - timeout or no response
                            response = {
                                "type": "CONNECTION_STATUS",
                                "state": "Lost"
                            }
                            await websocket.send(json.dumps(response))
                            print("Device connection failed")
                    else:
                        # Failed to send request
                        response = {
                            "type": "CONNECTION_STATUS",
                            "state": "Lost"
                        }
                        await websocket.send(json.dumps(response))
                        print("Device connection failed")
                    
                elif msg_type == "DISCONNECT_REQUEST":
                    # Disconnect from device (don't close serial port, just mark as disconnected)
                    device_connected[websocket] = False
                    # PacemakerInputs.close()  # Don't close - keep serial port open for reconnection
                    response = {
                        "type": "CONNECTION_STATUS",
                        "state": "Lost"
                    }
                    await websocket.send(json.dumps(response))
                    print("Device disconnected, Wipe DCM state")
                
                elif msg_type == "EKG_START_REQUEST":
                    # Reset start time when starting a new stream
                    PacemakerInputs.ekg_start_time = None
                    
                    if PacemakerInputs.ekg_writer_task is None or PacemakerInputs.ekg_writer_task.done():
                        PacemakerInputs.ekg_writer_task = asyncio.create_task(PacemakerInputs.ekg_request_loop())

                        # Start reading data too
                        if ekg_task is None or ekg_task.done():
                            ekg_task = asyncio.create_task(PacemakerInputs.awaitEKGData(websocket))

                        # Respond to frontend
                        await websocket.send(json.dumps({
                            "type": "EKG_STATUS",
                            "streaming": True,
                            "message": "EKG streaming started"
                        }))

                elif msg_type == "EKG_STOP_REQUEST":
                    # Reset start time when stopping stream
                    PacemakerInputs.ekg_start_time = None
                    
                    if PacemakerInputs.ekg_writer_task:
                        PacemakerInputs.ekg_writer_task.cancel()
                        try:
                            await PacemakerInputs.ekg_writer_task
                        except asyncio.CancelledError:
                            pass
                        PacemakerInputs.ekg_writer_task = None

                    if ekg_task:
                        ekg_task.cancel()
                        try:
                            await ekg_task
                        except asyncio.CancelledError:
                            pass

                    await websocket.send(json.dumps({
                        "type": "EKG_STATUS",
                        "streaming": False,
                        "message": "EKG streaming stopped"
                    }))
                    
                else:
                    # Handle parameter data or other messages
                    PacemakerInputs.mapData(message)
                    await websocket.send(f"Echo: {message}")
                    
            except json.JSONDecodeError:
                # If not JSON, try to map as parameter data
                print("Getting Weird Data")
                try:
                    PacemakerInputs.mapData(message)
                    await websocket.send(f"Echo: {message}")
                except:
                    pass
                    
    except websockets.exceptions.ConnectionClosedError:
        pass
    except Exception as e:
        print(f"Error in handler: {e}")
    finally:
        # Cancel all tasks
        if ekg_task and not ekg_task.done():
            ekg_task.cancel()
            try:
                await ekg_task
            except asyncio.CancelledError:
                pass
        verification_task.cancel()
        try:
            await verification_task
        except asyncio.CancelledError:
            pass
        connected.remove(websocket)
        if websocket in device_connected:
            del device_connected[websocket]


connectionStarted = False

async def wait_for_connection():
    """Keeps retrying until a websocket client connects"""
    global connectionStarted
    global PacemakerInputs
    print("Serial Communication Script Initialized....")

    # This server will run forever once a connection is made
    async with websockets.serve(handler, "localhost", 3001):
        print("WebSocket server running on ws://localhost:3001")
        while True:
            if len(connected) == 0:
                print("Awaiting Websocket to Front End...")
                if connectionStarted == True:
                    connectionStarted = False
                await asyncio.sleep(2)
            else:
                if connectionStarted == False:
                    print("Connected to DCM")
                    connectionStarted = True
                await asyncio.sleep(1)  # Maintain connection once active

if __name__ == "__main__":
    asyncio.run(wait_for_connection())
