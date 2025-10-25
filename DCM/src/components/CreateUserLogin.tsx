// Imports for React and UI components
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

export function CreateUserLogin({ onCreateUser, onBackToLogin }: CreateUserScreenProps) {
    const [username, setUsername] = useState("");
    const [password, setPassword] = useState("");
    const [confirmPassword, setConfirmPassword] = useState("");
    const [error, setError] = useState("");;
    const [success, setSuccess] = useState(false);

    const handleSubmit = async (e: React.FormEvent) => {
        e.preventDefault();
        setError("");
        setSuccess(false);

        // Main Logic:Basic validation
        if (password !== confirmPassword) {
            setError("Passwords do not match.");
            return;
        }

        if (!username || !password) {
            setError("Username and password are required.");
            return;
        }

        setTimeout(() => {
            const success = onCreateUser(username, password);
            if (success) {
                setSuccess(true);
                setUsername("");
                setPassword("");
                setConfirmPassword("");
            }
            else {
                const savedUsers = JSON.parse(localStorage.getItem("users") || '[]');
                if (savedUsers.length >= 10){
                    setError("User limit reached. Cannot create more users.");
                }
                else {
                    setError("Username already exists.");
                }
            }
        }, 500);
    };

    if (success){
        return (
            <div className="min-h-screen bg-background flex items-center justify-center p-4">
                <Card className="w-full max-w-md p-8 text-center">
                    <CheckCircle className="h-16 w-16 text-green-500 mx-auto mb-4" />
                    <h2 className="text-xl font-semibold mb-2">Account Created!</h2>
                    <p className="text-muted-foreground mb-4">Your account has been successfully created.</p>
                    <Button onClick={onBackToLogin} className="w-full">
                        Back to Login
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
                        className="mr-2 p-2"
                        >
                            <ArrowLeft className="h-4 w-4" />
                    </Button>
                    <div className="flex items-center gap-3">
                        <div>
                            <h1 className="text-center text-xl font-bold">Register New Patient</h1>
                            <p className="text-sm text-muted-foreground">Create a new patient account</p>
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
                        <Label htmlFor="username">Username</Label>
                        <Input
                            id="username"
                            type="text"
                            value={username}
                            onChange={(e) => setUsername(e.target.value)}
                            placeholder="Choose a username"
                        />
                    </div>

                    <div className="space-y-2">
                        <Label htmlFor="password">Password</Label>
                        <Input
                            id="password"
                            type="password"
                            value={password}
                            onChange={(e) => setPassword(e.target.value)}
                            placeholder="Choose a password"
                        />
                    </div>

                    <div className="space-y-2">
                        <Label htmlFor="confirmPassword">Confirm Password</Label>
                        <Input
                            id="confirmPassword"
                            type="password"
                            value={confirmPassword}
                            onChange={(e) => setConfirmPassword(e.target.value)}
                            placeholder="Re-enter your password"
                        />
                    </div>

                    <Button type="submit" className="w-full">
                        Create Account
                    </Button>
                </form>

            </Card>
        </div>
    );
}
