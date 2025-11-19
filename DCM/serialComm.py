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
        self.port = "COM1" #CHANGE TO COM3
        self.baudrate = 115200
        self.ser = serial.Serial(self.port, baudrate=self.baudrate, timeout=1)
        

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

        self.modedict = {"AOO": 100, "VOO": 200, "AAI": 112, "VVI": 222, "AOOR": 1000, "AAIR": 1120, "VOOR": 2000, "VVIR": 2220}

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
        self.sendData()

    def sendData(self):
        if not self.ser.is_open:
            try:
                self.ser.open()
                print("Opened Serial Comm Port")
            except serial.SerialException as e:
                print("Serial failure on reopen: {e}")
        try:
            # Start of packet 
            packet = bytearray()
            packet.append(0x16)  # SYNC byte
            packet.append(0x55)  # Function code
            # for key, value in self.__dict__.items():
            #     # Handle unsigned 32-bit integers
            #     if key.endswith("_u32"):
            #         packet.extend(struct.pack('<I', int(value)))  # little endian 

            packet.extend(struct.pack('<I', int(self.mode)))
            packet.extend(struct.pack('<I', int(self.upperRateLimit)))
            packet.extend(struct.pack('<I', int(self.lowerRateLimit)))

            packet.extend(struct.pack('<f', float(self.atrialAmplitudeUnregulated)))

            packet.extend(struct.pack('<d', float(self.atrialPulseWidth)))

            packet.extend(struct.pack('<f', float(self.ventricularAmplitudeUnregulated)))

            packet.extend(struct.pack('<d', float(self.ventricularPulseWidth))) #GPT says doubles via serial comm are tricky

            packet.extend(struct.pack('<I', int(self.atrialRefractoryPeriod)))
            packet.extend(struct.pack('<I', int(self.pvarp)))
            packet.extend(struct.pack('<I', int(self.hysteresisRateLimit)))

            packet.extend(struct.pack('<d', float(self.rateSmoothing)))
            packet.extend(struct.pack('<d', float(self.rateSmoothing)))
            
            packet.extend(struct.pack('<f', float(self.atrialSensitivity)))
            packet.extend(struct.pack('<f', float(self.ventricularSensitivity)))

            packet.extend(struct.pack('<I', int(self.ventricularRefractoryPeriod)))
            packet.extend(struct.pack('<I', int(self.activityThreshold)))
            packet.extend(struct.pack('<I', int(self.reactionTime)))
            packet.extend(struct.pack('<I', int(self.responseFactor)))
            packet.extend(struct.pack('<I', int(self.recoveryTime)))
            packet.extend(struct.pack('<I', int(self.maximumSensorRate)))

            packet.extend(struct.pack('<B', int(self.hysteresisRateLimit))) #missing HFLag from DCM

            self.ser.write(packet)
            self.ser.flush()

            print("Data Sent to Board")

        except serial.SerialException as e:
            print(f"Serial error: {e}")
            self.close()


    async def awaitEKGData(self):
        while True:
            if self.ser.is_open:
                print("Awaiting")
                try:
                    # Check if at least 4 bytes are available (size of uint32)
                    if self.ser.in_waiting >= 4:
                        raw = self.ser.read(4)  # Read 4 bytes
                        value = struct.unpack('<I', raw)[0]  # Little-endian uint32
                        print("Received EKG data from board:", value)
                        #Send to DCM
                except serial.SerialException as e:
                    print(f"Serial error: {e}")
                    self.close()  # Close port if error occurs
            else:
                return
            # Wait 1 ms before checking again
            await asyncio.sleep(0.001)

    
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
        egm_task = asyncio.create_task(egm_simulator(websocket))
        test_recieve = asyncio.create_task(PacemakerInputs.awaitEKGData()) 
        async for message in websocket:
            # Try to parse as JSON for structured messages
            try:
                data = json.loads(message)
                msg_type = data.get("type")
                
                if msg_type == "CONNECT_REQUEST":
                    # Simulate device connection (NEEDS TO BE REPLACED WITH ACTUAL SERIAL CONNECTION LOGIC)
                    device_connected[websocket] = True
                    response = {
                        "type": "CONNECTION_STATUS",
                        "state": "Connected"
                    }
                    await websocket.send(json.dumps(response))
                    print("Device connected")
                    
                elif msg_type == "DISCONNECT_REQUEST":
                    # Simulate device disconnection (NEEDS TO BE REPLACED WITH ACTUAL SERIAL DISCONNECTION LOGIC)
                    device_connected[websocket] = False
                    response = {
                        "type": "CONNECTION_STATUS",
                        "state": "Lost"
                    }
                    await websocket.send(json.dumps(response))
                    print("Device disconnected")
                    
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
        egm_task.cancel()
        try:
            await egm_task
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
                if PacemakerInputs.ser.is_open:                
                    try:
                        PacemakerInputs.ser.close()
                        print("Serial port closed")
                    except:
                        print("Serial failure on close: {e}")
                await asyncio.sleep(2)
            else:
                if connectionStarted == False:
                    print("Connected to DCM")
                    connectionStarted = True
                if not PacemakerInputs.ser.is_open:                
                    try:
                        PacemakerInputs.ser.open()
                        print("Serial port opened")
                    except serial.SerialException as e:                        
                        print("Serial failure on reopen: {e}")
                await asyncio.sleep(1)  # Maintain connection once active

if __name__ == "__main__":
    asyncio.run(wait_for_connection())
