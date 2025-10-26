import { useState, useEffect } from "react";
import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Button } from "./ui/button";
import { Badge } from "./ui/badge";
import { Dialog, DialogContent, DialogDescription, DialogHeader, DialogTitle, DialogTrigger } from "./ui/dialog";
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from "./ui/table";
import { Checkbox } from "./ui/checkbox";
import { Input } from "./ui/input";
import { Label } from "./ui/label";
import { ScrollArea } from "./ui/scroll-area";
import { FileText, Printer, Download, Eye, Calendar, Building, User, Edit, RefreshCw } from "lucide-react";

interface Report {
    id: string;
    name: string;
    description: string;
    type: 'diagnostic' | 'parameter' | 'status' ;
    lastGenerated?: string;
    isAvailable: boolean;
}

const availableReports: Report[] = [
    { id: 'bradycardia', name: 'Bradycardia Report', description: 'Saved bradycardia report and parameters', type: 'parameter', isAvailable: true },
    { id: 'temporary', name: 'Temporary Parameters', description: 'Current session parameter changes', type: 'parameter', isAvailable: true },
    { id: 'implant', name: 'Implant Data Report', description: 'Device specifications and implant information', type: 'status', isAvailable: true },
    { id: 'threshold', name: 'Threshold Test Report', description: 'Saved threshold test results', type: 'diagnostic', isAvailable: true },
    { id: 'measured', name: 'Measured Data Report', description: 'Lead impedance and sensor data', type: 'diagnostic', isAvailable: true },
    { id: 'markers', name: 'Marker Legend', description: 'EGM event markers', type: 'status', isAvailable: true },
    { id: 'session', name: 'Session Net Change', description: 'Summary of parameter modifications', type: 'status', isAvailable: true },
    { id: 'final', name: 'Final Report', description: 'Complete session summary', type: 'status', isAvailable: true },
    { id: 'histogram', name: 'Histogram Report', description: 'Rate histogram data', type: 'diagnostic', isAvailable: true },
    { id: 'trending', name: 'Trending Report', description: 'Trends report and data', type: 'diagnostic', isAvailable: true }
];

const reportTypeColors: Record<Report['type'], string> = {
    diagnostic: 'bg-blue-100 text-blue-800 dark:bg-blue-900 dark:text-blue-300',
    parameter: 'bg-green-100 text-green-800 dark:bg-green-900 dark:text-green-300',
    status: 'bg-orange-100 text-orange-800 dark:bg-orange-900 dark:text-orange-300',
    // trending: 'bg-purple-100 text-purple-800 dark:bg-purple-900 dark:text-purple-300'
};

