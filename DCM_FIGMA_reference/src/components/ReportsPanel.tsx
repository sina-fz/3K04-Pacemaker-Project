import { useState } from "react";
import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Button } from "./ui/button";
import { Badge } from "./ui/badge";
import { Dialog, DialogContent, DialogDescription, DialogHeader, DialogTitle, DialogTrigger } from "./ui/dialog";
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from "./ui/table";
import { Checkbox } from "./ui/checkbox";
import { Input } from "./ui/input";
import { Label } from "./ui/label";
import { ScrollArea } from "./ui/scroll-area";
import { FileText, Printer, Download, Eye, Calendar, Building, User, Edit } from "lucide-react";

interface Report {
  id: string;
  name: string;
  description: string;
  type: 'diagnostic' | 'parameter' | 'session' | 'trending';
  lastGenerated?: string;
  isAvailable: boolean;
}

const availableReports: Report[] = [
  { id: 'bradycardia', name: 'Bradycardia Report', description: 'Comprehensive pacing data and statistics', type: 'diagnostic', lastGenerated: '2024-01-15 14:35', isAvailable: true },
  { id: 'temporary', name: 'Temporary Parameters', description: 'Current session parameter changes', type: 'parameter', isAvailable: true },
  { id: 'implant', name: 'Implant Data Report', description: 'Device specifications and implant information', type: 'diagnostic', lastGenerated: '2024-01-15 14:30', isAvailable: true },
  { id: 'threshold', name: 'Threshold Test Report', description: 'Capture threshold test results', type: 'diagnostic', lastGenerated: '2024-01-15 14:32', isAvailable: true },
  { id: 'measured', name: 'Measured Data Report', description: 'Lead impedance and sensor data', type: 'diagnostic', lastGenerated: '2024-01-15 14:36', isAvailable: true },
  { id: 'markers', name: 'Marker Legend', description: 'EGM event marker reference', type: 'session', isAvailable: true },
  { id: 'session', name: 'Session Net Change', description: 'Summary of parameter modifications', type: 'session', isAvailable: true },
  { id: 'final', name: 'Final Report', description: 'Complete session summary', type: 'session', isAvailable: true },
  { id: 'histogram', name: 'Histogram Report', description: 'Rate histogram data and analysis', type: 'trending', lastGenerated: '2024-01-15 14:40', isAvailable: true },
  { id: 'trending', name: 'Trending Report', description: 'Long-term rate and activity trends', type: 'trending', lastGenerated: '2024-01-15 14:42', isAvailable: true }
];

const reportTypeColors = {
  diagnostic: 'bg-blue-100 text-blue-800 dark:bg-blue-900 dark:text-blue-300',
  parameter: 'bg-green-100 text-green-800 dark:bg-green-900 dark:text-green-300',
  session: 'bg-orange-100 text-orange-800 dark:bg-orange-900 dark:text-orange-300',
  trending: 'bg-purple-100 text-purple-800 dark:bg-purple-900 dark:text-purple-300'
};

