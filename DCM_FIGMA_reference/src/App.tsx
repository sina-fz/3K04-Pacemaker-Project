import { useState, useEffect } from "react";
import { Card, CardContent, CardHeader, CardTitle } from "./components/ui/card";
import { Button } from "./components/ui/button";
import { Badge } from "./components/ui/badge";
import { Tabs, TabsContent, TabsList, TabsTrigger } from "./components/ui/tabs";
import { Alert, AlertDescription } from "./components/ui/alert";
import { Separator } from "./components/ui/separator";
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
  Hash
} from "lucide-react";

// Import all our components
import { LoginScreen } from "./components/LoginScreen";
import { CreateUserScreen } from "./components/CreateUserScreen";

import { TelemetryWidget } from "./components/TelemetryWidget";
import { ParametersTable } from "./components/ParametersTable";
import { EGMViewer } from "./components/EGMViewer";
import { ReportsPanel } from "./components/ReportsPanel";
import { AboutUtilities } from "./components/AboutUtilities";

interface Patient {
  id: string;
  name: string;
  dateOfBirth: string;
  patientId: string;
  device: {
    model: string;
    serialNumber: string;
    lastInterrogation: string;
    batteryStatus: 'BOL' | 'ERN' | 'ERT' | 'ERP';
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

export default function App() {
  const [isLoggedIn, setIsLoggedIn] = useState(false);
  const [currentUser, setCurrentUser] = useState<string>("");
  const [showCreateUser, setShowCreateUser] = useState(false);
  const [selectedPatient, setSelectedPatient] = useState<Patient | null>(null);
  const [activeTab, setActiveTab] = useState("connection");
  const [telemetryState, setTelemetryState] = useState({
    connectionState: 'Lost' as 'Connected' | 'Out of Range' | 'Noise' | 'Lost',
    isConnecting: false
  });
  const [currentTime, setCurrentTime] = useState(new Date());

  // Update time every second
  useEffect(() => {
    const timer = setInterval(() => {
      setCurrentTime(new Date());
    }, 1000);
    return () => clearInterval(timer);
  }, []);

  // No longer need separate patient list since each user has their own patient data

  // Load saved users from localStorage with default patient accounts
  const [savedUsers, setSavedUsers] = useState<User[]>(() => {
    const saved = localStorage.getItem('dcm_users');
    if (saved) {
      return JSON.parse(saved);
    }
    // Default patient accounts
    return [
      {
        username: 'john.doe',
        password: 'patient123',
        accountNumber: 1,
        createdAt: '2024-01-01T08:00:00.000Z',
        patientData: {
          id: '1',
          name: 'John Doe',
          dateOfBirth: '1965-03-15',
          patientId: 'P001234',
          device: {
            model: 'Medtronic Advisor XL DR',
            serialNumber: 'ABC123456789',
            lastInterrogation: '2024-01-15 14:30',
            batteryStatus: 'BOL' as const,
            isConnected: true
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
            arp: 250
          }
        }
      },
      {
        username: 'mary.johnson',
        password: 'patient456',
        accountNumber: 2,
        createdAt: '2024-01-02T10:30:00.000Z',
        patientData: {
          id: '2', 
          name: 'Mary Johnson',
          dateOfBirth: '1972-08-22',
          patientId: 'P001235',
          device: {
            model: 'Boston Scientific Accolade MRI',
            serialNumber: 'DEF987654321',
            lastInterrogation: '2024-01-10 09:15',
            batteryStatus: 'ERN' as const,
            isConnected: false
          }
        }
      },
      {
        username: 'robert.wilson',
        password: 'patient789',
        accountNumber: 3,
        createdAt: '2024-01-03T14:15:00.000Z',
        patientData: {
          id: '3',
          name: 'Robert Wilson',
          dateOfBirth: '1958-12-03',
          patientId: 'P001236',
          device: {
            model: 'Abbott Assurity MRI',
            serialNumber: 'GHI555666777',
            lastInterrogation: '2024-01-08 16:45',
            batteryStatus: 'ERT' as const,
            isConnected: false
          }
        }
      }
    ];
  });

  // Save users to localStorage whenever savedUsers changes
  useEffect(() => {
    localStorage.setItem('dcm_users', JSON.stringify(savedUsers));
  }, [savedUsers]);

  // Auto-select the current user's patient data when logged in
  useEffect(() => {
    if (isLoggedIn && currentUser) {
      const user = savedUsers.find(u => u.username === currentUser);
      if (user) {
        setSelectedPatient(user.patientData);
      }
    }
  }, [isLoggedIn, currentUser, savedUsers]);

  const handleLogin = (username: string, password: string): boolean => {
    const user = savedUsers.find(u => u.username === username && u.password === password);
    if (user) {
      setCurrentUser(username);
      setSelectedPatient(user.patientData);
      setIsLoggedIn(true);
      return true;
    }
    return false;
  };

  const handleCreateUser = (username: string, password: string): boolean => {
    if (savedUsers.find(u => u.username === username)) {
      return false; // User already exists
    }
    if (savedUsers.length >= 10) {
      return false; // Maximum 10 accounts
    }
    
    const accountNumber = savedUsers.length + 1;
    const newUser: User = { 
      username, 
      password,
      accountNumber,
      createdAt: new Date().toISOString(),
      patientData: {
        id: String(accountNumber),
        name: username, // Use username as display name
        dateOfBirth: '',
        patientId: `P00${String(accountNumber).padStart(4, '0')}`,
        device: {
          model: 'Unknown Device',
          serialNumber: 'N/A',
          lastInterrogation: 'Never',
          batteryStatus: 'BOL',
          isConnected: false
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
          arp: 250
        }
      }
    };
    setSavedUsers(prev => [...prev, newUser]);
    return true;
  };

  const handleParametersSaved = (parameters: any) => {
    if (!selectedPatient || !currentUser) return;

    // Update the user's patient data with new parameters
    setSavedUsers(prev => prev.map(user => 
      user.username === currentUser 
        ? { ...user, patientData: { ...user.patientData, parameters } }
        : user
    ));

    // Update the selected patient with new parameters
    setSelectedPatient(prev => prev ? { ...prev, parameters } : null);
  };

  const handleLogout = () => {
    setIsLoggedIn(false);
    setCurrentUser("");
    setSelectedPatient(null);
    setActiveTab("connection");
  };

  const handleConnect = () => {
    setTelemetryState(prev => ({ ...prev, isConnecting: true }));
    // Simulate connection process
    setTimeout(() => {
      setTelemetryState({
        connectionState: 'Connected',
        isConnecting: false
      });
    }, 2000);
  };

  const handleDisconnect = () => {
    setTelemetryState({
      connectionState: 'Lost',
      isConnecting: false
    });
  };

  const handleRetry = () => {
    handleConnect();
  };

  const isConnected = telemetryState.connectionState === 'Connected';

  // Show login screen if not logged in
  if (!isLoggedIn) {
    if (showCreateUser) {
      return (
        <CreateUserScreen
          onCreateUser={handleCreateUser}
          onBackToLogin={() => setShowCreateUser(false)}
        />
      );
    }
    return (
      <LoginScreen
        onLogin={handleLogin}
        onShowCreateUser={() => setShowCreateUser(true)}
      />
    );
  }

  return (
    <div className="min-h-screen bg-background">
      {/* Header */}
      <header className="border-b bg-card">
        <div className="flex h-16 items-center justify-between px-6">
          <div className="flex items-center gap-3">
            <div>
              <h1 className="text-xl font-semibold">My Pacemaker Monitor</h1>
              <p className="text-sm text-muted-foreground">Personal Device Management Portal</p>
            </div>
          </div>
          
          <div className="flex items-center gap-4">
            <div className="text-right">
              <p className="text-sm font-medium">{currentUser}</p>
              <p className="text-xs text-muted-foreground">
                {currentTime.toLocaleTimeString('en-US', { 
                  hour: '2-digit', 
                  minute: '2-digit',
                  second: '2-digit',
                  hour12: true 
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
        {/* Sidebar Navigation */}
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
              <Settings className="mr-2 h-4 w-4 flex-shrink-0" />
              <span className="truncate">My Parameters</span>
            </Button>
            
            <Button
              variant={activeTab === "egm" ? "default" : "ghost"}
              className="w-full justify-start min-w-0"
              onClick={() => setActiveTab("egm")}
            >
              <Activity className="mr-2 h-4 w-4 flex-shrink-0" />
              <span className="truncate">Electrogram</span>
            </Button>
            
            <Button
              variant={activeTab === "reports" ? "default" : "ghost"}
              className="w-full justify-start min-w-0"
              onClick={() => setActiveTab("reports")}
            >
              <FileText className="mr-2 h-4 w-4 flex-shrink-0" />
              <span className="truncate">My Reports</span>
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

        {/* Main Content Area */}
        <main className="flex-1 overflow-auto">
          <div className="p-6">
            {activeTab === "connection" && selectedPatient && (
              <div className="space-y-6">
                {/* User Account Information */}
                {(() => {
                  const currentUserData = savedUsers.find(u => u.username === currentUser);
                  const getBatteryStatusColor = (status: string) => {
                    switch (status) {
                      case 'BOL':
                        return 'bg-green-100 text-green-800 border-green-300 dark:bg-green-950/20 dark:text-green-400 dark:border-green-800';
                      case 'ERN':
                        return 'bg-yellow-100 text-yellow-800 border-yellow-300 dark:bg-yellow-950/20 dark:text-yellow-400 dark:border-yellow-800';
                      case 'ERT':
                        return 'bg-orange-100 text-orange-800 border-orange-300 dark:bg-orange-950/20 dark:text-orange-400 dark:border-orange-800';
                      case 'ERP':
                        return 'bg-red-100 text-red-800 border-red-300 dark:bg-red-950/20 dark:text-red-400 dark:border-red-800';
                      default:
                        return 'bg-gray-100 text-gray-800 border-gray-300 dark:bg-gray-950/20 dark:text-gray-400 dark:border-gray-800';
                    }
                  };

                  const getBatteryStatusText = (status: string) => {
                    switch (status) {
                      case 'BOL':
                        return 'Beginning of Life';
                      case 'ERN':
                        return 'Elective Replacement Needed';
                      case 'ERT':
                        return 'Elective Replacement Time';
                      case 'ERP':
                        return 'End of Replacement Period';
                      default:
                        return status;
                    }
                  };

                  return currentUserData && (
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
                            <p className="text-sm text-muted-foreground">Username</p>
                            <p className="font-medium">{currentUserData.username}</p>
                          </div>
                          <div>
                            <p className="text-sm text-muted-foreground">Account Created</p>
                            <p className="font-medium">{new Date(currentUserData.createdAt).toLocaleDateString()}</p>
                          </div>
                        </div>

                        <Separator />

                        {/* Device Information */}
                        <div className="space-y-4">
                          <div className="grid grid-cols-2 gap-4">
                            <div>
                              <p className="text-sm text-muted-foreground mb-1">Device Model</p>
                              <p className="font-medium">{currentUserData.patientData.device.model}</p>
                            </div>
                            <div>
                              <p className="text-sm text-muted-foreground mb-1">Serial Number</p>
                              <p className="font-medium font-mono text-sm text-[16px] font-bold">{currentUserData.patientData.device.serialNumber}</p>
                            </div>
                          </div>

                          <div className="grid grid-cols-2 gap-4">
                            <div>
                              <p className="text-sm text-muted-foreground mb-1">Battery Status</p>
                              <div className={`inline-flex items-center gap-2 px-3 py-1.5 rounded-md border ${getBatteryStatusColor(currentUserData.patientData.device.batteryStatus)}`}>
                                <span className="font-mono font-semibold">{currentUserData.patientData.device.batteryStatus}</span>
                                <span className="text-xs">({getBatteryStatusText(currentUserData.patientData.device.batteryStatus)})</span>
                              </div>
                            </div>
                            <div>
                              <p className="text-sm text-muted-foreground mb-1">Last Interrogation</p>
                              <p className="font-medium">{currentUserData.patientData.device.lastInterrogation}</p>
                            </div>
                          </div>
                        </div>
                      </CardContent>
                    </Card>
                  );
                })()}

                {/* Connection Controls */}
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
                  onParametersSaved={handleParametersSaved}
                />
              </div>
            )}
            
            {activeTab === "egm" && selectedPatient && (
              <EGMViewer />
            )}
            
            {activeTab === "reports" && selectedPatient && (
              <ReportsPanel />
            )}
            
            {activeTab === "about" && (
              <AboutUtilities 
                savedUsers={savedUsers}
                onDeleteUser={(username) => {
                  setSavedUsers(prev => prev.filter(user => user.username !== username));
                }}
              />
            )}
            
            {!selectedPatient && activeTab !== "about" && (
              <Card className="p-8 text-center">
                <Heart className="h-12 w-12 mx-auto mb-4 text-muted-foreground" />
                <h3 className="text-lg font-medium mb-2">Loading Your Device Data</h3>
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