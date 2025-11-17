import asyncio
import websockets
import time
import json

import struct
import serial
import math # for ekg testing 

connected = set()

class PacemakerInputs_template:
    def __init__(self):
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
        self.reactionTime_float = 0
        self.responseFactor_float = 0
        self.recoveryTime_float = 0

    def mapData(self,message):
        print("Data Mapped")
        in_data = json.loads(message)                                                     
        for key, value in in_data.items():
            if hasattr(PacemakerInputs, key):  # check if the attribute exists
                setattr(PacemakerInputs, key, value)
        print(PacemakerInputs.lowerRateLimit)

    def sendData(self):
            port = "COM3"
            baudrate = 115200

            try:
                ser = serial.Serial(port, baudrate=baudrate, timeout=1)
                # Start of packet 
                packet = bytearray()
                packet.append(0x16)  # SYNC byte
                #packet.append(0x55)  # Function code

                for key, value in self.__dict__.items():
                    # Handle unsigned 32-bit integers
                    if key.endswith("_u32"):
                        packet.extend(struct.pack('<I', int(value)))  # little endian 
                    # Handle floats
                    elif key.endswith("_float") or isinstance(value, float):
                        packet.extend(struct.pack('<f', float(value)))
                    else:
                        # default to float for amplitude/sensitivity-like values
                        packet.extend(struct.pack('<f', float(value)))

                ser.write(packet)
                ser.flush()

            except serial.SerialException as e:
                print(f"Serial error: {e}")
            finally:
                if 'ser' in locals() and ser.is_open:
                    ser.close()

class ECGData_template:
    def __init__(self):            
        self.AtrDetect = 0
        self.VentDetect = 0
        self.AtrPulse = 0
        self.VentPulse = 0
        self.Time = 0

async def egm_simulator(websocket):
    t = 0.0
    dt = 0.1
    window_seconds = 100
    max_points = int(window_seconds / dt)
    egm_data = {  # Fixed: emg -> egm
        "type": "ekg",  # Changed to "ekg" to match frontend expectations
        "Atrial": [], 
        "Ventricular": [],
        "ECG": []
    }
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

PacemakerInputs = PacemakerInputs_template()
ECGData = ECGData_template()


async def handler(websocket):
    global PacemakerInputs
    global ECGData

    #global connectionStarted

    try:
        connected.add(websocket)
        egm_task = asyncio.create_task(egm_simulator(websocket))
        async for message in websocket:
            PacemakerInputs.mapData(message)
            await websocket.send(f"Echo: {message}")
    except websockets.exceptions.ConnectionClosedError:
        #print("Frontend disconnected unexpectedly")
        pass
    except Exception:
        pass
    finally:
        egm_task.cancel()
        try:
            await egm_task
        except asyncio.CancelledError:
            pass
        connected.remove(websocket)


connectionStarted = False

async def wait_for_connection():
    """Keeps retrying until a websocket client connects"""
    global connectionStarted
    print("Serial Communication Script Initialized....")

    # This server will run forever once a connection is made
    async with websockets.serve(handler, "localhost", 3001):
        print("WebSocket server running on ws://localhost:3001")
        while True:
            if len(connected) == 0:
                print("Awaiting Websocket to Front End...")
                await asyncio.sleep(2)
            else:
                if connectionStarted == False:
                    print("Connected to DCM")
                    connectionStarted = True
                await asyncio.sleep(1)  # Maintain connection once active

if __name__ == "__main__":
    asyncio.run(wait_for_connection())
