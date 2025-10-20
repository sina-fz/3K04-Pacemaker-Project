import { useState } from "react";
import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Button } from "./ui/button";
import { Dialog, DialogContent, DialogDescription, DialogHeader, DialogTitle, DialogTrigger } from "./ui/dialog";
import { Badge } from "./ui/badge";
import { Separator } from "./ui/separator";
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
}

export function AboutUtilities({ savedUsers, onDeleteUser }: AboutUtilitiesProps) {
  const [currentTime, setCurrentTime] = useState(new Date());

  const handleSetClock = () => {
    setCurrentTime(new Date());
    console.log('Setting device clock to current time:', currentTime.toLocaleString());
  };

  const handleQuitSession = () => {
    console.log('Ending telemetry session and quitting application');
  };

  const handleNewPatientFlow = () => {
    console.log('Starting new patient workflow');
  };

  return (
    <div className="space-y-6">
      {/* About Information */}
      <Card>
        <CardHeader className="pb-3">
          <CardTitle className="flex items-center gap-2">
            <Info className="h-5 w-5" />
            About DCM Application
          </CardTitle>
        </CardHeader>
        <CardContent className="space-y-4">
          <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
            <div className="space-y-4">
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <Cpu className="h-5 w-5 text-muted-foreground" />
                <div>
                  <p className="font-medium">Application Version</p>
                  <p className="text-sm text-muted-foreground">DCM Software v2.1.5</p>
                </div>
              </div>
              
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <HardDrive className="h-5 w-5 text-muted-foreground" />
                <div>
                  <p className="font-medium">DCM Serial Number</p>
                  <p className="text-sm font-mono">DCM-2024-001</p>
                </div>
              </div>
              
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <Building className="h-5 w-5 text-muted-foreground" />
                <div>
                  <p className="font-medium">Institution</p>
                  <p className="text-sm text-muted-foreground">Cardiology Associates</p>
                </div>
              </div>
            </div>
            
            <div className="space-y-4">
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <Calendar className="h-5 w-5 text-muted-foreground" />
                <div>
                  <p className="font-medium">Build Date</p>
                  <p className="text-sm text-muted-foreground">December 15, 2023</p>
                </div>
              </div>
              
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <Wifi className="h-5 w-5 text-muted-foreground" />
                <div>
                  <p className="font-medium">Telemetry Status</p>
                  <Badge variant="default">Ready</Badge>
                </div>
              </div>
              
              <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                <Info className="h-5 w-5 text-muted-foreground" />
                <div>
                  <p className="font-medium">License</p>
                  <p className="text-sm text-muted-foreground">Clinical Use License</p>
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
                Synchronize the pacemaker clock with system time
              </p>
              <p className="text-sm font-mono">
                Current System Time: {currentTime.toLocaleString()}
              </p>
            </div>
            <Dialog>
              <DialogTrigger asChild>
                <Button variant="outline" className="flex items-center gap-2">
                  <Clock className="h-4 w-4" />
                  Set Clock
                </Button>
              </DialogTrigger>
              <DialogContent>
                <DialogHeader>
                  <DialogTitle>Set Device Clock</DialogTitle>
                  <DialogDescription>
                    Synchronize the device clock with the current system time
                  </DialogDescription>
                </DialogHeader>
                <div className="space-y-4">
                  <div className="text-center space-y-2">
                    <p>This will set the device clock to match the system time:</p>
                    <div className="text-xl font-mono bg-muted/50 p-3 rounded">
                      {currentTime.toLocaleString()}
                    </div>
                  </div>
                  <div className="bg-yellow-50 dark:bg-yellow-950/20 border border-yellow-200 dark:border-yellow-800 rounded-lg p-3">
                    <p className="text-sm text-yellow-800 dark:text-yellow-300">
                      <strong>Warning:</strong> Changing the device clock may affect diagnostic data timestamps. 
                      Ensure the system time is accurate before proceeding.
                    </p>
                  </div>
                  <div className="flex gap-2 pt-4">
                    <Button onClick={handleSetClock} className="flex-1">
                      Confirm Set Clock
                    </Button>
                    <DialogTrigger asChild>
                      <Button variant="outline" className="flex-1">
                        Cancel
                      </Button>
                    </DialogTrigger>
                  </div>
                </div>
              </DialogContent>
            </Dialog>
          </div>

          {/* New Patient Flow */}
          <div className="flex items-center justify-between p-4 border rounded-lg">
            <div className="space-y-1">
              <h4 className="font-medium">New Patient Workflow</h4>
              <p className="text-sm text-muted-foreground">
                Start a new patient session and clear current data
              </p>
            </div>
            <Button 
              onClick={handleNewPatientFlow} 
              variant="outline" 
              className="flex items-center gap-2"
            >
              <UserPlus className="h-4 w-4" />
              New Patient
            </Button>
          </div>

          {/* End Session and Quit */}
          <div className="flex items-center justify-between p-4 border rounded-lg border-red-200 dark:border-red-800">
            <div className="space-y-1">
              <h4 className="font-medium text-red-700 dark:text-red-300">End Telemetry Session</h4>
              <p className="text-sm text-muted-foreground">
                Safely disconnect from device and close application
              </p>
            </div>
            <AlertDialog>
              <AlertDialogTrigger asChild>
                <Button variant="destructive" className="flex items-center gap-2">
                  <Power className="h-4 w-4" />
                  Quit
                </Button>
              </AlertDialogTrigger>
              <AlertDialogContent>
                <AlertDialogHeader>
                  <AlertDialogTitle>End Telemetry Session?</AlertDialogTitle>
                  <AlertDialogDescription>
                    This will safely disconnect from the current device and close the DCM application. 
                    Any unsaved parameter changes will be lost.
                  </AlertDialogDescription>
                </AlertDialogHeader>
                <AlertDialogFooter>
                  <AlertDialogCancel>Cancel</AlertDialogCancel>
                  <AlertDialogAction onClick={handleQuitSession}>
                    End Session & Quit
                  </AlertDialogAction>
                </AlertDialogFooter>
              </AlertDialogContent>
            </AlertDialog>
          </div>
        </CardContent>
      </Card>

      {/* Developer Section */}
      <Card>
        <CardHeader className="pb-3">
          <CardTitle className="flex items-center gap-2">
            <Code className="h-5 w-5" />
            Developer Tools
          </CardTitle>
        </CardHeader>
        <CardContent className="space-y-4">
          <div className="flex items-center justify-between p-4 border rounded-lg">
            <div className="space-y-1">
              <h4 className="font-medium">Account Manager</h4>
              <p className="text-sm text-muted-foreground">
                View and manage all user accounts in the system
              </p>
            </div>
            <Dialog>
              <DialogTrigger asChild>
                <Button variant="outline" className="flex items-center gap-2">
                  <User className="h-4 w-4" />
                  Manage Accounts
                </Button>
              </DialogTrigger>
              <DialogContent className="max-w-4xl max-h-[80vh] overflow-hidden flex flex-col">
                <DialogHeader>
                  <DialogTitle>Account Manager - Developer Tools</DialogTitle>
                  <DialogDescription>
                    View and manage all user accounts. Handle with care - deleted accounts cannot be recovered.
                  </DialogDescription>
                </DialogHeader>
                <div className="flex-1 overflow-auto">
                  <div className="bg-yellow-50 dark:bg-yellow-950/20 border border-yellow-200 dark:border-yellow-800 rounded-lg p-3 mb-4">
                    <p className="text-sm text-yellow-800 dark:text-yellow-300">
                      <strong>Warning:</strong> This is a developer tool. Deleting accounts will permanently remove user data and cannot be undone.
                    </p>
                  </div>
                  
                  <div className="space-y-4">
                    <div className="flex items-center justify-between">
                      <h4 className="font-medium">All User Accounts ({savedUsers.length}/10)</h4>
                      <Badge variant="secondary">{savedUsers.length} accounts registered</Badge>
                    </div>
                    
                    <div className="border rounded-lg">
                      <Table>
                        <TableHeader>
                          <TableRow>
                            <TableHead>
                              <div className="flex items-center gap-2">
                                <User className="h-4 w-4" />
                                Username
                              </div>
                            </TableHead>
                            <TableHead>
                              <div className="flex items-center gap-2">
                                <Key className="h-4 w-4" />
                                Password
                              </div>
                            </TableHead>
                            <TableHead>
                              <div className="flex items-center gap-2">
                                <CalendarIcon className="h-4 w-4" />
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
                                <AlertDialog>
                                  <AlertDialogTrigger asChild>
                                    <Button
                                      variant="ghost"
                                      size="sm"
                                      className="h-8 w-8 p-0 text-red-600 hover:text-red-700 hover:bg-red-50 dark:hover:bg-red-950/20"
                                    >
                                      <Trash2 className="h-4 w-4" />
                                    </Button>
                                  </AlertDialogTrigger>
                                  <AlertDialogContent>
                                    <AlertDialogHeader>
                                      <AlertDialogTitle>Delete User Account</AlertDialogTitle>
                                      <AlertDialogDescription>
                                        Are you sure you want to delete the account for <strong>{user.username}</strong>? 
                                        This action cannot be undone and will permanently remove all user data including saved parameters and device information.
                                      </AlertDialogDescription>
                                    </AlertDialogHeader>
                                    <AlertDialogFooter>
                                      <AlertDialogCancel>Cancel</AlertDialogCancel>
                                      <AlertDialogAction 
                                        onClick={() => onDeleteUser(user.username)}
                                        className="bg-red-600 hover:bg-red-700 text-white"
                                      >
                                        Delete Account
                                      </AlertDialogAction>
                                    </AlertDialogFooter>
                                  </AlertDialogContent>
                                </AlertDialog>
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
                </div>
              </DialogContent>
            </Dialog>
          </div>
        </CardContent>
      </Card>


    </div>
  );
}