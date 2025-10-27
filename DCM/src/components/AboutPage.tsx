import { useState } from "react";
import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Button } from "./ui/button";
import { Dialog, DialogContent, DialogDescription, DialogHeader, DialogTitle, DialogTrigger } from "./ui/dialog";
import { Badge } from "./ui/badge";
import { AlertDialog, AlertDialogAction, AlertDialogCancel, AlertDialogContent, AlertDialogDescription, AlertDialogFooter, AlertDialogHeader, AlertDialogTitle, AlertDialogTrigger } from "./ui/alert-dialog";
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from "./ui/table";
import { Info, Clock, Power, UserPlus, Building, Calendar, Cpu, Wifi, HardDrive, Code, Trash2, User, Key, Calendar as CalendarIcon } from "lucide-react";

interface User {
    username: string;
    password: string;
    accountNumber: number;
    createdAt: string;
}

interface AboutUtilitiesProps {
    savedUsers: User[];
    onDeleteUser: (username: string) => void;
    currentUser?: string;
  onNewPatient: () => void;
}

export function AboutUtilities({ savedUsers, onDeleteUser, currentUser, onNewPatient }: AboutUtilitiesProps) {
    const [currentTime, setCutrrentTime] = useState(new Date());

    const handleSetClock = () => {
        setCutrrentTime(new Date());
        console.log("System clock synchronized to current time.");
    };

    const handleQuitApplication = () => {
        console.log("Quitting Application");
    };

  const handleNewPatientFlow = () => {
    console.log("Starting New Patient Workflow");
    // Delegate to parent (App.tsx): sign out and navigate to Create User page
    onNewPatient();
  };

    return (
    <div className="space-y-6">
      {/* About Information */}
      <Card>
        <CardHeader className="pb-3">
          <CardTitle className="flex items-center gap-2">
            <Info className="h-5 w-5" />
            DCM Utilities
          </CardTitle>
        </CardHeader>
        <CardContent className="space-y-4">
          <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
            <div className="space-y-4">
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <div>
                  <p className="font-medium">Application Version</p>
                  <p className="text-sm text-muted-foreground">Placeholder</p>
                </div>
              </div>
              
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <div>
                  <p className="font-medium">DCM Serial Number</p>
                  <p className="text-sm text-muted-foreground">Placeholder</p>
                </div>
              </div>
              
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <div>
                  <p className="font-medium">Institution</p>
                  <p className="text-sm text-muted-foreground">McMaster University</p>
                </div>
              </div>
            </div>
            
            <div className="space-y-4">
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <div>
                  <p className="font-medium">Build Date</p>
                  <p className="text-sm text-muted-foreground">Placeholder </p>
                </div>
              </div>
              
              
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <div>
                  <p className="font-medium">Telemetry Status</p>
                  <Badge variant="default">Placeholder</Badge>
                </div>
              </div>
            
              
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <div>
                  <p className="font-medium">Group</p>
                  <p className="text-sm text-muted-foreground">3K04 Group 3</p>
                </div>
              </div>
            </div>
          </div>
        </CardContent>
      </Card>

      {/* Utilities */}
      <Card>
        <CardHeader className="pb-3">
          <CardTitle className="flex items-center gap-2">
            <Clock className="h-5 w-5" />
            System Utilities
          </CardTitle>
        </CardHeader>
        <CardContent className="space-y-4">
          {/* Set Clock */}
          <div className="flex items-center justify-between p-4 border rounded-lg">
            <div className="space-y-1">
              <h4 className="font-medium">Set Device Clock</h4>

              <p className="text-sm text-muted-foreground">
                Current System Time: {currentTime.toLocaleString()}
              </p>
            </div>
            <Button 
              variant="outline" 
              className="flex items-center gap-2"
              onClick={handleSetClock}
            >
              Set Clock
            </Button>
          </div>

          {/* New Patient Flow */}
          <div className="flex items-center justify-between p-4 border rounded-lg">
            <div className="space-y-1">
              <h4 className="font-medium">New Patient Workflow</h4>
              <p className="text-sm text-muted-foreground">
                Start a new patient session and clear data
              </p>
            </div>
            <Button 
              onClick={handleNewPatientFlow} 
              variant="outline" 
              className="flex items-center gap-2"
            >
              New Patient
            </Button>
          </div>

          {/* End Session and Quit */}
          <div className="flex items-center justify-between p-4 border rounded-lg border-red-200 dark:border-red-800">
            <div className="space-y-1">
              <h4 className="font-medium text-red-700 dark:text-red-300">End Telemetry Session</h4>
              <p className="text-sm text-muted-foreground">
                Close application
              </p>
            </div>
            <Button 
              variant="destructive" 
              className="flex items-center gap-2"
              onClick={handleQuitApplication}
            >
              <Power className="h-4 w-4" />
              Quit
            </Button>
          </div>
        </CardContent>
      </Card>

      {/* Developer Section - Only visible to Admin */}
      {currentUser === "Admin" && (
      <Card>
        <CardHeader className="pb-3">
          <CardTitle className="flex items-center gap-2">
            Developer Tools
          </CardTitle>
        </CardHeader>
        <CardContent className="space-y-4">
          <div className="flex items-center justify-between p-4 border rounded-lg">
            <div className="space-y-1">
              <h4 className="font-medium">Account Manager</h4>
            </div>
            <div className="border rounded-lg">
              <Table>
                <TableHeader>
                  <TableRow>
                    <TableHead>
                      <div className="flex items-center gap-2">
                        Username
                      </div>
                    </TableHead>
                    <TableHead>
                      <div className="flex items-center gap-2">
                        Password
                      </div>
                    </TableHead>
                    <TableHead>
                      <div className="flex items-center gap-2">
                        Created
                      </div>
                    </TableHead>
                    <TableHead className="w-[100px]">Actions</TableHead>
                  </TableRow>
                </TableHeader>
                <TableBody>
                  {savedUsers.map((user) => (
                    <TableRow key={user.username}>
                      <TableCell className="font-medium">
                        {user.username}
                      </TableCell>
                      <TableCell className="font-mono text-sm">
                        {user.password}
                      </TableCell>
                      <TableCell className="text-sm">
                        {new Date(user.createdAt).toLocaleDateString()}
                      </TableCell>
                      <TableCell>
                        <Button
                          variant="ghost"
                          size="sm"
                          className="h-8 w-8 p-0 text-red-600 hover:text-red-700 hover:bg-red-50 dark:hover:bg-red-950/20"
                          onClick={() => onDeleteUser(user.username)}
                        >
                          <Trash2 className="h-4 w-4" />
                        </Button>
                      </TableCell>
                    </TableRow>
                  ))}
                </TableBody>
              </Table>
            </div>
            
            {savedUsers.length === 0 && (
              <div className="text-center py-8 text-muted-foreground">
                <User className="h-12 w-12 mx-auto mb-4 opacity-50" />
                <p>No user accounts found</p>
              </div>
            )}
          </div>
        </CardContent>
      </Card>
      )}


    </div>
  );
}
