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
import { FileText, Printer, Download, Eye, Calendar, Building, User, Edit } from "lucide-react";

interface Report {
    id: string;
    name: string;
    description: string;
    type: 'parameter' | 'status' | 'diagnostic';
}

const avaliableReports: Report[] = [
    { id: 'bradycardia', name: 'Bradycardia Parameter Report', description: 'Comprehensive pacing data and statistics', type: 'parameter'},
    { id: 'temporary', name: 'Temporary Parameters', description: 'Current session parameter changes', type: 'parameter'},
    { id: 'implant', name: 'Implant Data Report', description: 'Device specifications and implant information', type: 'status'},
    { id: 'threshold', name: 'Threshold Test Report', description: 'Capture threshold test results', type: 'parameter'},
    { id: 'measured', name: 'Measured Data Report', description: 'Lead impedance and sensor data', type: 'status'},
    { id: 'markers', name: 'Marker Legend', description: 'EGM event marker reference', type: 'status'},
    { id: 'session', name: 'Session Net Change', description: 'Summary of parameter modifications', type: 'status'},
    { id: 'final', name: 'Final Report', description: 'Complete session summary', type: 'status'},
    { id: 'histogram', name: 'Histogram Report', description: 'Rate histogram data and analysis', type: 'diagnostic'},
    { id: 'trending', name: 'Trending Report', description: 'Long-term rate and activity trends', type: 'diagnostic'}
];

const reportTypeColors = {
    diagnostic: 'bg-blue-100 text-blue-800 dark:bg-blue-900 dark:text-blue-300',
    parameter: 'bg-green-100 text-green-800 dark:bg-green-900 dark:text-green-300',
    status: 'bg-orange-100 text-orange-800 dark:bg-orange-900 dark:text-orange-300',
};

