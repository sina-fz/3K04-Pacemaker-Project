import { useState } from "react";
import { Button } from "./ui/button";
import { Input } from "./ui/input";
import { Card, CardContent, CardHeader, CardTitle, CardDescription } from "./ui/card";
import { Label } from "./ui/label";
import { Alert, AlertDescription } from "./ui/alert";
import { Heart, AlertCircle, CheckCircle, ArrowLeft } from "lucide-react";  

interface Parameter{
    id: string;
    name: string;
    value: number; // always numeric now
    unit: string;
    type: 'select' | 'number' | 'text';
    options?: number[]; // numeric options
    min?: number;
    max?: number;
    step?: number | 'custom';
    isDirty?: boolean;
    isValid?: boolean;
    range?: string;
    allowOff?: boolean; // when true, 0 represents Off
}

interface ParametersTableProps {
    selectedPatient: any;
    onParameterSaved: (parameter: any) => void;
}

// right side select mode button
function ModeButton({ mode, isSelected, onClick }: { mode: string; isSelected: boolean; onClick: () => void }) {
    return (
        <Button
            variant={isSelected ? "default" : "outline"}
            size="sm"
            onClick={onClick}
            className={`min-w-[80px] ${isSelected ? 'bg-blue-600 hover:bg-blue-700' : ''}`}
        >
            {mode}
        </Button>
    );
}

// helper functions for step values
const getLowerRateLimitStep = (value: number) => {
    if (value >= 30 && value < 50) return 5;
    if (value >= 50 && value < 90) return 1;
    if (value >= 90 && value <= 175) return 5;
};

