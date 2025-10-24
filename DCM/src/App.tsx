import React, { useState } from "react";

// Keep only the login components the user implemented
import { UserLogin } from "./components/UserLogin";
import { CreateUserLogin } from "./components/CreateUserLogin";

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
    <div className="min-h-screen flex items-center justify-center">
      You are logged in.
    </div>
  );
}
