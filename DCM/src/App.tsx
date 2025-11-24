import { useState, useEffect, useRef} from "react";
import { Card, CardContent, CardHeader, CardTitle } from "./components/ui/card";
import { Button } from "./components/ui/button";
import { Separator } from "./components/ui/separator";
import { Badge } from "./components/ui/badge";
import { Tabs, TabsContent, TabsList, TabsTrigger } from "./components/ui/tabs";
import { Alert, AlertDescription } from "./components/ui/alert";
// Keep only the login components the user implemented
import { UserLogin } from "./components/UserLogin";
import { CreateUserLogin } from "./components/CreateUserLogin";
import { ParametersTable } from "./components/ParametersTable";
import { ReportsPanel } from "./components/PrintedReports";
import { TelemetryWidget } from "./components/DeviceCard";
import { AboutUtilities } from "./components/AboutPage";
import { EKGViewer } from "./components/EKGViewer";
import {
  Heart,
  Users,
  Radio,
  Settings,
  Activity,
  FileText,
  Info,
  AlertTriangle,
  Wifi,
  WifiOff,
  LogOut,
  Battery,
  Clock,
  Cpu,
  Hash,
} from "lucide-react";
interface Patient {
  id: string;
  name: string;
  dateOfBirth: string;
  patientId: string;
  device: {
    model: string;
    serialNumber: string;
    lastInterrogation: string;
    isConnected: boolean;
  };
  parameters?: {
    [key: string]: number | string;
  };
}

interface User {
  username: string;
  password: string;
  accountNumber: number;
  createdAt: string;
  patientData: Patient;
}