export function ReportsPanel() {
  const [selectedReports, setSelectedReports] = useState<string[]>([]);
  const [previewReport, setPreviewReport] = useState<Report | null>(null);
  const [isEditingHeader, setIsEditingHeader] = useState(false);
  const [headerInfo, setHeaderInfo] = useState({
    institution: 'Cardiology Associates',
    clinician: 'Dr. Sarah Johnson',
    sessionDate: 'January 15, 2024 14:35:22',
    dcmInfo: 'S/N: DCM-2024-001, v2.1.5'
  });

  const toggleReportSelection = (reportId: string) => {
    setSelectedReports(prev => 
      prev.includes(reportId) 
        ? prev.filter(id => id !== reportId)
        : [...prev, reportId]
    );
  };

  const handlePrintSelected = () => {
    console.log('Printing reports:', selectedReports);
  };

  const handleExportSelected = () => {
    console.log('Exporting reports:', selectedReports);
  };

  const mockReportContent = `
DEVICE CONTROLLER-MONITOR REPORT
${previewReport?.name.toUpperCase() || ''}

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.sessionDate}
Clinician: ${headerInfo.clinician}
Patient: John Doe (ID: 12345)

Device Information:
Model: Medtronic Advisor XL DR
Serial Number: ABC123456789
Implant Date: March 10, 2023
Last Interrogation: January 15, 2024 14:30

DCM Information:
${headerInfo.dcmInfo}

${previewReport?.type === 'diagnostic' ? `
DIAGNOSTIC RESULTS
==================
Atrial Lead:
- Impedance: 520 Ω (Normal)
- Threshold: 0.8 V @ 0.4 ms
- Sensing: 3.2 mV
- Status: Normal

Ventricular Lead:
- Impedance: 680 Ω (Normal)  
- Threshold: 1.2 V @ 0.4 ms
- Sensing: 15.8 mV
- Status: Normal

Battery Status: BOL (Beginning of Life)
Estimated Longevity: >8 years

` : previewReport?.type === 'parameter' ? `
CURRENT PARAMETERS
=================
Pacing Mode: DDD
Lower Rate Limit: 60 BPM
Upper Rate Limit: 130 BPM
AV Delay: 150 ms

Atrial Settings:
- Amplitude: 3.5 V
- Pulse Width: 0.4 ms
- Sensitivity: 0.5 mV

Ventricular Settings:
- Amplitude: 2.5 V
- Pulse Width: 0.4 ms
- Sensitivity: 2.5 mV

` : previewReport?.type === 'trending' ? `
TRENDING ANALYSIS
================
Analysis Period: 24 Hours
Total Paced Events: 1,247
Total Sensed Events: 1,395
Average Heart Rate: 72 BPM
Pacing Percentage: 47%

Rate Distribution:
60-70 BPM: 35%
71-80 BPM: 28%
81-90 BPM: 22%
Other: 15%

Activity Correlation: Moderate
Circadian Pattern: Normal

` : `
SESSION SUMMARY
==============
Session Start: January 15, 2024 14:00
Session End: January 15, 2024 14:45
Duration: 45 minutes

Parameter Changes:
- No parameters modified

Tests Performed:
- Threshold Test (Atrial): PASS
- Threshold Test (Ventricular): PASS
- Lead Impedance Test: PASS

Status: Session completed successfully
`}

Report generated by DCM v2.1.5 on ${new Date().toLocaleString()}
  `;

  return (
    <div className="space-y-6">
      <Card>
        <CardHeader className="pb-3">
          <div className="flex items-center justify-between">
            <CardTitle className="flex items-center gap-2">
              <FileText className="h-5 w-5" />
              Available Reports
            </CardTitle>
            <div className="flex items-center gap-2">
              <Button 
                onClick={handlePrintSelected}
                disabled={selectedReports.length === 0}
                className="flex items-center gap-2"
              >
                <Printer className="h-4 w-4" />
                Print Selected ({selectedReports.length})
              </Button>
              <Button 
                onClick={handleExportSelected}
                disabled={selectedReports.length === 0}
                variant="outline"
                className="flex items-center gap-2"
              >
                <Download className="h-4 w-4" />
                Export PDF
              </Button>
            </div>
          </div>
        </CardHeader>
        <CardContent>
          <div className="border rounded-lg">
            <Table>
              <TableHeader>
                <TableRow>
                  <TableHead className="w-12">Select</TableHead>
                  <TableHead>Report Name</TableHead>
                  <TableHead>Type</TableHead>
                  <TableHead>Description</TableHead>
                  <TableHead>Last Generated</TableHead>
                  <TableHead>Actions</TableHead>
                </TableRow>
              </TableHeader>
              <TableBody>
                {availableReports.map((report) => (
                  <TableRow key={report.id} className={!report.isAvailable ? "opacity-50" : ""}>
                    <TableCell>
                      <Checkbox
                        checked={selectedReports.includes(report.id)}
                        onCheckedChange={() => toggleReportSelection(report.id)}
                        disabled={!report.isAvailable}
                      />
                    </TableCell>
                    <TableCell className="font-medium">{report.name}</TableCell>
                    <TableCell>
                      <Badge 
                        variant="outline" 
                        className={reportTypeColors[report.type]}
                      >
                        {report.type}
                      </Badge>
                    </TableCell>
                    <TableCell className="text-sm text-muted-foreground">
                      {report.description}
                    </TableCell>
                    <TableCell className="font-mono text-sm">
                      {report.lastGenerated || 'Not generated'}
                    </TableCell>
                    <TableCell>
                      <div className="flex items-center gap-2">
                        <Dialog>
                          <DialogTrigger asChild>
                            <Button 
                              variant="outline" 
                              size="sm"
                              onClick={() => setPreviewReport(report)}
                              disabled={!report.isAvailable}
                            >
                              <Eye className="h-4 w-4" />
                            </Button>
                          </DialogTrigger>
                          <DialogContent className="max-w-4xl max-h-[80vh]">
                            <DialogHeader>
                              <DialogTitle>{report.name} Preview</DialogTitle>
                              <DialogDescription>
                                Preview and export your pacemaker report
                              </DialogDescription>
                            </DialogHeader>
                            <ScrollArea className="h-96">
                              <pre className="text-xs font-mono whitespace-pre-line bg-muted/50 p-4 rounded">
                                {mockReportContent}
                              </pre>
                            </ScrollArea>
                            <div className="flex justify-end gap-2 pt-4 border-t">
                              <Button variant="outline" className="flex items-center gap-2">
                                <Printer className="h-4 w-4" />
                                Print
                              </Button>
                              <Button className="flex items-center gap-2">
                                <Download className="h-4 w-4" />
                                Export PDF
                              </Button>
                            </div>
                          </DialogContent>
                        </Dialog>
                        
                        <Button 
                          variant="outline" 
                          size="sm"
                          disabled={!report.isAvailable}
                        >
                          <Printer className="h-4 w-4" />
                        </Button>
                      </div>
                    </TableCell>
                  </TableRow>
                ))}
              </TableBody>
            </Table>
          </div>
        </CardContent>
      </Card>

      {/* Report Header Configuration */}
      <Card>
        <CardHeader className="pb-3">
          <div className="flex items-center justify-between">
            <CardTitle className="flex items-center gap-2">
              <Building className="h-5 w-5" />
              Report Header Information
            </CardTitle>
            <Button
              variant="outline"
              size="sm"
              onClick={() => setIsEditingHeader(!isEditingHeader)}
              className="flex items-center gap-2"
            >
              <Edit className="h-4 w-4" />
              {isEditingHeader ? 'Cancel' : 'Edit'}
            </Button>
          </div>
        </CardHeader>
        <CardContent className="space-y-4">
          {isEditingHeader ? (
            <div className="space-y-4">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                <div className="space-y-4">
                  <div>
                    <Label htmlFor="institution">Institution</Label>
                    <Input
                      id="institution"
                      value={headerInfo.institution}
                      onChange={(e) => setHeaderInfo(prev => ({ ...prev, institution: e.target.value }))}
                      placeholder="Enter institution name"
                    />
                  </div>
                  
                  <div>
                    <Label htmlFor="clinician">Clinician</Label>
                    <Input
                      id="clinician"
                      value={headerInfo.clinician}
                      onChange={(e) => setHeaderInfo(prev => ({ ...prev, clinician: e.target.value }))}
                      placeholder="Enter clinician name"
                    />
                  </div>
                </div>
                
                <div className="space-y-4">
                  <div>
                    <Label htmlFor="sessionDate">Session Date/Time</Label>
                    <Input
                      id="sessionDate"
                      value={headerInfo.sessionDate}
                      onChange={(e) => setHeaderInfo(prev => ({ ...prev, sessionDate: e.target.value }))}
                      placeholder="Enter session date/time"
                    />
                  </div>
                  
                  <div>
                    <Label htmlFor="dcmInfo">DCM Information</Label>
                    <Input
                      id="dcmInfo"
                      value={headerInfo.dcmInfo}
                      onChange={(e) => setHeaderInfo(prev => ({ ...prev, dcmInfo: e.target.value }))}
                      placeholder="Enter DCM information"
                    />
                  </div>
                </div>
              </div>
              
              <div className="flex gap-2 pt-4 border-t">
                <Button 
                  onClick={() => setIsEditingHeader(false)}
                  className="flex-1"
                >
                  Save Changes
                </Button>
                <Button 
                  variant="outline"
                  onClick={() => setIsEditingHeader(false)}
                  className="flex-1"
                >
                  Cancel
                </Button>
              </div>
            </div>
          ) : (
            <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
              <div className="space-y-4">
                <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                  <Building className="h-5 w-5 text-muted-foreground" />
                  <div>
                    <p className="font-medium">Institution</p>
                    <p className="text-sm text-muted-foreground">{headerInfo.institution}</p>
                  </div>
                </div>
                
                <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                  <User className="h-5 w-5 text-muted-foreground" />
                  <div>
                    <p className="font-medium">Clinician</p>
                    <p className="text-sm text-muted-foreground">{headerInfo.clinician}</p>
                  </div>
                </div>
              </div>
              
              <div className="space-y-4">
                <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                  <Calendar className="h-5 w-5 text-muted-foreground" />
                  <div>
                    <p className="font-medium">Session Date/Time</p>
                    <p className="text-sm text-muted-foreground">{headerInfo.sessionDate}</p>
                  </div>
                </div>
                
                <div className="flex items-center gap-3 p-3 bg-muted/50 rounded-lg">
                  <FileText className="h-5 w-5 text-muted-foreground" />
                  <div>
                    <p className="font-medium">DCM Information</p>
                    <p className="text-sm text-muted-foreground">{headerInfo.dcmInfo}</p>
                  </div>
                </div>
              </div>
            </div>
          )}
        </CardContent>
      </Card>
    </div>
  );
}