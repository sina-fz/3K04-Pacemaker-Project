import { useState, useEffect } from "react";
import { Card, CardContent, CardHeader, CardTitle } from "./components/ui/card";
import { Button } from "./components/ui/button";

// Keep only the login components the user implemented
import { UserLogin } from "./components/UserLogin";
import { CreateUserLogin } from "./components/CreateUserLogin";

interface patient {
  name: string;
  dateofbirth: string;
  device: {
    serialNumber: string;
  };
}

interface User {
  username: string;
  password: string;
  accountNumber: number;
  createdAt: string;
  patientData: patient;
}
export default function App() {
  const [isLoggedIn, setIsLoggedIn] = useState(false);
  const [showCreateUser, setShowCreateUser] = useState(false);

  // Minimal login handler: the UserLogin component controls validation; here we
  // just mark logged in when the component reports success.
  const handleLogin = (username: string, password: string): boolean => {
    setIsLoggedIn(true);
    return true;
  };

  const handleCreateUser = (username: string, password: string): boolean => {
    try {
      const raw = localStorage.getItem("dcm_users") || "[]";
      const users = JSON.parse(raw) as { username: string; password: string }[];
      if (users.find((u) => u.username === username)) return false;
      users.push({ username, password });
      localStorage.setItem("dcm_users", JSON.stringify(users));
      return true;
    } catch (e) {
      console.error("Failed to save user", e);
      return false;
    }
  };

  if (!isLoggedIn) {
    if (showCreateUser) {
      return (
        <CreateUserLogin
          onCreateUser={(u, p) => {
            const ok = handleCreateUser(u, p);
            if (ok) setShowCreateUser(false);
            return ok;
          }}
          onBackToLogin={() => setShowCreateUser(false)}
        />
      );
    }

    return (
      <UserLogin
        onLogin={(u, p) => handleLogin(u, p)}
        onNavigateToCreateUser={() => setShowCreateUser(true)}
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
              <p className="text-sm text-muted-foreground">
                {" "}
                Personal Device Management Portal
              </p>
            </div>
          </div>

          <div className="flex items-center ">
            <div className="text-right">
              <p className="text-sm font-medium"> **Change to User Name**</p>
            </div>
          </div>
        </div>
      </header>
    </div>
  );
}