export function ReportsPanel({ selectedPatient }: { selectedPatient?: any }) {
    const [selectedReports, setSelectedReports] = useState<string[]>([]);
    const [previewReport, setPreviewReport] = useState<Report | null>(null);
    const [isEditingHeader, setIsEditingHeader] = useState(false);
    const [headerInfo, setHeaderInfo] = useState({
        instution: 'McMaster University Hospital',
        date: 'date',
        deviceInfo: 'info placeholder',
        dcmInfo: 'info placeholder',
    });
    const [patientHistory, setPatientHistory] = useState<any[]>([]);

    const toggleReportSelection = (reportId: string) => {
        setSelectedReports(prev => 
            prev.includes(reportId) ? prev.filter(id => id !== reportId) : [...prev, reportId]
        );
    };      
    
    // Get history for a patient
    const loadPatientHistory = (id: string) => {
        try {
            const raw = localStorage.getItem('pacemakerParameters');
            if (!raw) {
                setPatientHistory([]);
                return;
            }
            const parsed = JSON.parse(raw || '{}');
            const hist = parsed[id] || [];
            setPatientHistory(hist);
        } catch (e) {
            console.error('Error reading patient history', e);
            setPatientHistory([]);
        }
    };

    // Preview helper: pass headerInfo with savedParameters if available
    const handlePreview = (report: Report) => {
        setPreviewReport(report);
    };

    // Download latest parameters for current selected patient
    const downloadLatestForCurrentPatient = () => {
        try {
            const id = selectedPatient?.id;
            if (!id) return;
            const raw = localStorage.getItem('pacemakerParameters');
            if (!raw) return;
            const parsed = JSON.parse(raw || '{}');
            const hist = parsed[id] || [];
            if (!hist.length) return;
            const latest = hist[hist.length - 1];
            const blob = new Blob([JSON.stringify(latest, null, 2)], { type: 'application/json' });
            const url = URL.createObjectURL(blob);
            const a = document.createElement('a');
            a.href = url;
            a.download = `${id}_latest_parameters.json`;
            document.body.appendChild(a);
            a.click();
            document.body.removeChild(a);
            URL.revokeObjectURL(url);
        } catch (e) {
            console.error('Error downloading latest parameters', e);
        }
    };

    // load history when selected patient changes
    useEffect(() => {
        const id = selectedPatient?.id;
        if (id) loadPatientHistory(id);
        else setPatientHistory([]);
    }, [selectedPatient]);

    return (
        <div className="space-y-6">
            <div className="grid grid-cols-1 md:grid-cols-3 gap-6">
                <Card>
                    <CardHeader>
                        <CardTitle>Available Reports</CardTitle>
                    </CardHeader>
                    <CardContent>
                        <div className="space-y-2">
                            {avaliableReports.map(r => (
                                <div key={r.id} className="flex items-center justify-between">
                                    <div className="flex items-center gap-2">
                                        <Checkbox checked={selectedReports.includes(r.id)} onCheckedChange={() => toggleReportSelection(r.id)} />
                                        <div>
                                            <div className="font-medium">{r.name}</div>
                                            <div className="text-xs text-gray-500">{r.description}</div>
                                        </div>
                                    </div>
                                    <Badge className={reportTypeColors[r.type]}>{r.type}</Badge>
                                </div>
                            ))}
                        </div>
                    </CardContent>
                </Card>

                <Card>
                    <CardHeader>
                        <CardTitle>Current Patient</CardTitle>
                    </CardHeader>
                    <CardContent>
                        <div className="space-y-2">
                            <div className="text-sm">Patient ID</div>
                            <div className="font-medium">{selectedPatient?.id ?? 'No patient selected'}</div>
                            <div className="flex gap-2 mt-2">
                                <Button onClick={() => { if (selectedPatient?.id) loadPatientHistory(selectedPatient.id); }}>Load History</Button>
                                <Button onClick={() => { downloadLatestForCurrentPatient(); }} disabled={!selectedPatient?.id}>Download Latest</Button>
                            </div>
                            <div className="mt-3">
                                <Label>Note</Label>
                                <div className="text-sm text-gray-500">Reports will use the currently logged-in patient's saved parameters.</div>
                            </div>
                        </div>
                    </CardContent>
                </Card>

                <Card>
                    <CardHeader>
                        <CardTitle>History / Actions</CardTitle>
                    </CardHeader>
                    <CardContent>
                        <div className="space-y-2">
                            <div className="text-sm">Loaded history entries: {patientHistory.length}</div>
                            <ScrollArea className="h-48">
                                <div className="space-y-2">
                                    {patientHistory.length === 0 && <div className="text-sm text-gray-500">No history loaded</div>}
                                    {patientHistory.map((entry, idx) => (
                                        <div key={idx} className="p-2 border rounded">
                                            <div className="text-xs text-gray-600">{entry.timestamp} — mode: {entry.mode}</div>
                                            <div className="text-sm">{Object.keys(entry.values || {}).length} parameters</div>
                                            <div className="mt-2 flex gap-2">
                                                <Button size="sm" onClick={() => { setPreviewReport({ id: 'temporary', name: 'Temporary Parameters', description: '', type: 'parameter' }); }}>Preview</Button>
                                                <Button size="sm" variant="outline" onClick={() => {
                                                    const blob = new Blob([JSON.stringify(entry, null, 2)], { type: 'application/json' });
                                                    const url = URL.createObjectURL(blob);
                                                    const a = document.createElement('a');
                                                    a.href = url;
                                                    a.download = `${selectedPatient?.id || 'patient'}_history_${idx + 1}.json`;
                                                    document.body.appendChild(a);
                                                    a.click();
                                                    document.body.removeChild(a);
                                                    URL.revokeObjectURL(url);
                                                }}>Export</Button>
                                            </div>
                                        </div>
                                    ))}
                                </div>
                            </ScrollArea>
                        </div>
                    </CardContent>
                </Card>
            </div>

            {/* Preview / Actions footer */}
            <div className="flex gap-2">
                <Button onClick={() => { if (selectedReports.length === 1) handlePreview(avaliableReports.find(r => r.id === selectedReports[0])!); else if (selectedReports.length > 1) handlePreview(avaliableReports.find(r => r.id === selectedReports[0])!); }}>Preview Selected</Button>
                <Button onClick={() => { if (previewReport) outputReport(previewReport, { ...headerInfo, date: new Date().toISOString(), parameters: patientHistory.length > 0 ? patientHistory[patientHistory.length - 1].values : undefined, institution: headerInfo.instution, patientId: selectedPatient?.id }); }}>Download Preview</Button>
            </div>

            {/* Preview Dialog */}
            <Dialog open={!!previewReport} onOpenChange={(open: boolean) => { if (!open) setPreviewReport(null); }}>
                <DialogContent>
                    <DialogHeader>
                        <DialogTitle>{previewReport?.name}</DialogTitle>
                        <DialogDescription>
                                <pre className="whitespace-pre-wrap">{generateReportContent(previewReport, { ...headerInfo, date: new Date().toISOString(), parameters: patientHistory.length > 0 ? patientHistory[patientHistory.length - 1].values : undefined, institution: headerInfo.instution, patientId: selectedPatient?.id })}</pre>
                        </DialogDescription>
                    </DialogHeader>
                </DialogContent>
            </Dialog>
        </div>
    );
};

function generateReportContent(report: Report | null, headerInfo: any): string {
    if (!report) return '';
    switch (report.id) {
        
        // bradycardia parameters report
        case 'bradycardia': case 'temporary': {
            // Try to get parameters from headerInfo first, then fall back to common localStorage keys.
            let params: any = headerInfo.parameters ?? headerInfo.savedParameters;
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

            // Normalize parameters into a readable list
            let paramsText = '';
            if (Array.isArray(params)) {
            paramsText = params
                .map((p, i) => {
                if (p && typeof p === 'object') {
                    // common shapes: { name, value } or { parameter, value }
                    const name = p.name ?? p.parameter ?? p.param ?? `param_${i + 1}`;
                    const value = p.value ?? p.val ?? JSON.stringify(p);
                    return `- ${name}: ${value}`;
                }
                return `- ${String(p)}`;
                })
                .join('\n');
            } else if (params && typeof params === 'object') {
            paramsText = Object.entries(params)
                .map(([k, v]) => `- ${k}: ${v}`)
                .join('\n');
            } else {
            paramsText = '- [No saved parameters found]';
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


