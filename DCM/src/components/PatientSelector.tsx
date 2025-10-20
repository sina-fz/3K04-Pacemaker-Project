import { useState } from "react";
import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Button } from "./ui/button";
import { Input } from "./ui/input";
import { Dialog, DialogContent, DialogDescription, DialogHeader, DialogTitle, DialogTrigger } from "./ui/dialog";
import { Label } from "./ui/label";
import { Badge } from "./ui/badge";
import { Search, Plus, User, Calendar, Hash, Stethoscope } from "lucide-react";
import { DeviceCard } from "./DeviceCard";

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



interface PatientSelectorProps {
  patients: Patient[];
  onPatientSelect: (patient: Patient) => void;
  onAddPatient: (patient: Patient) => void;
  selectedPatient: Patient | null;
}

export function PatientSelector({ patients, onPatientSelect, onAddPatient, selectedPatient }: PatientSelectorProps) {
  const [searchTerm, setSearchTerm] = useState('');
  const [isNewPatientOpen, setIsNewPatientOpen] = useState(false);
  const [newPatient, setNewPatient] = useState({
    name: '',
    dateOfBirth: '',
    patientId: ''
  });

  const filteredPatients = patients.filter(patient =>
    patient.name.toLowerCase().includes(searchTerm.toLowerCase()) ||
    patient.patientId.toLowerCase().includes(searchTerm.toLowerCase())
  );

  const handleNewPatient = () => {
    if (!newPatient.name || !newPatient.dateOfBirth || !newPatient.patientId) {
      return;
    }

    const newPatientData: Patient = {
      id: String(patients.length + 1),
      name: newPatient.name,
      dateOfBirth: newPatient.dateOfBirth,
      patientId: newPatient.patientId,
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
    };

    onAddPatient(newPatientData);
    setIsNewPatientOpen(false);
    setNewPatient({
      name: '',
      dateOfBirth: '',
      patientId: ''
    });
  };

  return (
    <div className="space-y-6">
      {/* Search and Actions */}
      <Card>
        <CardHeader className="pb-3">
          <div className="flex items-center justify-between">
            <CardTitle className="flex items-center gap-2">
              <Stethoscope className="h-5 w-5" />
              Patient Selection
            </CardTitle>
            <Dialog open={isNewPatientOpen} onOpenChange={setIsNewPatientOpen}>
              <DialogTrigger asChild>
                <Button className="flex items-center gap-2">
                  <Plus className="h-4 w-4" />
                  New Patient
                </Button>
              </DialogTrigger>
              <DialogContent className="max-w-md">
                <DialogHeader>
                  <DialogTitle>Add New Patient</DialogTitle>
                  <DialogDescription>
                    Enter patient information to add a new patient record
                  </DialogDescription>
                </DialogHeader>
                <div className="space-y-4">
                  <div>
                    <Label htmlFor="patient-name">Patient Name *</Label>
                    <Input 
                      id="patient-name"
                      value={newPatient.name}
                      onChange={(e) => setNewPatient(prev => ({ ...prev, name: e.target.value }))}
                      placeholder="Enter patient name"
                    />
                  </div>
                  
                  <div>
                    <Label htmlFor="patient-dob">Date of Birth *</Label>
                    <Input 
                      id="patient-dob"
                      type="date"
                      value={newPatient.dateOfBirth}
                      onChange={(e) => setNewPatient(prev => ({ ...prev, dateOfBirth: e.target.value }))}
                    />
                  </div>
                  
                  <div>
                    <Label htmlFor="patient-id">Patient ID *</Label>
                    <Input 
                      id="patient-id"
                      value={newPatient.patientId}
                      onChange={(e) => setNewPatient(prev => ({ ...prev, patientId: e.target.value }))}
                      placeholder="Enter patient ID"
                    />
                  </div>
                  
                  <div className="flex gap-2 pt-4">
                    <Button 
                      onClick={handleNewPatient}
                      disabled={!newPatient.name || !newPatient.dateOfBirth || !newPatient.patientId}
                      className="flex-1"
                    >
                      Create Patient
                    </Button>
                    <Button 
                      variant="outline" 
                      onClick={() => setIsNewPatientOpen(false)}
                      className="flex-1"
                    >
                      Cancel
                    </Button>
                  </div>
                </div>
              </DialogContent>
            </Dialog>
          </div>
        </CardHeader>
        <CardContent>
          <div className="relative">
            <Search className="absolute left-3 top-1/2 transform -translate-y-1/2 h-4 w-4 text-muted-foreground" />
            <Input
              placeholder="Search patients by name or ID..."
              value={searchTerm}
              onChange={(e) => setSearchTerm(e.target.value)}
              className="pl-9"
            />
          </div>
        </CardContent>
      </Card>

      {/* Current Patient (if selected) */}
      {selectedPatient && (
        <div className="space-y-4">
          <div className="flex items-center justify-between">
            <h3 className="text-lg font-medium">Current Patient</h3>
            <Badge variant="default">Active Session</Badge>
          </div>
          <Card className="w-full">
            <CardContent className="p-4">
              <div className="flex items-center justify-between">
                <div>
                  <h4 className="font-medium text-lg">{selectedPatient.name}</h4>
                  <p className="text-sm text-muted-foreground">
                    DOB: {new Date(selectedPatient.dateOfBirth).toLocaleDateString()}
                  </p>
                </div>
                <Badge variant="outline">
                  ID: {selectedPatient.patientId}
                </Badge>
              </div>
            </CardContent>
          </Card>
        </div>
      )}

      {/* Patient List */}
      <Card>
        <CardHeader className="pb-3">
          <CardTitle>Available Patients ({filteredPatients.length})</CardTitle>
        </CardHeader>
        <CardContent className="space-y-4">
          {filteredPatients.length === 0 ? (
            <div className="text-center py-8 text-muted-foreground">
              <User className="h-12 w-12 mx-auto mb-4 opacity-50" />
              <p>No patients found matching your search</p>
            </div>
          ) : (
            filteredPatients.map((patient) => (
              <div 
                key={patient.id} 
                className={`border rounded-lg p-4 cursor-pointer transition-colors hover:bg-muted/50 ${
                  selectedPatient?.id === patient.id ? 'bg-muted border-primary' : ''
                }`}
                onClick={() => onPatientSelect(patient)}
              >
                <div className="space-y-3">
                  <div className="flex items-center justify-between">
                    <div className="space-y-1">
                      <h4 className="font-medium">{patient.name}</h4>
                      <div className="flex items-center gap-4 text-sm text-muted-foreground">
                        <div className="flex items-center gap-1">
                          <Calendar className="h-4 w-4" />
                          <span>DOB: {new Date(patient.dateOfBirth).toLocaleDateString()}</span>
                        </div>
                        <div className="flex items-center gap-1">
                          <Hash className="h-4 w-4" />
                          <span>ID: {patient.patientId}</span>
                        </div>
                      </div>
                    </div>

                  </div>
                </div>
              </div>
            ))
          )}
        </CardContent>
      </Card>
    </div>
  );
}