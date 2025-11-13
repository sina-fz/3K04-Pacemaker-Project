import asyncio
import websockets
import time
import json

connected = set()

class PacemakerInputs_template:
    def __init__(self):
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
    try:
        connected.add(websocket)
        async for message in websocket:
            in_data = json.loads(message)
            for key, value in in_data.items():
                if hasattr(PacemakerInputs, key):  # check if the attribute exists
                    setattr(PacemakerInputs, key, value)
            print(PacemakerInputs.lowerRateLimit)
            await websocket.send(f"Echo: {message}")
    except websockets.exceptions.ConnectionClosedError:
        #print("Frontend disconnected unexpectedly")
        pass
    except Exception:
        pass
    finally:
        connectionStarted = False
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
