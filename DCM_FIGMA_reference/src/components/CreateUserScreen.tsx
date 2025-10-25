import { useState } from "react";
import { Card } from "./ui/card";
import { Button } from "./ui/button";
import { Input } from "./ui/input";
import { Label } from "./ui/label";
import { Alert, AlertDescription } from "./ui/alert";
import { Heart, AlertCircle, CheckCircle, ArrowLeft } from "lucide-react";

interface CreateUserScreenProps {
  onCreateUser: (username: string, password: string) => boolean;
  onBackToLogin: () => void;
}

export function CreateUserScreen({ onCreateUser, onBackToLogin }: CreateUserScreenProps) {
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const [confirmPassword, setConfirmPassword] = useState("");
  const [error, setError] = useState("");
  const [success, setSuccess] = useState(false);
  const [isLoading, setIsLoading] = useState(false);

  const handleSubmit = async (e: React.FormEvent) => {
    e.preventDefault();
    
    setError("");
    setSuccess(false);

    // Validation
    if (!username.trim() || !password.trim() || !confirmPassword.trim()) {
      setError("Please fill in all fields");
      return;
    }

    if (username.trim().length < 3) {
      setError("Username must be at least 3 characters long");
      return;
    }

    if (password.length < 6) {
      setError("Password must be at least 6 characters long");
      return;
    }

    if (password !== confirmPassword) {
      setError("Passwords do not match");
      return;
    }

    setIsLoading(true);

    // Simulate creation delay
    setTimeout(() => {
      const success = onCreateUser(username.trim(), password);
      
      if (success) {
        setSuccess(true);
        setUsername("");
        setPassword("");
        setConfirmPassword("");
        
        // Auto redirect to login after success
        setTimeout(() => {
          onBackToLogin();
        }, 2000);
      } else {
        const savedUsers = JSON.parse(localStorage.getItem('dcm_users') || '[]');
        if (savedUsers.length >= 10) {
          setError("Maximum number of accounts (10) reached");
        } else {
          setError("Username already exists");
        }
      }
      
      setIsLoading(false);
    }, 1000);
  };

  if (success) {
    return (
      <div className="min-h-screen bg-background flex items-center justify-center p-4">
        <Card className="w-full max-w-md p-8 text-center">
          <CheckCircle className="h-16 w-16 text-green-500 mx-auto mb-4" />
          <h2 className="text-xl font-semibold mb-2">Account Created Successfully!</h2>
          <p className="text-muted-foreground mb-4">
            Redirecting to login screen...
          </p>
          <Button onClick={onBackToLogin} className="w-full">
            Go to Login
          </Button>
        </Card>
      </div>
    );
  }

  return (
    <div className="min-h-screen bg-background flex items-center justify-center p-4">
      <Card className="w-full max-w-md p-8">
        <div className="flex items-center mb-6">
          <Button
            variant="ghost"
            size="sm"
            onClick={onBackToLogin}
            disabled={isLoading}
            className="mr-2 p-2"
          >
            <ArrowLeft className="h-4 w-4" />
          </Button>
          <div className="flex items-center gap-3">
            <Heart className="h-8 w-8 text-red-500" />
            <div>
              <h1 className="text-xl font-semibold">Patient Registration</h1>
              <p className="text-sm text-muted-foreground">Create Your Pacemaker Monitor Account</p>
            </div>
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
            <Label htmlFor="new-username">Username</Label>
            <Input
              id="new-username"
              type="text"
              value={username}
              onChange={(e) => setUsername(e.target.value)}
              placeholder="Choose a username (min 3 characters)"
              disabled={isLoading}
            />
          </div>

          <div className="space-y-2">
            <Label htmlFor="new-password">Password</Label>
            <Input
              id="new-password"
              type="password"
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              placeholder="Enter password (min 6 characters)"
              disabled={isLoading}
            />
          </div>

          <div className="space-y-2">
            <Label htmlFor="confirm-password">Confirm Password</Label>
            <Input
              id="confirm-password"
              type="password"
              value={confirmPassword}
              onChange={(e) => setConfirmPassword(e.target.value)}
              placeholder="Confirm your password"
              disabled={isLoading}
            />
          </div>

          <Button type="submit" className="w-full" disabled={isLoading}>
            {isLoading ? "Creating Account..." : "Create Account"}
          </Button>
        </form>

        <div className="mt-6 p-4 bg-muted rounded-lg">
          <h3 className="font-medium mb-2">Registration Requirements</h3>
          <ul className="text-xs text-muted-foreground space-y-1">
            <li>• All personal information fields are required</li>
            <li>• Username must be at least 3 characters</li>
            <li>• Password must be at least 6 characters</li>
            <li>• For pacemaker patients only</li>
          </ul>
        </div>
      </Card>
    </div>
  );
}