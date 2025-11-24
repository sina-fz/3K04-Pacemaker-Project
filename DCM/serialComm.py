import asyncio
import websockets
import json
import struct
import serial
import math # for ekg testing 

connected = set()
device_connected = {}  # Track connection state per websocket



class PacemakerInputs_template:
    def __init__(self):
        self.port = "COM8" #CHANGE TO COM3
        self.baudrate = 115200
        self.ser = serial.Serial(self.port, baudrate=self.baudrate, timeout=1)
        #self.ser = serial.serial_for_url("loop://",baudrate=self.baudrate, timeout=1) # for testing
        
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
            # Set flag to prevent other tasks from consuming the response
            self.waiting_for_device_info = True
            
            # start of packet (request handhshake)
            packet = bytearray(99)
            packet[0] = 0x16  # SYNC byte 1
            packet[1] = 0x45  # Function code byte 2
            packet[2] = 1 # Flag enable for serial handshake byte 3

            self.ser.write(packet)
            self.ser.flush()

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


    # send request to start/stop EKG data streaming
    def sendEKGRequest(self, start=True):
        if not self.ser.is_open:
            try:
                self.ser.open()
                print("Opened serial comm port for EKG request")
            except serial.SerialException as e:
                print(f"Serial failure on open: {e}")
                return False
        
        try:
            # start of packet (request ekg data streaming for start and stop)
            packet = bytearray(99)
            packet[0] = 0x16  # SYNC byte 1
            packet[1] = 0x36  # EKG request function code byte 2
            packet[2] = 1 if start else 0 # 1 is start, 0 is stop streaming
        
            self.ser.write(packet)
            self.ser.flush()
            return True
            
        except serial.SerialException as e:
            print(f"Serial error sending EKG request: {e}")
            self.close()
            return False

    # waits for EKG data from pacemaker via serial
    async def awaitEKGData(self, websocket):
        # print("=== EKG LOOP STARTED ===") #remove this later
        # loop_count = 0 #remove this later
        while True: # infinte loop while streaming is active
            # loop_count += 1
            # print(f"EKG Loop iteration: {loop_count}")
            
            if not self.ser.is_open:
                print("=== EKG LOOP ENDED: Serial port closed ===")
                return
            try:
                if self.ser.in_waiting >= 99:
                    await asyncio.sleep(0.01)
                    continue
                if self.ser.in_waiting >= 18:
                    packet = self.ser.read(18)

                    # Check header bytes for EKG data
                    if not(packet[0] == 0x16 and packet[1] == 0x20):
                        await asyncio.sleep(0.001)
                        continue
                
                    # Extract packet
                    # atrial_val, ventricular_val, timestamp = struct.unpack
                    
                    # Send EKG data to frontend
                    ekg_data = {
                        "type": "ekg",
                        "Atrial": [{"x": timestamp, "y": atrial_val}],
                        "Ventricular": [{"x": timestamp, "y": ventricular_val}]
                    }
                    await websocket.send(json.dumps(ekg_data))
                    print(f"EKG Data: Atrial={atrial_val:.2f}, Ventricular={ventricular_val:.2f}, Time={timestamp:.2f}")
                    
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

async def egm_simulator(websocket):
    t = 0.0
    dt = 0.004  # 4ms between points = 250 Hz sampling rate
    window_seconds = 10.0  # Keep last 10 seconds of data
    max_points = int(window_seconds / dt)
    egm_data = {  # Fixed: emg -> egm
        "type": "ekg",  # Changed to "ekg" to match frontend expectations
        "Atrial": [], 
        "Ventricular": [],
        "ECG": []
    }
    try:
        while True: 
            t += dt
            atrial_val = 5.0 * math.sin(2 * math.pi * 1.0 * t)
            ventricular_val = 12.0 * math.sin(2 * math.pi * 1.0 * t + 0.6)
            ecg_val = atrial_val * 0.5 + ventricular_val * 0.8
            egm_data["Atrial"].append({"x": t, "y": atrial_val})
            egm_data["Ventricular"].append({"x": t, "y": ventricular_val})
            egm_data["ECG"].append({"x": t, "y": ecg_val})
            for key in ["Atrial", "Ventricular", "ECG"]:
                if len(egm_data[key]) > max_points:
                    egm_data[key].pop(0)
            # send data to frontend
            await websocket.send(json.dumps(egm_data))
            # sample interval
            await asyncio.sleep(dt)

    except asyncio.CancelledError:
        # Task was cancelled; exit gracefully
        pass
    except websockets.exceptions.ConnectionClosedOK:
        # Client disconnected normally; exit gracefully
        pass
    except websockets.exceptions.ConnectionClosedError as e:
        # Client disconnected unexpectedly; log if needed
        print(f"Websocket disconnected: {e}")
        pass

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
                    # Send EKG start request to pacemaker
                    request_sent = PacemakerInputs.sendEKGRequest(start=True)
                    
                    if request_sent:
                        # Start the EKG data receiving task
                        if ekg_task is None or ekg_task.done():
                            ekg_task = asyncio.create_task(PacemakerInputs.awaitEKGData(websocket))
                            print("EKG streaming task started")
                        
                        response = {
                            "type": "EKG_STATUS",
                            "streaming": True,
                            "message": "EKG streaming started"
                        }
                        await websocket.send(json.dumps(response))
                        print("EKG streaming started")
                    else:
                        response = {
                            "type": "EKG_STATUS",
                            "streaming": False,
                            "message": "Failed to start EKG streaming"
                        }
                        await websocket.send(json.dumps(response))
                        print("Failed to start EKG streaming")
                
                elif msg_type == "EKG_STOP_REQUEST":
                    # Send EKG stop request to pacemaker
                    request_sent = PacemakerInputs.sendEKGRequest(start=False)

                    if ekg_task and not ekg_task.done():
                        ekg_task.cancel()
                        try:
                            await ekg_task
                        except asyncio.CancelledError:
                            pass
                        print("EKG streaming task cancelled")
                    
                    if request_sent:
                        response = {
                            "type": "EKG_STATUS",
                            "streaming": False,
                            "message": "EKG streaming stopped"
                        }
                        await websocket.send(json.dumps(response))
                        print("EKG streaming stopped")
                    else:
                        response = {
                            "type": "EKG_STATUS",
                            "streaming": False,
                            "message": "Failed to stop EKG streaming"
                        }
                        await websocket.send(json.dumps(response))
                        print("Failed to stop EKG streaming")
                    
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
