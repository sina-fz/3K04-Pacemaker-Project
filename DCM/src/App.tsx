import { useState, useEffect } from "react";
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
    connectionState: "Lost" as "Connected" | "lost",
    isConnecting: false,
  });

  const [currentTime, setCurrentTime] = useState(new Date());

  useEffect(() => {
    const timer = setInterval(() => {
      setCurrentTime(new Date());
    }, 1000);
    return () => clearInterval(timer);
  }, []);

  const [savedUsers, setSavedUsers] = useState<User[]>(() => {
    const saved = localStorage.getItem("dcm_user");
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
      return false;
    }
    return true;
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
          model: "Unknown Device",
          serialNumber: "N/A",
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
    }, 2000);
  };

  const handleDisconnect = () => {
    setTelemetryState({
      connectionState: "lost",
      isConnecting: false,
    });

    const handleRetry = () => {
      handleConnect();
    };
    const isConnected = telemetryState.connectionState === "Connected";
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
      </div>
    </div>
  );
}
