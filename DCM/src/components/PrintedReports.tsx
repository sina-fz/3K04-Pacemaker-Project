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
import { FileText, Printer, Download, Eye, Calendar, Building, User, Edit, RefreshCw, AlertCircle } from "lucide-react";

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

export function ReportsPanel({ selectedPatient, deviceInfo, ekgData }: { 
    selectedPatient?: any; 
    deviceInfo?: { serialNumber?: string; model?: string };
    ekgData?: { Atrial?: Array<{x: number, y: number}>, Ventricular?: Array<{x: number, y: number}> };
}) {
    const [selectedReports, setSelectedReports] = useState<string[]>([]);
    const [previewReport, setPreviewReport] = useState<Report | null>(null);
    const [isEditingHeader, setIsEditingHeader] = useState(false);
    const [capturedEkgData, setCapturedEkgData] = useState<any[]>([]);
    const [headerInfo, setHeaderInfo] = useState({
        institution: 'McMaster University',
        group: '3K04 Group 3',
        sessionDate: new Date().toLocaleString(),
        dcmInfo: 'Placeholder',
    });
    const [patientHistory, setPatientHistory] = useState<any[]>([]);
    const [isRefreshing, setIsRefreshing] = useState(false);
    const [lastRefreshedAt, setLastRefreshedAt] = useState<string | null>(null);
    const [temporaryParams, setTemporaryParams] = useState<any>(null);

    // Capture first 30 EKG data points when ekgData changes
    useEffect(() => {
        if (ekgData && (ekgData.Atrial || ekgData.Ventricular)) {
            const atrialPoints = ekgData.Atrial?.slice(0, 30) || [];
            const ventricularPoints = ekgData.Ventricular?.slice(0, 30) || [];
            
            if (atrialPoints.length > 0 || ventricularPoints.length > 0) {
                setCapturedEkgData([
                    { channel: 'Atrial', points: atrialPoints },
                    { channel: 'Ventricular', points: ventricularPoints }
                ]);
            }
        }
    }, [ekgData]);

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
                deviceInfo: deviceInfo,
                dcmInfo: headerInfo.dcmInfo,
                parameters: values,
                patientId: selectedPatient?.id,
                temporaryParams: temporaryParams,
                ekgData: capturedEkgData,
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
                deviceInfo: deviceInfo,
                dcmInfo: headerInfo.dcmInfo,
                parameters: values,
                patientId: selectedPatient?.id,
                temporaryParams: temporaryParams,
            });
        });
    };

    // Load history when selected patient changes
    useEffect(() => {
        const id = selectedPatient?.id;
        if (id) loadPatientHistory(id); else setPatientHistory([]);
    }, [selectedPatient]);

    // Listen for temporary parameter changes from sessionStorage
    useEffect(() => {
        const checkTemporaryParams = () => {
            try {
                const tempParams = sessionStorage.getItem('temporaryParameters');
                const tempParamsMeta = sessionStorage.getItem('temporaryParametersMeta');
                
                if (tempParams && tempParamsMeta) {
                    const params = JSON.parse(tempParams);
                    const meta = JSON.parse(tempParamsMeta);
                    
                    // Only show if they belong to current patient
                    if (meta.patientId === selectedPatient?.id) {
                        setTemporaryParams({
                            params,
                            meta,
                            modifiedAt: meta.modifiedAt,
                        });
                    } else {
                        setTemporaryParams(null);
                    }
                } else {
                    setTemporaryParams(null);
                }
            } catch (e) {
                console.error('Error loading temporary parameters:', e);
                setTemporaryParams(null);
            }
        };

        checkTemporaryParams();
        
        // Check periodically for updates
        const interval = setInterval(checkTemporaryParams, 1000);
        
        return () => clearInterval(interval);
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
                                                                    deviceInfo: deviceInfo,
                                                                    dcmInfo: headerInfo.dcmInfo,
                                                                    parameters: getLatestForPatient().values,
                                                                    patientId: selectedPatient?.id,
                                                                    temporaryParams: temporaryParams,
                                                                    ekgData: capturedEkgData,
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
                                                                deviceInfo: deviceInfo,
                                                                dcmInfo: headerInfo.dcmInfo,
                                                                parameters: getLatestForPatient().values,
                                                                patientId: selectedPatient?.id,
                                                                temporaryParams: temporaryParams,
                                                                ekgData: capturedEkgData,
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
                                                        deviceInfo: deviceInfo,
                                                        dcmInfo: headerInfo.dcmInfo,
                                                        parameters: getLatestForPatient().values,
                                                        patientId: selectedPatient?.id,
                                                        temporaryParams: temporaryParams,
                                                        ekgData: capturedEkgData,
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
            // For temporary report, use temporary parameters if available
            let params: any;
            let isTempReport = report.id === 'temporary';
            
            if (isTempReport && headerInfo.temporaryParams) {
                params = headerInfo.temporaryParams.params;
            } else {
                // Try to get parameters from headerInfo first, then fall back to persisted 'pacemakerParameters' for the given patient
                params = headerInfo.parameters ?? headerInfo.savedParameters;
                
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
            
            let reportHeader = '';
            if (isTempReport) {
                const tempMeta = headerInfo.temporaryParams?.meta;
                const lastModified = tempMeta?.modifiedAt ? new Date(tempMeta.modifiedAt).toLocaleString() : 'Unknown';
                
                reportHeader = `
    DEVICE CONTROLLER-MONITOR REPORT
    ${report.name.toUpperCase()}

    Institution: ${institution}
    Date/Time: ${headerInfo.date}
    Device Info: ${headerInfo.deviceInfo}
    Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}
    Last Modified: ${lastModified}

    ${params ? 'Temporary parameters (not yet saved):' : 'No temporary parameters - all changes have been saved'}
    ${paramsText}
                `.trim();
            } else {
                reportHeader = `
    DEVICE CONTROLLER-MONITOR REPORT
    ${report.name.toUpperCase()}

    Institution: ${institution}
    Date/Time: ${headerInfo.date}
    Device Info: ${headerInfo.deviceInfo}
    Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}

    Saved parameters:
    ${paramsText}
                `.trim();
            }

            return reportHeader;
        }

        // implant data report
        case 'implant': {
            const deviceModel = headerInfo.deviceInfo?.model || 'Not available';
            const serialNumber = headerInfo.deviceInfo?.serialNumber || 'Not available';
            
            return `
IMPLANT DATA REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Serial Number: ${serialNumber}

Device Information:
-------------------
Device Model: ${deviceModel}
Serial Number: ${serialNumber}
Patient ID: ${headerInfo.patientId || 'N/A'}
            `.trim();
        }

        // threshold data report
        case 'threshold': {
            let thresholdText = '';
            if (headerInfo.ekgData && headerInfo.ekgData.length > 0) {
                thresholdText = headerInfo.ekgData.map((channel: any) => {
                    if (!channel.points || channel.points.length === 0) {
                        return `\n${channel.channel} Channel: No data available`;
                    }
                    // Calculate average of first 30 points
                    const sum = channel.points.reduce((acc: number, p: any) => acc + p.y, 0);
                    const average = sum / channel.points.length;
                    return `\n${channel.channel} Channel:\n  Sample Size: ${channel.points.length} points\n  Average Threshold: ${average.toFixed(3)} mV`;
                }).join('\n');
            } else {
                thresholdText = '\nNo EKG data captured. Start EKG streaming to capture threshold data.';
            }

            return `
THRESHOLD TEST REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo?.model || 'Not available'}
Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}

Threshold Test Results:
-----------------------${thresholdText}
            `.trim();
        }

        // measured data report    
        case 'measured': {
            let ekgDataText = '';
            if (headerInfo.ekgData && headerInfo.ekgData.length > 0) {
                ekgDataText = headerInfo.ekgData.map((channel: any) => {
                    if (!channel.points || channel.points.length === 0) {
                        return `\n${channel.channel} Channel: No data`;
                    }
                    const pointsText = channel.points
                        .map((p: any, i: number) => `  Point ${i + 1}: Time=${p.x}, Value=${p.y.toFixed(3)}`)
                        .join('\n');
                    return `\n${channel.channel} Channel (${channel.points.length} points):\n${pointsText}`;
                }).join('\n');
            } else {
                ekgDataText = '\nNo EKG data captured. Start EKG streaming to capture data.';
            }

            return `
MEASURED DATA REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo?.model || 'Not available'}
Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}

EKG Data (First 30 Points):
---------------------------${ekgDataText}
            `.trim();
        }

        // marker legend report
        case 'markers':
            return `
MARKER LEGEND
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}
            `.trim();

        // session net change report
        case 'session': {
            // Get first and last parameter sets from patient history
            const id = headerInfo.patientId;
            let firstParams: any = null;
            let lastParams: any = null;
            let firstTimestamp = '';
            let lastTimestamp = '';
            
            try {
                const raw = localStorage.getItem('pacemakerParameters');
                if (raw && id) {
                    const parsed = JSON.parse(raw);
                    const hist = parsed[id] || [];
                    
                    if (hist.length > 0) {
                        firstParams = hist[0].values;
                        firstTimestamp = hist[0].timestamp;
                        lastParams = hist[hist.length - 1].values;
                        lastTimestamp = hist[hist.length - 1].timestamp;
                    }
                }
            } catch (e) {
                console.error('Error reading session history', e);
            }
            
            if (!firstParams || !lastParams) {
                return `
SESSION NET CHANGE REPORT
=========================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}

No session history available for this patient.
                `.trim();
            }
            
            // Calculate changes
            const changes: string[] = [];
            const allKeys = new Set([...Object.keys(firstParams), ...Object.keys(lastParams)]);
            
            allKeys.forEach(key => {
                const firstVal = firstParams[key];
                const lastVal = lastParams[key];
                
                if (firstVal !== lastVal) {
                    changes.push(`${key}: ${firstVal} to ${lastVal}`);
                }
            });
            
            return `
SESSION NET CHANGE REPORT
=========================

Institution: ${headerInfo.institution}
Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}
Patient ID: ${id || 'N/A'}

Session Start: ${firstTimestamp}
Session End: ${lastTimestamp}

Parameter Changes:
------------------
${changes.length > 0 ? changes.join('\n') : 'No parameter changes detected'}

Total Parameters Modified: ${changes.length}
            `.trim();
        }

        // final report - consolidated report of multiple reports
        case 'final': {
            // Generate all component reports
            const measuredReport = generateReportContent({ id: 'measured', name: 'Measured Data Report', description: '', type: 'diagnostic', isAvailable: true }, headerInfo);
            const thresholdReport = generateReportContent({ id: 'threshold', name: 'Threshold Test Report', description: '', type: 'diagnostic', isAvailable: true }, headerInfo);
            const trendingReport = generateReportContent({ id: 'trending', name: 'Trending Report', description: '', type: 'diagnostic', isAvailable: true }, headerInfo);
            const histogramReport = generateReportContent({ id: 'histogram', name: 'Histogram Report', description: '', type: 'diagnostic', isAvailable: true }, headerInfo);
            const implantReport = generateReportContent({ id: 'implant', name: 'Implant Data Report', description: '', type: 'status', isAvailable: true }, headerInfo);
            const sessionReport = generateReportContent({ id: 'session', name: 'Session Net Change', description: '', type: 'status', isAvailable: true }, headerInfo);
            
            return `
FINAL REPORT
============

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}

================================================================================

${measuredReport}

================================================================================

${thresholdReport}

================================================================================

${trendingReport}

================================================================================

${histogramReport}

================================================================================

${implantReport}

================================================================================

${sessionReport}

================================================================================
            `.trim();
        }

        // histogram report    
        case 'histogram':
            return `
HISTOGRAM REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}
            `.trim();

        // trending report    
        case 'trending':
            return `
TRENDING REPORT
===================

Institution: ${headerInfo.institution}
Date/Time: ${headerInfo.date}
Device Info: ${headerInfo.deviceInfo}
Device Serial Number: ${headerInfo.deviceInfo?.serialNumber || 'Not available'}
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