export function ParametersTable({ selectedPatient, onParameterSaved }: ParametersTableProps) {
    const [selectedMode, setSelectedMode] = useState('DDD'); // nominal mode
    const [hasChanges, setHasChanges] = useState(false);

    // parameters state
    const getInitialParameters = (): Parameter[] => {
        const patientParams = selectedPatient?.parameters || [];
        // helper: coerce incoming values (strings like 'Off', '3%', etc.) to numbers
        const toNumber = (v: any, fallback: number) => {
            if (v === undefined || v === null) return fallback;
            if (typeof v === 'number') return v;
            if (typeof v === 'string') {
                const s = v.trim();
                if (s.toLowerCase() === 'off') return 0;
                if (s.toLowerCase() === 'on') return 1;
                if (s.endsWith('%')) return Number(s.slice(0, -1));
                // handle empty string
                if (s === '') return fallback;
                const n = Number(s);
                return Number.isNaN(n) ? fallback : n;
            }
            const n = Number(v);
            return Number.isNaN(n) ? fallback : n;
        };

        // helper: convert an array of option strings/numbers to numbers
        const optionsToNumbers = (opts: Array<string | number> | undefined) => {
            if (!opts) return undefined;
            return opts.map((o) => toNumber(o, 0));
        };

        // mapping for activityThreshold labels -> numeric codes
        const activityThresholdMap = ['V-Low', 'Low', 'Med-Low', 'Med', 'Med-High', 'High', 'V-High'];
        const mapActivity = (v: any, fallback: number) => {
            if (typeof v === 'number') return v;
            if (typeof v === 'string') {
                const idx = activityThresholdMap.indexOf(v);
                if (idx !== -1) return idx + 1; // 1..7
            }
            return fallback;
        };
        return [
            { // Lower Rate Limit
                id: 'lowerRateLimit',
                name: 'Lower Rate Limit',
                value: patientParams.lowerRateLimit || 60,  
                unit: 'ppm',
                type: 'number',
                min: 30,
                max: 175,
                step: getLowerRateLimitStep(patientParams.lowerRateLimit || 60),
                range: '30-175 ppm',
                isValid: true
            },
            { // Upper Rate Limit
                id: 'upperRateLimit',
                name: 'Upper Rate Limit',
                value: patientParams.upperRateLimit || 120,
                unit: 'ppm',
                type: 'number',
                min: 50,
                max: 175, 
                step: 5,
                range: '50-175 ppm',
                isValid: true
            },
            { // Maximum Sensor Rate
                id: 'maximumSensorRate',
                name: 'Maximum Sensor Rate',
                value: patientParams.maximumSensorRate || 120,
                unit: 'ppm',
                type: 'number',
                min: 50,
                max: 175,
                step: 5,
                range: '50-175 ppm',
                isValid: true
            },
            { // Fixed AV Delay
                id: 'fixedAVDelay',
                name: 'Fixed AV Delay',
                value: patientParams.fixedAVDelay || 150,
                unit: 'ms',
                type: 'number',
                min: 70,
                max: 300,
                step: 10,
                range: '70-300 ms',
                isValid: true
            },
            { // Dynamic AV Delay (Off=0, On=1)
                id: 'dynamicAVDelay',
                name: 'Dynamic AV Delay',
                value: toNumber(patientParams.dynamicAVDelay, 0),
                unit: '',
                type: 'select',
                options: [0, 1],
                range: 'Off (0) or On (1)',
                isValid: true,
                allowOff: true,
            },
            { // Minimum Dynamic AV Delay
                id: 'minimumDynamicAVDelay', 
                name: 'Minimum Dynamic AV Delay', 
                value: patientParams.minimumDynamicAVDelay || 50, 
                unit: 'ms',
                type: 'number', 
                min: 30, 
                max: 100,
                step: 10,
                range: '30-100 ms, 10 ms increments',
                isValid: true 
            },
            { // Sensed AV Delay Offset (numeric, Off -> 0)
                id: 'sensedAVDelayOffset',
                name: 'Sensed AV Delay Offset',
                value: toNumber(patientParams.sensedAVDelayOffset, 0),
                unit: 'ms',
                type: 'number',
                min: -100,
                max: 0,
                step: 10,
                range: 'Off (0) or -10 to -100 ms in -10 ms steps',
                isValid: true,
                allowOff: true,
                options: optionsToNumbers([0, -10, -20, -30, -40, -50, -60, -70, -80, -90, -100])
            },
            { // Atrial Amplitude Parameters (Regulated)
                id: 'atrialAmplitudeRegulated',
                name: 'Atrial Amplitude (Regulated)',
                value: toNumber(patientParams.atrialAmplitudeRegulated, 3.5),
                unit: 'V',
                type: 'select',
                options: optionsToNumbers(['Off','0.5','0.6','0.7','0.8','0.9','1.0','1.1','1.2','1.3','1.4','1.5','1.6','1.7','1.8','1.9','2.0','2.1','2.2','2.3','2.4','2.5','2.6','2.7','2.8','2.9','3.0','3.1','3.2','3.5','4.0','4.5','5.0','5.5','6.0','6.5','7.0']),
                range: 'Off, 0.5-3.2 V (0.1 V), 3.5-7.0 V (0.5 V)',
                isValid: true,
                allowOff: true
            },
            { // Ventricular Amplitude Parameters (Regulated)
                id: 'ventricularAmplitudeRegulated',
                name: 'Ventricular Amplitude (Regulated)',
                value: toNumber(patientParams.ventricularAmplitudeRegulated, 3.5),
                unit: 'V',
                type: 'select',
                options: optionsToNumbers(['Off','0.5','0.6','0.7','0.8','0.9','1.0','1.1','1.2','1.3','1.4','1.5','1.6','1.7','1.8','1.9','2.0','2.1','2.2','2.3','2.4','2.5','2.6','2.7','2.8','2.9','3.0','3.1','3.2','3.5','4.0','4.5','5.0','5.5','6.0','6.5','7.0']),
                range: 'Off, 0.5-3.2 V (0.1 V), 3.5-7.0 V (0.5 V)',
                isValid: true,
                allowOff: true
            },
            { // Atrial Amplitude Parameters (Unregulated)
                id: 'atrialAmplitudeUnregulated',
                name: 'Atrial Amplitude (Unregulated)',
                value: toNumber(patientParams.atrialAmplitudeUnregulated, 3.75),
                unit: 'V',
                type: 'select',
                options: optionsToNumbers(['Off', '1.25', '2.5', '3.75', '5.0']),
                range: 'Off, 1.25, 2.5, 3.75, 5.0 V',
                isValid: true,
                allowOff: true
            },
            { // Ventricular Amplitude Parameters (Unregulated)
                id: 'ventricularAmplitudeUnregulated',
                name: 'Ventricular Amplitude (Unregulated)',
                value: toNumber(patientParams.ventricularAmplitudeUnregulated, 3.75),
                unit: 'V',
                type: 'select',
                options: optionsToNumbers(['Off', '1.25', '2.5', '3.75', '5.0']),
                range: 'Off, 1.25, 2.5, 3.75, 5.0 V',
                isValid: true,
                allowOff: true
            },
            { // Pulse Width Parameters
                id: 'atrialPulseWidth', 
                name: 'Atrial Pulse Width', 
                value: patientParams.atrialPulseWidth || 0.2, 
                unit: 'ms',
                type: 'number', 
                min: 0.05, 
                max: 1.9,
                step: 0.1,
                range: '0.05-1.9 ms, 0.1 ms increments above 0.4 ms',
                isValid: true 
            },
            { // Pulse Width Parameters
                id: 'ventricularPulseWidth', 
                name: 'Ventricular Pulse Width', 
                value: patientParams.ventricularPulseWidth || 0.2, 
                unit: 'ms',
                type: 'number', 
                min: 0.05, 
                max: 1.9,
                step: 0.1,
                range: '0.05-1.9 ms, 0.1 ms increments above 0.4 ms',
                isValid: true 
            },
            { // Sensitivity Parameters
                id: 'atrialSensitivity',
                name: 'Atrial Sensitivity',
                value: toNumber(patientParams.atrialSensitivity, 0.75),
                unit: 'mV',
                type: 'select',
                options: optionsToNumbers(['0.25','0.5','0.75','1.0','1.5','2.0','2.5','3.0','3.5','4.0','4.5','5.0','5.5','6.0','6.5','7.0','7.5','8.0','8.5','9.0','9.5','10.0']),
                range: '0.25, 0.5, 0.75, 1.0-10 mV (0.5 mV increments)',
                isValid: true
            },
            { // Sensitivity Parameters
                id: 'ventricularSensitivity',
                name: 'Ventricular Sensitivity',
                value: toNumber(patientParams.ventricularSensitivity, 2.5),
                unit: 'mV',
                type: 'select',
                options: optionsToNumbers(['0.25','0.5','0.75','1.0','1.5','2.0','2.5','3.0','3.5','4.0','4.5','5.0','5.5','6.0','6.5','7.0','7.5','8.0','8.5','9.0','9.5','10.0']),
                range: '0.25, 0.5, 0.75, 1.0-10 mV (0.5 mV increments)',
                isValid: true
            },
            { // Refractory Period Parameters
                id: 'ventricularRefractoryPeriod', 
                name: 'Ventricular Refractory Period', 
                value: patientParams.ventricularRefractoryPeriod || 320, 
                unit: 'ms',
                type: 'number', 
                min: 150, 
                max: 500,
                step: 10,
                range: '150-500 ms, 10 ms increments',
                isValid: true 
            },
            { // Refractory Period Parameters
                id: 'atrialRefractoryPeriod', 
                name: 'Atrial Refractory Period', 
                value: patientParams.atrialRefractoryPeriod || 250, 
                unit: 'ms',
                type: 'number', 
                min: 150, 
                max: 500,
                step: 10,
                range: '150-500 ms, 10 ms increments',
                isValid: true 
            },
            { // PVARP Parameters
                id: 'pvarp', 
                name: 'PVARP', 
                value: patientParams.pvarp || 250, 
                unit: 'ms',
                type: 'number', 
                min: 150, 
                max: 500,
                step: 10,
                range: '150-500 ms, 10 ms increments',
                isValid: true 
            },
            { // PVARP Extension Parameters
                id: 'pvarpExtension',
                name: 'PVARP Extension',
                value: toNumber(patientParams.pvarpExtension, 0),
                type: 'select',
                unit: '',
                options: optionsToNumbers(['Off','50','100','150','200','250','300','350','400']),
                range: 'Off (0) or 50-400 ms in 50 ms increments',
                isValid: true,
                allowOff: true
            },
            { // Hysteresis Rate Limit
                id: 'hysteresisRateLimit',
                name: 'Hysteresis Rate Limit',
                value: toNumber(patientParams.hysteresisRateLimit, 0),
                type: 'select',
                unit: '',
                options: optionsToNumbers(['Off','30','35','40','45','50','55','60','65','70','75','80','85','90','95','100','105','110','115','120','125','130','135','140','145','150','155','160','165','170','175']),
                range: 'Off (0) or same as Lower Rate Limit',
                isValid: true,
                allowOff: true
            },
            { // Rate Smoothing
                id: 'rateSmoothing',
                name: 'Rate Smoothing',
                value: toNumber(patientParams.rateSmoothing, 0),
                type: 'select',
                unit: '',
                options: optionsToNumbers(['Off','3%','6%','9%','12%','15%','18%','21%','25%']),
                range: 'Off (0), 3-25%',
                isValid: true,
                allowOff: true
            },
            { // ATR Mode
                id: 'atrMode',
                name: 'ATR Mode',
                value: toNumber(patientParams.atrMode, 0),
                type: 'select',
                unit: '',
                options: [0,1],
                range: 'On (1) or Off (0)',
                isValid: true,
                allowOff: true
            },
            { // ATR Duration
                id: 'atrDuration',
                name: 'ATR Duration',
                value: toNumber(patientParams.atrDuration, 20),
                unit: 'cc',
                type: 'select',
                options: optionsToNumbers(['10','20','40','60','80','100','200','300','400','500','600','700','800','900','1000','1100','1200','1300','1400','1500','1600','1700','1800','1900','2000']),
                range: '10, 20-80, 100-2000 cardiac cycles',
                isValid: true
            },
            { // ATR Fallback Time
                id: 'atrFallbackTime', 
                name: 'ATR Fallback Time', 
                value: patientParams.atrFallbackTime || 1, 
                unit: 'min',
                type: 'number', 
                min: 1, 
                max: 5,
                step: 1,
                range: '1-5 min, 1 min increments',
                isValid: true 
            },
            { // Ventricular Blanking
                id: 'ventricularBlanking', 
                name: 'Ventricular Blanking', 
                value: patientParams.ventricularBlanking || 40, 
                unit: 'ms',
                type: 'number', 
                min: 30, 
                max: 60,
                step: 10,
                range: '30-60 ms, 10 ms increments',
                isValid: true 
            },
            {
                id: 'activityThreshold',
                name: 'Activity Threshold',
                value: mapActivity(patientParams.activityThreshold, 4),
                type: 'select',
                unit: '',
                options: [1,2,3,4,5,6,7],
                range: '1..7 mapping to V-Low..V-High',
                isValid: true
            },
            { 
                id: 'reactionTime', 
                name: 'Reaction Time', 
                value: patientParams.reactionTime || 30, 
                unit: 'sec',
                type: 'number', 
                min: 10, 
                max: 50,
                step: 10,
                range: '10-50 sec, 10 sec increments',
                isValid: true 
            },
            { 
                id: 'responseFactor', 
                name: 'Response Factor', 
                value: patientParams.responseFactor || 8, 
                type: 'number', 
                unit: '',
                min: 1, 
                max: 16,
                step: 1,
                range: '1-16, 1 increment',
                isValid: true 
            },
            { 
                id: 'recoveryTime', 
                name: 'Recovery Time', 
                value: patientParams.recoveryTime || 5, 
                unit: 'min',
                type: 'number', 
                min: 2, 
                max: 16,
                step: 1,
                range: '2-16 min, 1 min increments',
                isValid: true 
            }
        ];
    };

    const [parameters, setParameters] = useState<Parameter[]>(getInitialParameters());

    // Update parameters when patient changes
    useEffect(() => {}