type ConnectionState = "";
export default function App() {
  const [isLoggedIn, setIsLoggedIn] = useState(false);
  const [currentUser, setCurrentUser] = useState<string>("");
  const [showCreateUser, setShowCreateUser] = useState(false);
  const [selectedPatient, setSelectedPatient] = useState<Patient | null>(null);
  const [activeTab, setActiveTab] = useState("connection");
  const [telemetryState, setTelemetryState] = useState({
    connectionState: "Lost" as "Connected" | "Lost" | "Out of Range" | "Noise",
    isConnecting: false,
  });

  const [currentTime, setCurrentTime] = useState(new Date());
  const [ekgData, setEkgData] = useState<{
    Atrial?: {x: number, y: number}[],
    Ventricular?: {x: number, y: number}[],
    ECG?: {x: number, y: number}[]
  } | null>(null);
  const [verificationStatus, setVerificationStatus] = useState<{
    status: "pending" | "verified" | "failed" | null,
    message: string
  }>({ status: null, message: "" });
//////////////////////////////
const wsRef = useRef<WebSocket | null>(null);
const currentUserRef = useRef<string>(currentUser);
const selectedPatientRef = useRef<Patient | null>(selectedPatient);

// Keep refs in sync with state
useEffect(() => {
  currentUserRef.current = currentUser;
  selectedPatientRef.current = selectedPatient;
}, [currentUser, selectedPatient]);

useEffect(() => {
  let ws: WebSocket;
  let retryTimeout: NodeJS.Timeout;

  const connect = () => {
    ws = new WebSocket("ws://localhost:3001");
    wsRef.current = ws;

    ws.onopen = () => {
      console.log("Connected to Python backend");

      if (selectedPatient?.parameters) {
        ws.send(JSON.stringify(selectedPatient.parameters));
      }
    };

    ws.onmessage = (event: MessageEvent) => {
      const rawData = event.data;
      
      // Handle echo messages (they start with "Echo: ")
      if (rawData.startsWith('Echo: ')) {
        return; // Ignore echo messages
      }
      
      // Try to parse as JSON
      try {
        const data = JSON.parse(rawData);
        
        // Debug: Log current state when message received
        if (data.type === "DEVICE_INFO") {
          console.log("=== DEVICE_INFO DEBUG ===");
          console.log("currentUser state:", currentUser);
          console.log("selectedPatient state:", selectedPatient);
          console.log("isLoggedIn:", isLoggedIn);
        }
        
        // Handle different message types
        if (data.type === 'ekg' || data.type === 'egm') {
          // EKG/EGM data received - update state
          setEkgData({
            Atrial: data.Atrial,
            Ventricular: data.Ventricular,
            ECG: data.ECG
          });
        } else if (data.type === "CONNECTION_STATUS") {
          // Connection status updates from Python
          setTelemetryState({
            connectionState: data.state,
            isConnecting: false,
          });
          console.log("Device connection state updated to:", data.state);
          
          // If disconnected, reset device info to "Not available"
          if (data.state === "Lost" || data.state === "Out of Range") {
            if (selectedPatientRef.current && currentUserRef.current) {
              const resetDevice = {
                ...selectedPatientRef.current.device,
                serialNumber: "Not available",
                model: "Not available",
                isConnected: false
              };
              
              // Update selectedPatient state
              setSelectedPatient({
                ...selectedPatientRef.current,
                device: resetDevice
              });
              
              // Also persist to localStorage
              setSavedUsers((prev) => {
                return prev.map((user) =>
                  user.username === currentUserRef.current
                    ? { 
                        ...user, 
                        patientData: { 
                          ...user.patientData, 
                          device: resetDevice
                        } 
                      }
                    : user
                );
              });
            }
          }
        } else if (data.type === "PARAMETER_VERIFICATION") {
          // Parameter verification status from Python
          setVerificationStatus({
            status: data.status,
            message: data.message
          });
          console.log("Parameter verification:", data.status, "-", data.message);
        } else if (data.type === "DEVICE_INFO") {
          // Device info received from pacemaker - update patient device info
          console.log("DEVICE_INFO received:", data);
          console.log("Current user (from ref):", currentUserRef.current);
          console.log("Selected patient (from ref):", selectedPatientRef.current);
          
          if (selectedPatientRef.current && currentUserRef.current) {
            const updatedDevice = {
              ...selectedPatientRef.current.device,
              serialNumber: data.serialNumber,
              model: data.deviceModel,
              lastInterrogation: new Date().toLocaleString(),
              isConnected: true
            };
            
            console.log("Updated device:", updatedDevice);
            
            // Update selectedPatient state
            setSelectedPatient({
              ...selectedPatientRef.current,
              device: updatedDevice
            });
            
            // Also persist to localStorage by updating savedUsers
            setSavedUsers((prev) => {
              const updated = prev.map((user) =>
                user.username === currentUserRef.current
                  ? { 
                      ...user, 
                      patientData: { 
                        ...user.patientData, 
                        device: updatedDevice
                      } 
                    }
                  : user
              );
              console.log("Updated savedUsers:", updated);
              return updated;
            });
          }
          console.log("Device info updated:", data.serialNumber, data.deviceModel);
        } else {
          console.log("Message from Python:", rawData);
        }
      } catch (e) {
        // If it's not valid JSON and not an echo, log it
        if (!rawData.startsWith('Echo: ')) {
          console.log("Error parsing message:", e, "Raw data:", rawData);
        }
      }
    };

    ws.onclose = () => {
      console.log("Disconnected from Python backend, retrying in 2s...");
      retryTimeout = setTimeout(connect, 2000); // retry connection
    };
  };

  connect();

  return () => {
    //if (wsRef.current) wsRef.current.close();
    if (retryTimeout) clearTimeout(retryTimeout);
  };
}, []);
  
//////////////////////////////
  useEffect(() => {
    const timer = setInterval(() => {
      setCurrentTime(new Date());
    }, 1000);
    return () => clearInterval(timer);
  }, []);

  const [savedUsers, setSavedUsers] = useState<User[]>(() => {
    // Load previously saved users from localStorage
    // Use a consistent key name: 'dcm_users'
    const saved = localStorage.getItem("dcm_users");
    if (saved) {
      const users = JSON.parse(saved);
      // Reset device info to "Not available" for all users on load
      return users.map((user: User) => ({
        ...user,
        patientData: {
          ...user.patientData,
          device: {
            ...user.patientData.device,
            model: "Not available",
            serialNumber: "Not available",
            lastInterrogation: user.patientData.device.lastInterrogation,
            isConnected: false,
          }
        }
      }));
    }
    return [
      {
        // If no cache saved for site it will run on incognito
        // If cache saved run on incognito to obtain default.
        username: "john",
        password: "john",
        accountNumber: 1,
        createdAt: "2025-10-01T08:00:00.000Z",
        patientData: {
          id: "1",
          name: "Johnny Boy",
          dateOfBirth: "2005-06-24",
          patientId: "007",
          device: {
            model: "Not available",
            serialNumber: "Not available",
            lastInterrogation: "Never",
            isConnected: false,
          },
          // Default Parameter Values for this patient
          parameters: {
            lowerRateLimit: 60,
            upperRateLimit: 120,
            atrialAmplitude: 3.5,
            atrialPulseWidth: 0.4,
            atrialSensitivity: 0.5,
            ventricularSensitivity: 2.5,
            vrp: 320,
            arp: 250,
          },
        },
      },
    ];
  });

  // Saving new users when useState savedUsers is updated
  useEffect(() => {
    localStorage.setItem("dcm_users", JSON.stringify(savedUsers));
  }, [savedUsers]);

  useEffect(() => {
    if (isLoggedIn && currentUser) {
      const user = savedUsers.find((u) => u.username === currentUser);
      if (user) {
        setSelectedPatient(user.patientData);
      }
    }
  }, [isLoggedIn, currentUser, savedUsers]); // Added dependency array to prevent infinite loop
  const handleLogin = (username: string, password: string): boolean => {
    const user = savedUsers.find(
      (u) => u.username === username && u.password === password
    );
    if (user) {
      setCurrentUser(username);
      setSelectedPatient(user.patientData);
      setIsLoggedIn(true);
      return true;
    }
    return false;
  };

  const handleCreateUser = (username: string, password: string): boolean => {
    if (savedUsers.find((u) => u.username === username)) {
      console.log("user already exists");
      return false;
    }
    if (savedUsers.length >= 10) {
      console.log("user capacity reached 10 users");
      return false;
    }

    // does not break restrictions will continue user creation

    const accountNumber = savedUsers.length + 1;
    const newUser: User = {
      username,
      password,
      accountNumber,
      createdAt: new Date().toISOString(),
      patientData: {
        id: String(accountNumber),
        name: username, // Use username as display name
        dateOfBirth: "",
        patientId: `P00${String(accountNumber).padStart(4, "0")}`,
        device: {
          model: "Not available",
          serialNumber: "Not available",
          lastInterrogation: "Never",
          isConnected: false,
        },
        parameters: {
          lowerRateLimit: 60,
          upperRateLimit: 120,
          atrialAmplitude: 3.5,
          atrialPulseWidth: 0.4,
          ventricularAmplitude: 2.5,
          ventricularPulseWidth: 0.4,
          atrialSensitivity: 0.5,
          ventricularSensitivity: 2.5,
          vrp: 320,
          arp: 250,
        },
      },
    };
    setSavedUsers((prev) => [...prev, newUser]);
    return true;
  };

  const handleParametersSaved = (parameters: any) => {
    if (!selectedPatient || !currentUser) return;

    // Update the user's patient data with new parameters (local state only)
    setSavedUsers((prev) =>
      prev.map((user) =>
        user.username === currentUser
          ? { ...user, patientData: { ...user.patientData, parameters } }
          : user
      )
    );

    // Update the selected patient with new parameters in UI state
    setSelectedPatient((prev) => (prev ? { ...prev, parameters } : null));

    // not sending to backend here anymore.
    // Sending is now exclusively handled by the "Send to Pacemaker" button
    // via handleSendToPacemaker to separate persist vs transmit actions.
  };

  const handleSendToPacemaker = (data: any) => {
    if (wsRef.current && wsRef.current.readyState === WebSocket.OPEN) {
      // Set verification status to pending when sending
      setVerificationStatus({ status: "pending", message: "Waiting for verification..." });
      
      wsRef.current.send(JSON.stringify(data));
      console.log("Sent to pacemaker via WebSocket:", data);
      
      // Update last interrogation timestamp
      const timestamp = new Date().toLocaleString('en-US', {
        year: 'numeric',
        month: '2-digit',
        day: '2-digit',
        hour: '2-digit',
        minute: '2-digit',
        hour12: true
      });
      
      // Update the current user's patient data with new timestamp
      setSavedUsers((prev) =>
        prev.map((user) =>
          user.username === currentUser
            ? { 
                ...user, 
                patientData: { 
                  ...user.patientData, 
                  device: {
                    ...user.patientData.device,
                    lastInterrogation: timestamp
                  }
                } 
              }
            : user
        )
      );
      
      // Update the selected patient with new timestamp
      setSelectedPatient((prev) => 
        prev ? { 
          ...prev, 
          device: {
            ...prev.device,
            lastInterrogation: timestamp
          }
        } : null
      );
      
    } else {
      console.error("WebSocket is not connected. Cannot send parameters.");
    }
  };

  const handleLogout = () => {
    setIsLoggedIn(false);
    setCurrentUser("");
    setSelectedPatient(null);
    setActiveTab("connection");
  };

  const handleConnect = () => {
    setTelemetryState((prev) => ({ ...prev, isConnecting: true }));
    
    // Send connection request to Python backend
    if (wsRef.current && wsRef.current.readyState === WebSocket.OPEN) {
      const message = { type: "CONNECT_REQUEST" };
      wsRef.current.send(JSON.stringify(message));
      console.log("Sent CONNECT_REQUEST to Python backend");
    } else {
      console.error("WebSocket not connected to Python backend");
      setTelemetryState({
        connectionState: "Lost",
        isConnecting: false,
      });
    }
  };

  const handleDisconnect = () => {
    // Send disconnection request to Python backend
    if (wsRef.current && wsRef.current.readyState === WebSocket.OPEN) {
      const message = { type: "DISCONNECT_REQUEST" };
      wsRef.current.send(JSON.stringify(message));
      console.log("Sent DISCONNECT_REQUEST to Python backend");
    }
  };

  const handleStartEKG = () => {
    // Send EKG start request to Python backend
    if (wsRef.current && wsRef.current.readyState === WebSocket.OPEN) {
      const message = { type: "EKG_START_REQUEST" };
      wsRef.current.send(JSON.stringify(message));
      console.log("Sent the start request to Python backend");
    } else {
      console.error("WebSocket not connected to Python backend");
    }
  };

  const handleStopEKG = () => {
    // Send EKG stop request to Python backend
    if (wsRef.current && wsRef.current.readyState === WebSocket.OPEN) {
      const message = { type: "EKG_STOP_REQUEST" };
      wsRef.current.send(JSON.stringify(message));
      console.log("Sent the stop request to Python backend");
    } else {
      console.error("WebSocket not connected to Python backend");
    }
  };

  const handleRetry = () => {
    handleConnect();
  };

  const handleDeleteUser = (username: string) => {
    setSavedUsers((prev) => prev.filter((u) => u.username !== username));
  };

  // When starting a New Patient workflow from About page:
  // - Sign out current session
  // - Navigate to Create User page
  const handleNewPatient = () => {
    setIsLoggedIn(false);
    setCurrentUser("");
    setSelectedPatient(null);
    setActiveTab("connection");
    setShowCreateUser(true);
  };

  if (!isLoggedIn) {
    if (showCreateUser) {
      return (
        <CreateUserLogin
          onCreateUser={handleCreateUser}
          onBackToLogin={() => setShowCreateUser(false)}
        />
      );
    }
    return (
      <UserLogin
        onLogin={handleLogin}
        onNavigateToCreateUser={() => setShowCreateUser(true)}
      />
    );
  }

  const isConnected = telemetryState.connectionState === "Connected";

  return (
    <div className="min-h-screen bg-background">
      {/* Header */}
      <header className="border-b bg-card">
        <div className="flex h-16 items-center justify-between px-6">
          <div className="flex items-center gap-3">
            <div>
              <h1 className="text-xl font-semibold">My Pacemaker Monitor</h1>
              <p className="text-sm text-muted-foreground">
                {" "}
                Personal Device Management Portal
              </p>
            </div>
          </div>

          <div className="flex items-center  gap-4">
            <div className="text-right">
              <p className="text-sm font-medium"> {currentUser}</p>
              <p className="text-xs text-muted-foreground">
                {currentTime.toLocaleTimeString("en-US", {
                  hour: "2-digit",
                  minute: "2-digit",
                  second: "2-digit",
                  hour12: true,
                })}
              </p>
            </div>
            <Separator orientation="vertical" className="h-8" />
            <div className="flex items-center gap-2">
              {isConnected ? (
                <Wifi className="h-5 w-5 text-green-600" />
              ) : (
                <WifiOff className="h-5 w-5 text-gray-400" />
              )}
              <Badge variant={isConnected ? "default" : "secondary"}>
                {telemetryState.connectionState}
              </Badge>
            </div>
            <Button variant="outline" size="sm" onClick={handleLogout}>
              <LogOut className="h-4 w-4 mr-1" />
              Logout
            </Button>
          </div>
        </div>
      </header>

      {/* Main Content */}
      <div className="flex h-[calc(100vh-4rem)]">
        {/* Sidebar Navigation: STARTS*/}
        <aside className="w-64 border-r bg-card">
          <nav className="p-4 space-y-2">
            <Button
              variant={activeTab === "connection" ? "default" : "ghost"}
              className="w-full justify-start min-w-0"
              onClick={() => setActiveTab("connection")}
            >
              <Radio className="mr-2 h-4 w-4 flex-shrink-0" />
              <span className="truncate">Device Connection</span>
            </Button>

            <Button
              variant={activeTab === "parameters" ? "default" : "ghost"}
              className="w-full justify-start min-w-0"
              onClick={() => setActiveTab("parameters")}
            >
              <Settings className="mr-2 h-100 w-4 flex-shrink-0" />
              <span className="truncate">Parameters</span>
            </Button>

            <Button
              variant={activeTab === "egm" ? "default" : "ghost"}
              className="w-full justify-start min-w-0"
              onClick={() => setActiveTab("egm")}
            >
              <Activity className="mr-2 h-4 w-4 flex-shrink-0" />
              <span className="truncate">Strip Chart</span>
            </Button>

            <Button
              variant={activeTab === "reports" ? "default" : "ghost"}
              className="w-full justify-start min-w-0"
              onClick={() => setActiveTab("reports")}
            >
              <FileText className="mr-2 h-4 w-4 flex-shrink-0" />
              <span className="truncate">Reports</span>
            </Button>

            <Separator className="my-2" />

            <Button
              variant={activeTab === "about" ? "default" : "ghost"}
              className="w-full justify-start min-w-0"
              onClick={() => setActiveTab("about")}
            >
              <Info className="mr-2 h-4 w-4 flex-shrink-0" />
              <span className="truncate">Help & Support</span>
            </Button>
          </nav>
        </aside>
        {/* Sidebar Navigation: ENDS */}
        {/* main content for each tab */}
        <main className="flex-1 overflow-auto">
          <div className="p-6">
            {activeTab === "connection" && selectedPatient && (
              <div className="space-y-6">
                {(() => {
                  const currentUserData = savedUsers.find(
                    (u) => u.username === currentUser
                  );

                  return (
                    currentUserData && (
                      <Card className="w-full">
                        <CardHeader className="pb-3">
                          <CardTitle className="flex items-center gap-2">
                            <Users className="h-5 w-5" />
                            Account & Device Information
                          </CardTitle>
                        </CardHeader>
                        <CardContent className="space-y-4">
                          {/* User Information */}
                          <div className="grid grid-cols-2 gap-4">
                            <div>
                              <p className="text-sm text-muted-foreground">
                                Username
                              </p>
                              <p className="font-medium">
                                {currentUserData.username}
                              </p>
                            </div>
                            <div>
                              <p className="text-sm text-muted-foreground">
                                Account Created
                              </p>
                              <p className="font-medium">
                                {new Date(
                                  currentUserData.createdAt
                                ).toLocaleDateString()}
                              </p>
                            </div>
                          </div>

                          <Separator />

                          {/* Device Information */}
                          <div className="space-y-4">
                            <div className="grid grid-cols-2 gap-4">
                              <div>
                                <p className="text-sm text-muted-foreground mb-1">
                                  Device Model
                                </p>
                                <p className="font-medium">
                                  {selectedPatient.device.model}
                                </p>
                              </div>
                              <div>
                                <p className="text-sm text-muted-foreground mb-1">
                                  Serial Number
                                </p>
                                <p className="font-medium">
                                  {selectedPatient.device.serialNumber}
                                </p>
                              </div>
                            </div>

                            <div>
                              <p className="text-sm text-muted-foreground mb-1">
                                Last Interrogation
                              </p>
                              <p className="font-medium">
                                {selectedPatient.device.lastInterrogation}
                              </p>
                            </div>
                          </div>
                        </CardContent>
                      </Card>
                    )
                  );
                })()}
                <TelemetryWidget
                  connectionState={telemetryState.connectionState}
                  onConnect={handleConnect}
                  onDisconnect={handleDisconnect}
                  onRetry={handleRetry}
                  isConnecting={telemetryState.isConnecting}
                />
              </div>
            )}
            {activeTab === "parameters" && selectedPatient && (
              <div className="min-h-screen">
                <ParametersTable
                  selectedPatient={selectedPatient}
                  onParameterSaved={handleParametersSaved}
                  onSendToPacemaker={handleSendToPacemaker}
                  verificationStatus={verificationStatus}
                  isConnected={telemetryState.connectionState === "Connected"}
                />
              </div>
            )}

            {activeTab === "egm" && (
              <EKGViewer 
                isDeviceConnected={telemetryState.connectionState === "Connected"}
                channelData={ekgData || undefined}
                onStartEKG={handleStartEKG}
                onStopEKG={handleStopEKG}
              />
            )}

            {activeTab === "reports" && selectedPatient && (
              <ReportsPanel 
                selectedPatient={selectedPatient}
                deviceInfo={{
                  serialNumber: selectedPatient?.device?.serialNumber,
                  model: selectedPatient?.device?.model,
                }}
              />
            )}
            {activeTab === "about" && (
              <AboutUtilities 
                savedUsers={savedUsers} 
                onDeleteUser={handleDeleteUser} 
                currentUser={currentUser}
                onNewPatient={handleNewPatient}
                deviceSerialNumber={selectedPatient?.device?.serialNumber}
              />
            )}
            {!selectedPatient && activeTab !== "about" && (
              <Card className="p-8 text-center">
                <Heart className="h-12 w-12 mx-auto mb-4 text-muted-foreground" />
                <h3 className="text-lg font-medium mb-2">
                  Loading Your Device Data
                </h3>
                <p className="text-muted-foreground mb-4">
                  Please wait while we load your pacemaker information.
                </p>
              </Card>
            )}
          </div>
        </main>
      </div>
    </div>
  );
}