export function ReportsPanel({ selectedPatient }: { selectedPatient?: any }) {
    const [selectedReports, setSelectedReports] = useState<string[]>([]);
    const [previewReport, setPreviewReport] = useState<Report | null>(null);
    const [isEditingHeader, setIsEditingHeader] = useState(false);
    const [headerInfo, setHeaderInfo] = useState({
        institution: 'McMaster University',
        group: '3K04 Group 3',
        sessionDate: new Date().toLocaleString(),
        dcmInfo: 'Placeholder',
    });
    const [patientHistory, setPatientHistory] = useState<any[]>([]);
    const [isRefreshing, setIsRefreshing] = useState(false);
    const [lastRefreshedAt, setLastRefreshedAt] = useState<string | null>(null);

    const toggleReportSelection = (reportId: string) => {
        setSelectedReports(prev => prev.includes(reportId) ? prev.filter(id => id !== reportId) : [...prev, reportId]);
    };

    // Get history for a patient (persists from ParametersTable saves)
    const loadPatientHistory = (id: string) => {
        try {
            const raw = localStorage.getItem('pacemakerParameters');
            if (!raw) { 
                console.log('no pacemakerParameters found in localStorage');
                setPatientHistory([]); 
                return; 
            }
            const parsed = JSON.parse(raw || '{}');
            const hist = parsed[id] || [];
            console.log('Loading patient history for ID:', id);
            console.log('History entries found:', hist.length);
            console.log('History data:', hist);
            setPatientHistory(hist);
        } catch (e) {
            console.error('Error reading patient history', e);
            setPatientHistory([]);
        }
    };

    const getLatestForPatient = () => {
        // Prefer in-memory history if available
        if (patientHistory.length > 0) {
            const latest = patientHistory[patientHistory.length - 1];
            return { timestamp: latest.timestamp as string | undefined, values: latest.values };
        }
        // Fallback: read directly from localStorage using current patient id
        try {
            const id = selectedPatient?.id;
            if (!id) return { timestamp: undefined as string | undefined, values: undefined as any };
            const raw = localStorage.getItem('pacemakerParameters');
            if (!raw) return { timestamp: undefined as string | undefined, values: undefined as any };
            const parsed = JSON.parse(raw || '{}');
            const hist = parsed[id] || [];
            if (!hist.length) return { timestamp: undefined as string | undefined, values: undefined as any };
            const latest = hist[hist.length - 1];
            return { timestamp: latest.timestamp as string | undefined, values: latest.values };
        } catch {
            return { timestamp: undefined as string | undefined, values: undefined as any };
        }
    };

    const handleRefreshParameters = () => {
        const id = selectedPatient?.id;
        console.log('Refresh clicked - Patient ID:', id);
        if (!id) {
            console.log('No patient ID available');
            return;
        }
        setIsRefreshing(true);
        try {
            loadPatientHistory(id);
            setLastRefreshedAt(new Date().toLocaleTimeString());
            console.log('Refresh completed');
        } finally {
            setIsRefreshing(false);
        }
    };

    const handlePrintSelected = () => {
        // Simple print: open new window with concatenated report content
        const { values, timestamp } = getLatestForPatient();
        const win = window.open('', '_blank');
        if (!win) return;
        const content = selectedReports.map(id => {
            const r = availableReports.find(ar => ar.id === id)!;
            return generateReportContent(r, {
                institution: headerInfo.institution,
                instution: headerInfo.institution,
                date: timestamp || new Date().toISOString(),
                deviceInfo: '',
                dcmInfo: headerInfo.dcmInfo,
                parameters: values,
                patientId: selectedPatient?.id,
            });
        }).join('\n\n---\n\n');
        win.document.write(`<pre>${content.replace(/</g, '&lt;')}</pre>`);
        win.document.close();
        win.focus();
        win.print();
    };

    const handleExportSelected = () => {
        const { values, timestamp } = getLatestForPatient();
        selectedReports.forEach(id => {
            const r = availableReports.find(ar => ar.id === id)!;
            outputReport(r, {
                institution: headerInfo.institution,
                instution: headerInfo.institution,
                date: timestamp || new Date().toISOString(),
                deviceInfo: '',
                dcmInfo: headerInfo.dcmInfo,
                parameters: values,
                patientId: selectedPatient?.id,
            });
        });
    };

    // Load history when selected patient changes
    useEffect(() => {
        const id = selectedPatient?.id;
        if (id) loadPatientHistory(id); else setPatientHistory([]);
    }, [selectedPatient]);

    const latestTimestamp = getLatestForPatient().timestamp;

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
                                onClick={handleRefreshParameters}
                                variant="outline"
                                className="flex items-center gap-2"
                                disabled={isRefreshing || !selectedPatient?.id}
                                title="Reload latest parameters from local storage"
                            >
                                <RefreshCw className={`h-4 w-4 ${isRefreshing ? 'animate-spin' : ''}`} />
                                Refresh
                            </Button>
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
                                        <TableCell>
                                            <div className="flex items-center gap-2">
                                                <Dialog open={previewReport?.id === report.id} onOpenChange={(open: boolean) => { if (!open) setPreviewReport(null); }}>
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
                                                        </DialogHeader>
                                                        <ScrollArea className="h-96">
                                                            <pre className="text-xs font-mono whitespace-pre-line bg-muted/50 p-4 rounded">
                                                                {generateReportContent(report, {
                                                                    institution: headerInfo.institution,
                                                                    instution: headerInfo.institution,
                                                                    date: latestTimestamp || new Date().toISOString(),
                                                                    deviceInfo: '',
                                                                    dcmInfo: headerInfo.dcmInfo,
                                                                    parameters: getLatestForPatient().values,
                                                                    patientId: selectedPatient?.id,
                                                                })}
                                                            </pre>
                                                        </ScrollArea>
                                                        <div className="flex justify-end gap-2 pt-4 border-t">
                                                            <Button variant="outline" className="flex items-center gap-2" onClick={handleRefreshParameters} disabled={isRefreshing || !selectedPatient?.id}>
                                                                <RefreshCw className={`h-4 w-4 ${isRefreshing ? 'animate-spin' : ''}`} />
                                                                Refresh
                                                            </Button>
                                                            <Button variant="outline" className="flex items-center gap-2" onClick={handlePrintSelected}>
                                                                <Printer className="h-4 w-4" />
                                                                Print
                                                            </Button>
                                                            <Button className="flex items-center gap-2" onClick={() => outputReport(report, {
                                                                institution: headerInfo.institution,
                                                                instution: headerInfo.institution,
                                                                date: latestTimestamp || new Date().toISOString(),
                                                                deviceInfo: '',
                                                                dcmInfo: headerInfo.dcmInfo,
                                                                parameters: getLatestForPatient().values,
                                                                patientId: selectedPatient?.id,
                                                            })}>
                                                                <Download className="h-4 w-4" />
                                                                Export PDF
                                                            </Button>
                                                        </div>
                                                    </DialogContent>
                                                </Dialog>
                                                <Button 
                                                    variant="outline" 
                                                    size="sm"
                                                    onClick={() => outputReport(report, {
                                                        institution: headerInfo.institution,
                                                        instution: headerInfo.institution,
                                                        date: latestTimestamp || new Date().toISOString(),
                                                        deviceInfo: '',
                                                        dcmInfo: headerInfo.dcmInfo,
                                                        parameters: getLatestForPatient().values,
                                                        patientId: selectedPatient?.id,
                                                    })}
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
                                            value={headerInfo.group}
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
                                <Button onClick={() => setIsEditingHeader(false)} className="flex-1">Save Changes</Button>
                                <Button variant="outline" onClick={() => setIsEditingHeader(false)} className="flex-1">Cancel</Button>
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
                                        <p className="font-medium">Group</p>
                                        <p className="text-sm text-muted-foreground">{headerInfo.group}</p>
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
};

