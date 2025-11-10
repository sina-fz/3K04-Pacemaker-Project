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

//////////////////////////////
const wsRef = useRef<WebSocket | null>(null);

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
      console.log("Message from Python:", event.data);
    };

    ws.onclose = () => {
      console.log("Disconnected from Python backend, retrying in 2s...");
      retryTimeout = setTimeout(connect, 2000); // retry connection
    };
  };

  connect();

  return () => {
    if (wsRef.current) wsRef.current.close();
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
      return JSON.parse(saved);
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
            model: "PaceMaker-3000",
            serialNumber: "MDG387292AJS10",
            lastInterrogation: "2025-10-25 5:26",
            isConnected: true,
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
  });
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
          model: "Placeholder",
          serialNumber: "Placeholder",
          lastInterrogation: "Placeholder",
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

    // Update the user's patient data with new parameters
    setSavedUsers((prev) =>
      prev.map((user) =>
        user.username === currentUser
          ? { ...user, patientData: { ...user.patientData, parameters } }
          : user
      )
    );

    // Update the selected patient with new parameters
    setSelectedPatient((prev) => (prev ? { ...prev, parameters } : null));
    
    // Send new data to Python
    if (wsRef.current && wsRef.current.readyState === WebSocket.OPEN) {
    wsRef.current.send(JSON.stringify(parameters));
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
    // Simulate connection process
    setTimeout(() => {
      setTelemetryState({
        connectionState: "Connected",
        isConnecting: false,
      });
    }, 500);
  };

  const handleDisconnect = () => {
    setTelemetryState({
      connectionState: "Lost",
      isConnecting: false,
    });

    const handleRetry = () => {
      handleConnect();
    };
    const isConnected = telemetryState.connectionState === "Connected";
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
                                  {currentUserData.patientData.device.model}
                                </p>
                              </div>
                              <div>
                                <p className="text-sm text-muted-foreground mb-1">
                                  Serial Number
                                </p>
                                <p className="font-medium font-mono text-sm text-[16px] font-bold">
                                  {
                                    currentUserData.patientData.device
                                      .serialNumber
                                  }
                                </p>
                              </div>
                            </div>

                            <div>
                              <p className="text-sm text-muted-foreground mb-1">
                                Last Interrogation
                              </p>
                              <p className="font-medium">
                                {
                                  currentUserData.patientData.device
                                    .lastInterrogation
                                }
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
                />
              </div>
            )}

            {activeTab === "egm" && (
              <EKGViewer 
                isDeviceConnected={telemetryState.connectionState === "Connected"}
              />
            )}

            {activeTab === "reports" && selectedPatient && <ReportsPanel selectedPatient={selectedPatient} />}
            {activeTab === "about" && (
              <AboutUtilities 
                savedUsers={savedUsers} 
                onDeleteUser={handleDeleteUser} 
                currentUser={currentUser}
                onNewPatient={handleNewPatient}
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
