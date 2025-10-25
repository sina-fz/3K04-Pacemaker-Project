import { useState } from "react";
import { Card } from "./ui/card";
import { Button } from "./ui/button";
import { Input } from "./ui/input";
import { Label } from "./ui/label";
import { Alert, AlertDescription } from "./ui/alert";
import { Heart, AlertCircle, CheckCircle, ArrowLeft } from "lucide-react";

interface LoginScreenProps {
  onLogin: (username: string, password: string) => boolean;
  onNavigateToCreateUser: () => void;
}

export function UserLogin({onLogin, onNavigateToCreateUser}: LoginScreenProps) {
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");

  const handleSubmit = async (e: React.FormEvent) => {
    e.preventDefault();

    if (!username.trim() || !password.trim()) {
      setError("Please enter both username and password.");
      return;
    }

    setError("");

    setTimeout(() => {
      const success = onLogin(username.trim(), password);
      if (!success) {
        setError("Invalid username or password.");
      }
    }, 500);
  };

  return (
    <div className="min-h-screen bg-background flex items-center justify-center p-4">
      <Card className="w-full max-w-md p-8">
        <div className="flex flex-col items-center mb-8">
          <div className="text-center mb-4">
            <h1 className="text-2xl font-semi">DCM Login</h1>
            <p className="text-muted-foreground">Pacemaker Control Monitor</p>
          </div>
        </div>

        <form onSubmit={handleSubmit} className="space-y-4">
          {error && (
            <Alert variant="destructive">
              <AlertCircle className="h-4 w-4" />
              <AlertDescription>{error}</AlertDescription>
            </Alert>
          )}

          <div className="space-y-2">
            <Label htmlFor="username">Username</Label>
            <Input
              id="username"
              type="text"
              value={username}
              onChange={(e) => setUsername(e.target.value)}
              placeholder="Enter your username"
            />
          </div>

          <div className="space-y-2">
            <Label htmlFor="password">Password</Label>
            <Input
              id="password"
              type="password"
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              placeholder="Enter your password"
            />
          </div>

          <Button type="submit" className="w-full">
            Login
          </Button>
        </form>

        <div className="mt-6 text-center">
            <p className="text-sm text-muted-foreground mb-2">
                Don't have an account?
            </p>
            <Button
                variant="outline"
                onClick={onNavigateToCreateUser}
                className="w-full"
            >
                Create Account
            </Button>
        </div>

        <div className="mt-6 p-4 bg-muted rounded-lg">
            <p className="text-xs text-muted-foreground text-center">
                Clinical Pacemaker Management System
                <br />
                3K04
            </p>
        </div>
      </Card>
    </div>
  );
}