function generateReportContent(report: Report | null, headerInfo: any): string {
    if (!report) return '';
    switch (report.id) {
        
        // bradycardia parameters report
        case 'bradycardia': case 'temporary': {
            // Try to get parameters from headerInfo first, then fall back to persisted 'pacemakerParameters' for the given patient, then other common keys.
            let params: any = headerInfo.parameters ?? headerInfo.savedParameters;
            // Fallback 1: canonical app storage (with patient scoping)
            if (!params && headerInfo.patientId) {
                try {
                    const rawPP = localStorage.getItem('pacemakerParameters');
                    if (rawPP) {
                        const parsed = JSON.parse(rawPP || '{}');
                        const hist = parsed[headerInfo.patientId] || [];
                        if (hist.length) params = hist[hist.length - 1].values;
                    }
                } catch {}
            }
            // Fallback 2: legacy/common keys
            if (!params) {
                try {
                    const raw =
                        localStorage.getItem('dcm_parameters') ??
                        localStorage.getItem('savedParameters') ??
                        localStorage.getItem('parameters');
                    if (raw) params = JSON.parse(raw);
                } catch {
                    params = undefined;
                }
            }

                        // Normalize parameters into a readable list with friendly names and units
                        const labelMap: Record<string, string> = {
                            lowerRateLimit: 'Lower Rate Limit',
                            upperRateLimit: 'Upper Rate Limit',
                            maximumSensorRate: 'Maximum Sensor Rate',
                            fixedAVDelay: 'Fixed AV Delay',
                            dynamicAVDelay: 'Dynamic AV Delay',
                            minimumDynamicAVDelay: 'Minimum Dynamic AV Delay',
                            sensedAVDelayOffset: 'Sensed AV Delay Offset',
                            atrialAmplitudeRegulated: 'Atrial Amplitude (Regulated)',
                            ventricularAmplitudeRegulated: 'Ventricular Amplitude (Regulated)',
                            atrialAmplitudeUnregulated: 'Atrial Amplitude (Unregulated)',
                            ventricularAmplitudeUnregulated: 'Ventricular Amplitude (Unregulated)',
                            atrialPulseWidth: 'Atrial Pulse Width',
                            ventricularPulseWidth: 'Ventricular Pulse Width',
                            atrialSensitivity: 'Atrial Sensitivity',
                            ventricularSensitivity: 'Ventricular Sensitivity',
                            ventricularRefractoryPeriod: 'Ventricular Refractory Period',
                            atrialRefractoryPeriod: 'Atrial Refractory Period',
                            pvarp: 'PVARP',
                            pvarpExtension: 'PVARP Extension',
                            hysteresisRateLimit: 'Hysteresis Rate Limit',
                            rateSmoothing: 'Rate Smoothing',
                            atrMode: 'ATR Mode',
                            atrDuration: 'ATR Duration',
                            atrFallbackTime: 'ATR Fallback Time',
                            ventricularBlanking: 'Ventricular Blanking',
                            activityThreshold: 'Activity Threshold',
                            reactionTime: 'Reaction Time',
                            responseFactor: 'Response Factor',
                            recoveryTime: 'Recovery Time',
                        };

                        const unitMap: Record<string, string> = {
                            lowerRateLimit: 'ppm',
                            upperRateLimit: 'ppm',
                            maximumSensorRate: 'ppm',
                            fixedAVDelay: 'ms',
                            minimumDynamicAVDelay: 'ms',
                            sensedAVDelayOffset: 'ms',
                            atrialAmplitudeRegulated: 'V',
                            ventricularAmplitudeRegulated: 'V',
                            atrialAmplitudeUnregulated: 'V',
                            ventricularAmplitudeUnregulated: 'V',
                            atrialPulseWidth: 'ms',
                            ventricularPulseWidth: 'ms',
                            atrialSensitivity: 'mV',
                            ventricularSensitivity: 'mV',
                            ventricularRefractoryPeriod: 'ms',
                            atrialRefractoryPeriod: 'ms',
                            pvarp: 'ms',
                            pvarpExtension: 'ms',
                            hysteresisRateLimit: 'ppm',
                            ventricularBlanking: 'ms',
                            reactionTime: 'sec',
                            recoveryTime: 'min',
                        };

                        const toLabel = (key: string) => labelMap[key] || key
                            .replace(/([a-z])([A-Z])/g, '$1 $2')
                            .replace(/^./, (c) => c.toUpperCase());

                        let paramsText = '';
                        if (Array.isArray(params)) {
                            paramsText = params
                                .map((p, i) => {
                                    if (p && typeof p === 'object') {
                                        const rawKey = (p.name ?? p.parameter ?? p.param ?? `param_${i + 1}`) as string;
                                        const value = p.value ?? p.val ?? JSON.stringify(p);
                                        const label = toLabel(rawKey);
                                        const unit = unitMap[rawKey] ? ` ${unitMap[rawKey]}` : '';
                                        return `${label}: ${value}${unit}`;
                                    }
                                    return String(p);
                                })
                                .join('\n');
                        } else if (params && typeof params === 'object') {
                            paramsText = Object.entries(params)
                                .map(([k, v]) => {
                                    const label = toLabel(k);
                                    const unit = unitMap[k] ? ` ${unitMap[k]}` : '';
                                    return `${label}: ${v}${unit}`;
                                })
                                .join('\n');
                        } else {
                            paramsText = '[No saved parameters found]';
                        }

            const institution = headerInfo.institution ?? headerInfo.instution ?? '';

            return `
    DEVICE CONTROLLER-MONITOR REPORT
    ${report.name.toUpperCase()}

    Institution: ${institution}
    Date/Time: ${headerInfo.date}
    Device Info: ${headerInfo.deviceInfo}
    DCM Info: ${headerInfo.dcmInfo}

    Saved parameters:
    ${paramsText}
            `.trim();
        }

        // implant data report
        case 'implant':
            return `
IMPLANT DATA REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
DCM Info: ${headerInfo.dcmInfo}

Device Model:
Serial Number:
Implant Name:
            `.trim();

        // threshold data report
        case 'threshold':
            return `
THRESHOLD TEST REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
DCM Info: ${headerInfo.dcmInfo}
            `.trim();

        // measured data report    
        case 'measured':
            return `
MEASURED DATA REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
DCM Info: ${headerInfo.dcmInfo}
            `.trim();

        // marker legend report
        case 'markers':
            return `
MARKER LEGEND
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
DCM Info: ${headerInfo.dcmInfo}
            `.trim();

        // session net change report
        case 'session':
            return `
SESSION NET CHANGE REPORT

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
DCM Info: ${headerInfo.dcmInfo}
            `.trim();

        // final report
        case 'final':
            return `
FINAL REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
DCM Info: ${headerInfo.dcmInfo}
            `.trim();

        // histogram report    
        case 'histogram':
            return `
HISTOGRAM REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
DCM Info: ${headerInfo.dcmInfo}
            `.trim();

        // trending report    
        case 'trending':
            return `
TRENDING REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
DCM Info: ${headerInfo.dcmInfo}
            `.trim();
        default:
            return 'No report data available.';
    }
}


function outputReport(report: Report | null, headerInfo: any) {
    if (!report) return;
    const content = generateReportContent(report, headerInfo);
    const blob = new Blob([content], { type: 'text/plain' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = `${report.name.replace(/\s+/g, '_')}.txt`;
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
};


