import asyncio
import websockets
import time

connected = set()

async def handler(websocket):
    try:
        connected.add(websocket)
        async for message in websocket:
            print(f"Received from frontend: {message}") #yipeeee!
            await websocket.send(f"Echo: {message}")
    except websockets.exceptions.ConnectionClosedError:
        #print("Frontend disconnected unexpectedly")
        pass
    except Exception:
        pass
    finally:
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
