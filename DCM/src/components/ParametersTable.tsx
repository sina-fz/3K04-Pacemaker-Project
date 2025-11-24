import { useState, useEffect, useRef, useCallback } from "react";
import { Button } from "./ui/button";
import { Input } from "./ui/input";
import {
  Card,
  CardContent,
  CardHeader,
  CardTitle,
  CardDescription,
} from "./ui/card";
import { Label } from "./ui/label";
import { Alert, AlertDescription } from "./ui/alert";
import { AlertCircle, ChevronUp, ChevronDown } from "lucide-react";
import { Badge } from "./ui/badge";

// Parameter makes one editable parameter with the following properties
interface Parameter {
  id: string;
  name: string;
  value: number;
  unit: string;
  type: "select" | "number" | "text";
  options?: number[];
  min?: number;
  max?: number;
  step?: number | "custom";
  isDirty?: boolean;
  isValid?: boolean;
  range?: string;
  allowOff?: boolean;
}

// Passes the current selected patient and a callback when a parameter is saved
interface ParametersTableProps {
  selectedPatient: any;
  onParameterSaved: (parameter: any) => void;
  onSendToPacemaker?: (parameters: any) => void;
  verificationStatus?: {
    status: "pending" | "verified" | "failed" | null;
    message: string;
  };
  isConnected?: boolean;
}

// Available modes for pacemaker
const AVAILABLE_MODES = ["AOO", "VOO", "AAI", "VVI", "AOOR", "VOOR", "AAIR", "VVIR", "DDDR"];

// Right side select mode button
function ModeButton({
  mode,
  isSelected,
  onClick,
}: {
  mode: string;
  isSelected: boolean;
  onClick: () => void;
}) {
  return (
    <Button
      variant={isSelected ? "default" : "outline"}
      size="sm"
      onClick={onClick}
      className={`min-w-[80px] ${
        isSelected ? "bg-blue-600 hover:bg-blue-700" : ""
      }`}
    >
      {mode}
    </Button>
  );
}

// helper functions for step values
const getLowerRateLimitStep = (value: number) => {
  if (value >= 30 && value < 51) return 5;
  if (value >= 51 && value < 90) return 1;
  if (value >= 90 && value <= 175) return 5;
  return 1;
};

export function ParametersTable({
  selectedPatient,
  onParameterSaved,
  onSendToPacemaker,
  verificationStatus,
  isConnected = false,
}: ParametersTableProps) {
  const [selectedMode, setSelectedMode] = useState("VOO"); // current selected pacing mode
  const [hasChanges, setHasChanges] = useState(false); // true when any parameters have been changed
  const [modeUnavailableAlert, setModeUnavailableAlert] = useState(false); // alert for unavailable mode

  // builds initial parameter state
  const getInitialParameters = (): Parameter[] => {
    const patientParams = selectedPatient?.parameters || []; // reads from parameters of selected patient

    // helper: coerce incoming values to numbers
    const toNumber = (v: any, fallback: number) => {
      if (v === undefined || v === null) return fallback;
      if (typeof v === "number") return v;
      if (typeof v === "string") {
        const s = v.trim();
        if (s.toLowerCase() === "off") return 0;
        if (s.toLowerCase() === "on") return 1;
        if (s.endsWith("%")) return Number(s.slice(0, -1));
        // handle empty string
        if (s === "") return fallback;
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
    const activityThresholdMap = [
      "V-Low",
      "Low",
      "Med-Low",
      "Med",
      "Med-High",
      "High",
      "V-High",
    ];
    const mapActivity = (v: any, fallback: number) => {
      if (typeof v === "number") return v;
      if (typeof v === "string") {
        const idx = activityThresholdMap.indexOf(v);
        if (idx !== -1) return idx + 1; // 1..7
      }
      return fallback;
    };
    return [
      {
        // Lower Rate Limit
        id: "lowerRateLimit",
        name: "Lower Rate Limit",
        value: patientParams.lowerRateLimit || 60,
        unit: "ppm",
        type: "number",
        min: 30,
        max: 175,
       
        // mark as custom so we recompute per current value
        step: "custom",
        range: "30-175 ppm",
        isValid: true,
      },
      {
        // Upper Rate Limit
        id: "upperRateLimit",
        name: "Upper Rate Limit",
        value: patientParams.upperRateLimit || 120,
        unit: "ppm",
        type: "number",
        min: 50,
        max: 175,
        step: 5,
        range: "50-175 ppm",
        isValid: true,
      },
      {
        // Maximum Sensor Rate
        id: "maximumSensorRate",
        name: "Maximum Sensor Rate",
        value: patientParams.maximumSensorRate || 120,
        unit: "ppm",
        type: "number",
        min: 50,
        max: 175,
        step: 5,
        range: "50-175 ppm",
        isValid: true,
      },
      {
        // Fixed AV Delay
        id: "fixedAVDelay",
        name: "Fixed AV Delay",
        value: patientParams.fixedAVDelay || 150,
        unit: "ms",
        type: "number",
        min: 70,
        max: 300,
        step: 10,
        range: "70-300 ms",
        isValid: true,
      },
      {
        // Dynamic AV Delay (Off=0, On=1)
        id: "dynamicAVDelay",
        name: "Dynamic AV Delay",
        value: toNumber(patientParams.dynamicAVDelay, 0),
        unit: "",
        type: "select",
        options: [0, 1],
        range: "Off (0) or On (1)",
        isValid: true,
        allowOff: true,
      },
      {
        // Minimum Dynamic AV Delay
        id: "minimumDynamicAVDelay",
        name: "Minimum Dynamic AV Delay",
        value: patientParams.minimumDynamicAVDelay || 50,
        unit: "ms",
        type: "number",
        min: 30,
        max: 100,
        step: 10,
        range: "30-100 ms",
        isValid: true,
      },
      {
        // Sensed AV Delay Offset (numeric, Off -> 0)
        id: "sensedAVDelayOffset",
        name: "Sensed AV Delay Offset",
        value: toNumber(patientParams.sensedAVDelayOffset, 0),
        unit: "ms",
        type: "number",
        min: -100,
        max: 0,
        step: 10,
        range: "Off (0) or -10--100 ms",
        isValid: true,
        allowOff: true,
        options: optionsToNumbers([
          0, -10, -20, -30, -40, -50, -60, -70, -80, -90, -100,
        ]),
      },
      {
        // Atrial Amplitude Parameters (Regulated)
        id: "atrialAmplitudeRegulated",
        name: "Atrial Amplitude (Regulated)",
        value: toNumber(patientParams.atrialAmplitudeRegulated, 3.5),
        unit: "V",
        type: "select",
        options: optionsToNumbers([
          "Off",
          "0.5",
          "0.6",
          "0.7",
          "0.8",
          "0.9",
          "1.0",
          "1.1",
          "1.2",
          "1.3",
          "1.4",
          "1.5",
          "1.6",
          "1.7",
          "1.8",
          "1.9",
          "2.0",
          "2.1",
          "2.2",
          "2.3",
          "2.4",
          "2.5",
          "2.6",
          "2.7",
          "2.8",
          "2.9",
          "3.0",
          "3.1",
          "3.2",
          "3.5",
          "4.0",
          "4.5",
          "5.0",
          "5.5",
          "6.0",
          "6.5",
          "7.0",
        ]),
        range: "Off, 0.5-7.0V",
        isValid: true,
        allowOff: true,
      },
      {
        // Ventricular Amplitude Parameters (Regulated)
        id: "ventricularAmplitudeRegulated",
        name: "Ventricular Amplitude (Regulated)",
        value: toNumber(patientParams.ventricularAmplitudeRegulated, 3.5),
        unit: "V",
        type: "select",
        options: optionsToNumbers([
          "Off",
          "0.5",
          "0.6",
          "0.7",
          "0.8",
          "0.9",
          "1.0",
          "1.1",
          "1.2",
          "1.3",
          "1.4",
          "1.5",
          "1.6",
          "1.7",
          "1.8",
          "1.9",
          "2.0",
          "2.1",
          "2.2",
          "2.3",
          "2.4",
          "2.5",
          "2.6",
          "2.7",
          "2.8",
          "2.9",
          "3.0",
          "3.1",
          "3.2",
          "3.5",
          "4.0",
          "4.5",
          "5.0",
          "5.5",
          "6.0",
          "6.5",
          "7.0",
        ]),
        range: "Off, 0.5-7.0V",
        isValid: true,
        allowOff: true,
      },
      {
        // Atrial Amplitude Parameters (Unregulated)
        id: "atrialAmplitudeUnregulated",
        name: "Atrial Amplitude (Unregulated)",
        value: toNumber(patientParams.atrialAmplitudeUnregulated, 3.75),
        unit: "V",
        type: "select",
        options: optionsToNumbers(["Off", "1.25", "2.5", "3.75", "5.0"]),
        range: "Off, 1.25, 2.5, 3.75, 5.0 V",
        isValid: true,
        allowOff: true,
      },
      {
        // Ventricular Amplitude Parameters (Unregulated)
        id: "ventricularAmplitudeUnregulated",
        name: "Ventricular Amplitude (Unregulated)",
        value: toNumber(patientParams.ventricularAmplitudeUnregulated, 3.75),
        unit: "V",
        type: "select",
        options: optionsToNumbers(["Off", "1.25", "2.5", "3.75", "5.0"]),
        range: "Off, 1.25, 2.5, 3.75, 5.0 V",
        isValid: true,
        allowOff: true,
      },
      {
        // Atrial Pulse Width Parameters
        id: "atrialPulseWidth",
        name: "Atrial Pulse Width",
        value: patientParams.atrialPulseWidth || 0.4,
        unit: "ms",
        type: "select",
        options: optionsToNumbers([
          "0.05",
          "0.1",
          "0.2",
          "0.3",
          "0.4",
          "0.5",
          "0.6",
          "0.7",
          "0.8",
          "0.9",
          "1.0",
          "1.1",
          "1.2",
          "1.3",
          "1.4",
          "1.5",
          "1.6",
          "1.7",
          "1.8",
          "1.9",
        ]),
        range: "0.05, 0.1-1.9 ms (0.1 steps)",
        isValid: true,
      },
      {
        // Ventricular Pulse Width Parameters
        id: "ventricularPulseWidth",
        name: "Ventricular Pulse Width",
        value: patientParams.ventricularPulseWidth || 0.4,
        unit: "ms",
        type: "select",
        options: optionsToNumbers([
          "0.05",
          "0.1",
          "0.2",
          "0.3",
          "0.4",
          "0.5",
          "0.6",
          "0.7",
          "0.8",
          "0.9",
          "1.0",
          "1.1",
          "1.2",
          "1.3",
          "1.4",
          "1.5",
          "1.6",
          "1.7",
          "1.8",
          "1.9",
        ]),
        range: "0.05, 0.1-1.9 ms (0.1 steps)",
        isValid: true,
      },
      {
        // Sensitivity Parameters
        id: "atrialSensitivity",
        name: "Atrial Sensitivity",
        value: toNumber(patientParams.atrialSensitivity, 0.75),
        unit: "mV",
        type: "select",
        options: optionsToNumbers(["0.25", "0.5", "0.75"]),
        range: "0.25, 0.5, 0.75",
        isValid: true,
      },
      {
        // Sensitivity Parameters
        id: "ventricularSensitivity",
        name: "Ventricular Sensitivity",
        value: toNumber(patientParams.ventricularSensitivity, 2.5),
        unit: "mV",
        type: "select",
        options: optionsToNumbers([
          "1.0",
          "1.5",
          "2.0",
          "2.5",
          "3.0",
          "3.5",
          "4.0",
          "4.5",
          "5.0",
          "5.5",
          "6.0",
          "6.5",
          "7.0",
          "7.5",
          "8.0",
          "8.5",
          "9.0",
          "9.5",
          "10.0",
        ]),
        range: "1.0-10 mV",
        isValid: true,
      },
      {
        // Refractory Period Parameters
        id: "ventricularRefractoryPeriod",
        name: "Ventricular Refractory Period",
        value: patientParams.ventricularRefractoryPeriod || 320,
        unit: "ms",
        type: "number",
        min: 150,
        max: 500,
        step: 10,
        range: "150-500 ms",
        isValid: true,
      },
      {
        // Refractory Period Parameters
        id: "atrialRefractoryPeriod",
        name: "Atrial Refractory Period",
        value: patientParams.atrialRefractoryPeriod || 250,
        unit: "ms",
        type: "number",
        min: 150,
        max: 500,
        step: 10,
        range: "150-500 ms",
        isValid: true,
      },
      {
        // PVARP Parameters
        id: "pvarp",
        name: "PVARP",
        value: patientParams.pvarp || 250,
        unit: "ms",
        type: "number",
        min: 150,
        max: 500,
        step: 10,
        range: "150-500 ms",
        isValid: true,
      },
      {
        // PVARP Extension Parameters
        id: "pvarpExtension",
        name: "PVARP Extension",
        value: toNumber(patientParams.pvarpExtension, 0),
        type: "select",
        unit: "",
        options: optionsToNumbers([
          "Off",
          "50",
          "100",
          "150",
          "200",
          "250",
          "300",
          "350",
          "400",
        ]),
        range: "Off (0) or 50-400 ms",
        isValid: true,
        allowOff: true,
      },
      {
        // Hysteresis Rate Limit
        id: "hysteresisRateLimit",
        name: "Hysteresis Rate Limit",
        value: toNumber(patientParams.hysteresisRateLimit, 0),
        type: "select",
        unit: "",
        options: optionsToNumbers([
          "Off",
          "30",
          "35",
          "40",
          "45",
          "50",
          "55",
          "60",
          "65",
          "70",
          "75",
          "80",
          "85",
          "90",
          "95",
          "100",
          "105",
          "110",
          "115",
          "120",
          "125",
          "130",
          "135",
          "140",
          "145",
          "150",
          "155",
          "160",
          "165",
          "170",
          "175",
        ]),
        range: "Off (0) or same as Lower Rate Limit",
        isValid: true,
        allowOff: true,
      },
      {
        // Rate Smoothing
        id: "rateSmoothing",
        name: "Rate Smoothing",
        value: toNumber(patientParams.rateSmoothing, 0),
        type: "select",
        unit: "",
        options: optionsToNumbers([
          "Off",
          "3%",
          "6%",
          "9%",
          "12%",
          "15%",
          "18%",
          "21%",
          "25%",
        ]),
        range: "Off (0), 3-25%",
        isValid: true,
        allowOff: true,
      },
      {
        // ATR Mode
        id: "atrMode",
        name: "ATR Mode",
        value: toNumber(patientParams.atrMode, 0),
        type: "select",
        unit: "",
        options: [0, 1],
        range: "On (1) or Off (0)",
        isValid: true,
        allowOff: true,
      },
      {
        // ATR Duration
        id: "atrDuration",
        name: "ATR Duration",
        value: toNumber(patientParams.atrDuration, 20),
        unit: "cc",
        type: "select",
        options: optionsToNumbers([
          "10",
          "20",
          "40",
          "60",
          "80",
          "100",
          "200",
          "300",
          "400",
          "500",
          "600",
          "700",
          "800",
          "900",
          "1000",
          "1100",
          "1200",
          "1300",
          "1400",
          "1500",
          "1600",
          "1700",
          "1800",
          "1900",
          "2000",
        ]),
        range: "10, 20-80, 100-2000 cardiac cycles",
        isValid: true,
      },
      {
        // ATR Fallback Time
        id: "atrFallbackTime",
        name: "ATR Fallback Time",
        value: patientParams.atrFallbackTime || 1,
        unit: "min",
        type: "number",
        min: 1,
        max: 5,
        step: 1,
        range: "1-5 min",
        isValid: true,
      },
      {
        // Ventricular Blanking
        id: "ventricularBlanking",
        name: "Ventricular Blanking",
        value: patientParams.ventricularBlanking || 40,
        unit: "ms",
        type: "number",
        min: 30,
        max: 60,
        step: 10,
        range: "30-60 ms",
        isValid: true,
      },
      {
        id: "activityThreshold",
        name: "Activity Threshold",
        value: mapActivity(patientParams.activityThreshold, 4),
        type: "select",
        unit: "",
        options: [1, 2, 3, 4, 5, 6, 7],
        range: "1..7 mapping to V-Low..V-High",
        isValid: true,
      },
      {
        id: "reactionTime",
        name: "Reaction Time",
        value: patientParams.reactionTime || 30,
        unit: "sec",
        type: "number",
        min: 10,
        max: 50,
        step: 10,
        range: "10-50 sec",
        isValid: true,
      },
      {
        id: "responseFactor",
        name: "Response Factor",
        value: patientParams.responseFactor || 8,
        type: "number",
        unit: "",
        min: 1,
        max: 16,
        step: 1,
        range: "1-16",
        isValid: true,
      },
      {
        id: "recoveryTime",
        name: "Recovery Time",
        value: patientParams.recoveryTime || 5,
        unit: "min",
        type: "number",
        min: 2,
        max: 16,
        step: 1,
        range: "2-16 min",
        isValid: true,
      },
    ];
  };

  const [parameters, setParameters] = useState<Parameter[]>(
    getInitialParameters()
  );

  // Update parameters when patient changes
  useEffect(() => {
    setParameters(getInitialParameters());
    setHasChanges(false);
  }, [selectedPatient]);

  const modes = [
    "AAT",
    "VVT",
    "AOO",
    "AAI",
    "VOO",
    "VVI",
    "VDD",
    "DOO",
    "DDI",
    "DDD",
    "AOOR",
    "AAIR",
    "VOOR",
    "VVIR",
    "VDDR",
    "DOOR",
    "DDIR",
    "DDDR",
  ];

  // Helper function to validate cardiac cycle time
  // Ensures: 60000 - (ARP + AtrialPulseWidth) * LRL > 0
  // This guarantees enough time for one full cardiac cycle at the programmed LRL
  const validateCardiacCycleTime = (
    lowerRateLimit: number | undefined,
    atrialRefractoryPeriod: number | undefined,
    atrialPulseWidth: number | undefined
  ): boolean => {
    if (lowerRateLimit === undefined || atrialRefractoryPeriod === undefined || atrialPulseWidth === undefined) {
      return true; // Can't validate if values are missing
    }
    
    const timePerMinute = 60000; // milliseconds in a minute
    const totalRefractoryTime = (atrialRefractoryPeriod + atrialPulseWidth) * lowerRateLimit;
    const remainingTime = timePerMinute - totalRefractoryTime;
    
    return remainingTime > 0;
  };

  // Helper function to calculate Sensed AV Delay
  // Sensed AV Delay = Fixed AV Delay + Sensed AV Delay Offset
  const calculateSensedAVDelay = (
    fixedAVDelay: number | undefined,
    sensedAVDelayOffset: number | undefined
  ): number | undefined => {
    if (fixedAVDelay === undefined || sensedAVDelayOffset === undefined) {
      return undefined;
    }
    return fixedAVDelay + sensedAVDelayOffset;
  };

  // Update parameter value and validity
  const updateParameter = (id: string, value: number) => {
    setParameters((prev) => {
      // Get current rate limits for cross-validation
      const currentLowerRate = prev.find((p) => p.id === "lowerRateLimit")?.value;
      const currentUpperRate = prev.find((p) => p.id === "upperRateLimit")?.value;
      const currentMSR = prev.find((p) => p.id === "maximumSensorRate")?.value;
      const currentARP = prev.find((p) => p.id === "atrialRefractoryPeriod")?.value;
      const currentAtrialPulseWidth = prev.find((p) => p.id === "atrialPulseWidth")?.value;
      const currentFixedAVDelay = prev.find((p) => p.id === "fixedAVDelay")?.value;
      const currentMinimumDynamicAVDelay = prev.find((p) => p.id === "minimumDynamicAVDelay")?.value;
      const currentSensedAVDelayOffset = prev.find((p) => p.id === "sensedAVDelayOffset")?.value;

      const updatedParams = prev.map((param) => {
        if (param.id === id) {
          let numValue = value;
          let isValid = true;
          
          if (param.type === "number") {
            if (
              numValue === null ||
              numValue === undefined ||
              isNaN(numValue)
            ) {
              isValid = false;
            } else if (param.min !== undefined && numValue < param.min) {
              // check min
              isValid = false;
            } else if (param.max !== undefined && numValue > param.max) {
              // check max
              isValid = false;
            }
            
            // Cross-validation for rate limits
            if (param.id === "lowerRateLimit" && currentUpperRate !== undefined) {
              if (numValue > currentUpperRate) {
                isValid = false;
              }
            } else if (param.id === "upperRateLimit" && currentLowerRate !== undefined) {
              if (numValue < currentLowerRate) {
                isValid = false;
              }
            }
            
            // MSR must be greater than URL and LRL
            if (param.id === "maximumSensorRate") {
              if (currentUpperRate !== undefined && numValue <= currentUpperRate) {
                isValid = false;
              }
              if (currentLowerRate !== undefined && numValue <= currentLowerRate) {
                isValid = false;
              }
            } else if (param.id === "upperRateLimit" && currentMSR !== undefined) {
              // URL must be less than MSR
              if (numValue >= currentMSR) {
                isValid = false;
              }
            } else if (param.id === "lowerRateLimit" && currentMSR !== undefined) {
              // LRL must be less than MSR
              if (numValue >= currentMSR) {
                isValid = false;
              }
            }
            
            // Cardiac cycle time validation
            // Check if changing LRL, ARP, or AtrialPulseWidth violates cycle time constraint
            if (param.id === "lowerRateLimit" || param.id === "atrialRefractoryPeriod" || param.id === "atrialPulseWidth") {
              const newLRL = param.id === "lowerRateLimit" ? numValue : currentLowerRate;
              const newARP = param.id === "atrialRefractoryPeriod" ? numValue : currentARP;
              const newAtrialPulseWidth = param.id === "atrialPulseWidth" ? numValue : currentAtrialPulseWidth;
              
              if (!validateCardiacCycleTime(newLRL, newARP, newAtrialPulseWidth)) {
                isValid = false;
              }
            }
            
            // AV Delay validation constraints
            // 1. Minimum Dynamic AV Delay ≤ Fixed AV Delay
            // 2. Minimum Dynamic AV Delay ≤ Sensed AV Delay (where Sensed = FixedAV + Offset)
            if (param.id === "minimumDynamicAVDelay") {
              // Constraint 1: Minimum Dynamic AV Delay ≤ Fixed AV Delay
              if (currentFixedAVDelay !== undefined && numValue > currentFixedAVDelay) {
                isValid = false;
              }
              
              // Constraint 2: Minimum Dynamic AV Delay ≤ Sensed AV Delay
              const sensedAVDelay = calculateSensedAVDelay(currentFixedAVDelay, currentSensedAVDelayOffset);
              if (sensedAVDelay !== undefined && numValue > sensedAVDelay) {
                isValid = false;
              }
            } else if (param.id === "fixedAVDelay") {
              // When Fixed AV Delay changes, check both constraints
              // Constraint 1: Minimum Dynamic AV Delay ≤ Fixed AV Delay
              if (currentMinimumDynamicAVDelay !== undefined && currentMinimumDynamicAVDelay > numValue) {
                isValid = false;
              }
              
              // Constraint 2: Minimum Dynamic AV Delay ≤ Sensed AV Delay
              const sensedAVDelay = calculateSensedAVDelay(numValue, currentSensedAVDelayOffset);
              if (sensedAVDelay !== undefined && currentMinimumDynamicAVDelay !== undefined && currentMinimumDynamicAVDelay > sensedAVDelay) {
                isValid = false;
              }
            } else if (param.id === "sensedAVDelayOffset") {
              // When Sensed AV Delay Offset changes, check constraint 2
              // Constraint 2: Minimum Dynamic AV Delay ≤ Sensed AV Delay
              const sensedAVDelay = calculateSensedAVDelay(currentFixedAVDelay, numValue);
              if (sensedAVDelay !== undefined && currentMinimumDynamicAVDelay !== undefined && currentMinimumDynamicAVDelay > sensedAVDelay) {
                isValid = false;
              }
            }
          } else if (param.type === "select") {
            if (param.options && !param.options.includes(numValue)) {
              isValid = false;
            }
          }
          
          return {
            ...param,
            value: numValue,
            isDirty: true,
            isValid,
          };
        }
        
        // Revalidate the other rate limit when one changes
        if (
          (id === "lowerRateLimit" && param.id === "upperRateLimit") ||
          (id === "upperRateLimit" && param.id === "lowerRateLimit")
        ) {
          const newLowerRate = id === "lowerRateLimit" ? value : currentLowerRate;
          const newUpperRate = id === "upperRateLimit" ? value : currentUpperRate;
          
          let isValid = param.isValid !== false; // preserve other validation
          if (newLowerRate !== undefined && newUpperRate !== undefined) {
            if (param.id === "lowerRateLimit" && newLowerRate > newUpperRate) {
              isValid = false;
            } else if (param.id === "upperRateLimit" && newUpperRate < newLowerRate) {
              isValid = false;
            } else if (param.id === "lowerRateLimit" && newLowerRate <= newUpperRate) {
              // Re-validate if it was previously invalid due to cross-validation
              isValid = true;
              // Still check against min/max
              if (param.min !== undefined && param.value < param.min) {
                isValid = false;
              }
              if (param.max !== undefined && param.value > param.max) {
                isValid = false;
              }
            } else if (param.id === "upperRateLimit" && newUpperRate >= newLowerRate) {
              // Re-validate if it was previously invalid due to cross-validation
              isValid = true;
              // Still check against min/max
              if (param.min !== undefined && param.value < param.min) {
                isValid = false;
              }
              if (param.max !== undefined && param.value > param.max) {
                isValid = false;
              }
            }
          }
          
          return {
            ...param,
            isValid,
          };
        }
        
        // Revalidate MSR, URL, and LRL relationships when any of them changes
        if (
          (id === "maximumSensorRate" || id === "upperRateLimit" || id === "lowerRateLimit") &&
          (param.id === "maximumSensorRate" || param.id === "upperRateLimit" || param.id === "lowerRateLimit")
        ) {
          const newMSR = id === "maximumSensorRate" ? value : (param.id === "maximumSensorRate" ? param.value : currentMSR);
          const newURL = id === "upperRateLimit" ? value : (param.id === "upperRateLimit" ? param.value : currentUpperRate);
          const newLRL = id === "lowerRateLimit" ? value : (param.id === "lowerRateLimit" ? param.value : currentLowerRate);
          
          // Only revalidate if this parameter wasn't the one being changed (to avoid double validation)
          if (param.id !== id) {
            let isValid = param.isValid !== false; // preserve other validation
            
            // MSR must be greater than URL and LRL
            if (param.id === "maximumSensorRate") {
              if (newURL !== undefined && newMSR !== undefined && newMSR <= newURL) {
                isValid = false;
              }
              if (newLRL !== undefined && newMSR !== undefined && newMSR <= newLRL) {
                isValid = false;
              }
            } else if (param.id === "upperRateLimit") {
              // URL must be less than MSR
              if (newMSR !== undefined && newURL !== undefined && newURL >= newMSR) {
                isValid = false;
              }
              // URL must still be >= LRL (existing constraint)
              if (newLRL !== undefined && newURL !== undefined && newURL < newLRL) {
                isValid = false;
              }
            } else if (param.id === "lowerRateLimit") {
              // LRL must be less than MSR
              if (newMSR !== undefined && newLRL !== undefined && newLRL >= newMSR) {
                isValid = false;
              }
              // LRL must still be <= URL (existing constraint)
              if (newURL !== undefined && newLRL !== undefined && newLRL > newURL) {
                isValid = false;
              }
            }
            
            // Still check min/max constraints
            if (param.min !== undefined && param.value < param.min) {
              isValid = false;
            }
            if (param.max !== undefined && param.value > param.max) {
              isValid = false;
            }
            
            return {
              ...param,
              isValid,
            };
          }
        }
        
        // Revalidate AV Delay relationships when any of them changes
        if (
          (id === "minimumDynamicAVDelay" || id === "fixedAVDelay" || id === "sensedAVDelayOffset") &&
          (param.id === "minimumDynamicAVDelay" || param.id === "fixedAVDelay" || param.id === "sensedAVDelayOffset")
        ) {
          const newMinimumDynamicAVDelay = id === "minimumDynamicAVDelay" ? value : (param.id === "minimumDynamicAVDelay" ? param.value : currentMinimumDynamicAVDelay);
          const newFixedAVDelay = id === "fixedAVDelay" ? value : (param.id === "fixedAVDelay" ? param.value : currentFixedAVDelay);
          const newSensedAVDelayOffset = id === "sensedAVDelayOffset" ? value : (param.id === "sensedAVDelayOffset" ? param.value : currentSensedAVDelayOffset);
          
          // Only revalidate if this parameter wasn't the one being changed (to avoid double validation)
          if (param.id !== id) {
            let isValid = param.isValid !== false; // preserve other validation
            
            const sensedAVDelay = calculateSensedAVDelay(newFixedAVDelay, newSensedAVDelayOffset);
            
            // Constraint 1: Minimum Dynamic AV Delay ≤ Fixed AV Delay
            // Constraint 2: Minimum Dynamic AV Delay ≤ Sensed AV Delay (where Sensed = FixedAV + Offset)
            if (param.id === "minimumDynamicAVDelay") {
              if (newFixedAVDelay !== undefined && newMinimumDynamicAVDelay !== undefined && newMinimumDynamicAVDelay > newFixedAVDelay) {
                isValid = false;
              }
              if (sensedAVDelay !== undefined && newMinimumDynamicAVDelay !== undefined && newMinimumDynamicAVDelay > sensedAVDelay) {
                isValid = false;
              }
            } else if (param.id === "fixedAVDelay") {
              if (newMinimumDynamicAVDelay !== undefined && newFixedAVDelay !== undefined && newMinimumDynamicAVDelay > newFixedAVDelay) {
                isValid = false;
              }
              if (sensedAVDelay !== undefined && newMinimumDynamicAVDelay !== undefined && newMinimumDynamicAVDelay > sensedAVDelay) {
                isValid = false;
              }
            } else if (param.id === "sensedAVDelayOffset") {
              if (sensedAVDelay !== undefined && newMinimumDynamicAVDelay !== undefined && newMinimumDynamicAVDelay > sensedAVDelay) {
                isValid = false;
              }
            }
            
            // Still check min/max constraints
            if (param.min !== undefined && param.value < param.min) {
              isValid = false;
            }
            if (param.max !== undefined && param.value > param.max) {
              isValid = false;
            }
            
            return {
              ...param,
              isValid,
            };
          }
        }
        
        // Revalidate cardiac cycle time when LRL, ARP, or AtrialPulseWidth changes
        if (
          (id === "lowerRateLimit" || id === "atrialRefractoryPeriod" || id === "atrialPulseWidth") &&
          (param.id === "lowerRateLimit" || param.id === "atrialRefractoryPeriod" || param.id === "atrialPulseWidth")
        ) {
          const newLRL = id === "lowerRateLimit" ? value : (param.id === "lowerRateLimit" ? param.value : currentLowerRate);
          const newARP = id === "atrialRefractoryPeriod" ? value : (param.id === "atrialRefractoryPeriod" ? param.value : currentARP);
          const newAtrialPulseWidth = id === "atrialPulseWidth" ? value : (param.id === "atrialPulseWidth" ? param.value : currentAtrialPulseWidth);
          
          // Only revalidate if this parameter wasn't the one being changed (to avoid double validation)
          if (param.id !== id) {
            let isValid = param.isValid !== false; // preserve other validation
            
            // Re-check cardiac cycle time constraint
            if (!validateCardiacCycleTime(newLRL, newARP, newAtrialPulseWidth)) {
              isValid = false;
            } else {
              // If cardiac cycle is valid, still check min/max constraints
              if (param.min !== undefined && param.value < param.min) {
                isValid = false;
              }
              if (param.max !== undefined && param.value > param.max) {
                isValid = false;
              }
            }
            
            return {
              ...param,
              isValid,
            };
          }
        }
        
        return param;
      });

      // Save temporary parameters to sessionStorage for reports
      if (selectedPatient?.id) {
        try {
          const parameterValues = updatedParams.reduce((acc, param) => {
            acc[param.id] = param.value;
            return acc;
          }, {} as any);

          const dirtyCount = updatedParams.filter(p => p.isDirty).length;

          sessionStorage.setItem('temporaryParameters', JSON.stringify(parameterValues));
          sessionStorage.setItem('temporaryParametersMeta', JSON.stringify({
            patientId: selectedPatient.id,
            modifiedAt: new Date().toISOString(),
            modifiedCount: dirtyCount,
            mode: selectedMode,
          }));
        } catch (error) {
          console.error('Error saving temporary parameters:', error);
        }
      }

      return updatedParams;
    });
    setHasChanges(true);
  };

  // Increment function
  const incrementParameter = (param: Parameter) => {
    if (param.type === "select" && param.options) {
      // find parameter value index in param.options
      const currentIndex = param.options.indexOf(param.value);
      if (currentIndex < param.options.length - 1) {
        updateParameter(param.id, param.options[currentIndex + 1]);
      }
    } else if (param.type === "number") {
      const currentValue = param.value;
      // Always recompute dynamic step for lowerRateLimit when step === 'custom'
      const step = getStepValue(param) ?? 1;
      const newValue = currentValue + step; // increment by step value
      if (param.max === undefined || newValue <= param.max) {
        updateParameter(param.id, newValue); // update parameter value if within max limit
      }
    }
  };

  // Decrement function
  const decrementParameter = (param: Parameter) => {
    if (param.type === "select" && param.options) {
      const currentIndex = param.options.indexOf(param.value); // find parameter value index in param.options
      if (currentIndex > 0) {
        updateParameter(param.id, param.options[currentIndex - 1]);
      }
    } else if (param.type === "number") {
      const currentValue = param.value;
      // Recompute dynamic step based on current value
      const step = getStepValue(param) ?? 1;
      const newValue = currentValue - step; // decrement by step value
      if (param.min === undefined || newValue >= param.min) {
        updateParameter(param.id, newValue); // update parameter value if within min limit
      }
    }
  };

  // Reset all parameters to nominal values
  const handleResetToNominal = () => {
    // Define nominal values (all numbers)
    const nominalValues: Record<string, number> = {
      lowerRateLimit: 60,
      upperRateLimit: 120,
      maximumSensorRate: 120,
      fixedAVDelay: 150,
      dynamicAVDelay: 0,
      minimumDynamicAVDelay: 50,
      sensedAVDelayOffset: 0,
      atrialAmplitudeRegulated: 3.5,
      ventricularAmplitudeRegulated: 3.5,
      atrialAmplitudeUnregulated: 3.75,
      ventricularAmplitudeUnregulated: 3.75,
      atrialPulseWidth: 0.4,
      ventricularPulseWidth: 0.4,
      atrialSensitivity: 0.75,
      ventricularSensitivity: 2.5,
      ventricularRefractoryPeriod: 320,
      atrialRefractoryPeriod: 250,
      pvarp: 250,
      pvarpExtension: 0,
      hysteresisRateLimit: 0,
      rateSmoothing: 0,
      atrMode: 0,
      atrDuration: 20,
      atrFallbackTime: 1,
      ventricularBlanking: 40,
      activityThreshold: 4,
      reactionTime: 30,
      responseFactor: 8,
      recoveryTime: 5,
    };

    // Reset all parameters to nominal values
    setParameters((prev) =>
      prev.map((param) => ({
        ...param,
        value: nominalValues[param.id] ?? param.value, // only checks for null or undefined
        isDirty: true, // mark as dirty
        isValid: true,
      }))
    );
    setHasChanges(true);
  };

  // Save parameters to localStorage
  const saveToLocalStorage = (patientId: string, params: any) => {
    try {
      // Get existing saved parameters or initialize empty object
      const savedParams = JSON.parse(
        localStorage.getItem("pacemakerParameters") || "{}"
      );

      // Add timestamp for reporting
      const parameterData = {
        timestamp: new Date().toISOString(),
        mode: selectedMode,
        values: params,
      };

      // Save under patient ID with history
      if (!savedParams[patientId]) {
        savedParams[patientId] = [];
      }
      savedParams[patientId].push(parameterData);

      localStorage.setItem("pacemakerParameters", JSON.stringify(savedParams));

      console.log("Parameters saved successfully!");
      console.log("Patient ID:", patientId);
      console.log("Saved data:", parameterData);
      console.log("Full storage:", savedParams);
    } catch (error) {
      console.error("Error saving parameters to localStorage:", error);
    }
  };

  const handleSaveChanges = () => {
    // Prevent saving if there are any invalid parameters
    if (!canSave || invalidCount > 0) return;

    const parameterValues = parameters.reduce((acc, param) => {
      acc[param.id] = param.value;
      return acc;
    }, {} as any);

    // Save to localStorage with patient ID
    if (selectedPatient?.id) {
      saveToLocalStorage(selectedPatient.id, parameterValues);
      
      // Clear temporary parameters since they're now saved
      try {
        sessionStorage.removeItem('temporaryParameters');
        sessionStorage.removeItem('temporaryParametersMeta');
      } catch (error) {
        console.error('Error clearing temporary parameters:', error);
      }
    }

    onParameterSaved(parameterValues);
    setParameters((prev) => prev.map((p) => ({ ...p, isDirty: false })));
    setHasChanges(false);
  };

  // Helper functions for reports
  const getParameterHistory = (patientId: string) => {
    try {
      const savedParams = JSON.parse(
        localStorage.getItem("pacemakerParameters") || "{}"
      );
      return savedParams[patientId] || [];
    } catch (error) {
      console.error("Error getting parameter history:", error);
      return [];
    }
  };

  const getLatestParameters = (patientId: string) => {
    const history = getParameterHistory(patientId);
    return history.length > 0 ? history[history.length - 1] : null;
  };

  // Send parameters to pacemaker (deliverable 2) now implemented via WebSocket
  const handleSendToPacemaker = () => {
    if (!canSend || invalidCount > 0) return;
    
    const parameterValues = parameters.reduce((acc, param) => {
      acc[param.id] = param.value;
      return acc;
    }, {} as any);

    // Add mode and timestamp
    const dataToSend = {
      mode: selectedMode,
      ...parameterValues,
      timestamp: new Date().toISOString(),
    };

    console.log("Sending parameters to pacemaker:", dataToSend);
    
    // Send via WebSocket
    if (onSendToPacemaker) {
      onSendToPacemaker(dataToSend);
    }
  };

  // Handle mode selection with availability check
  const handleModeSelection = (mode: string) => {
    setSelectedMode(mode);
    setHasChanges(true);
    
    if (!AVAILABLE_MODES.includes(mode)) {
      setModeUnavailableAlert(true);
    } else {
      setModeUnavailableAlert(false);
    }
  };

  const invalidCount = parameters.filter((p) => p.isValid === false).length;
  const isModeAvailable = AVAILABLE_MODES.includes(selectedMode);
  const canSave =
    hasChanges &&
    invalidCount === 0 &&
    isModeAvailable &&
    parameters.every((p) => p.isValid !== false);
  const canSend =
    !hasChanges &&
    invalidCount === 0 &&
    isModeAvailable &&
    isConnected &&
    parameters.every((p) => p.isValid !== false);

  const getStepValue = (param: Parameter): number | undefined => {
    if (param.type !== "number") return undefined;

    if (param.step === "custom" && param.id === "lowerRateLimit") {
      return getLowerRateLimitStep(Number(param.value));
    }

    return param.step as number;
  };

  // Check if increment/decrement is possible
  const canIncrement = (param: Parameter): boolean => {
    if (param.type === "select" && param.options) {
      // find parameter value index in param.options
      const currentIndex = param.options.indexOf(param.value);
      return currentIndex < param.options.length - 1;
    } else if (param.type === "number") {
      const currentValue = param.value;
      let step: number =
        typeof param.step === "number"
          ? param.step
          : getLowerRateLimitStep(currentValue);
      return param.max === undefined || currentValue + step <= param.max;
    }
    return false;
  };

  // Check if decrement is possible
  const canDecrement = (param: Parameter): boolean => {
    if (param.type === "select" && param.options) {
      // find parameter value index in param.options
      const currentIndex = param.options.indexOf(param.value);
      return currentIndex > 0;
    } else if (param.type === "number") {
      const currentValue = param.value;
      let step: number =
        typeof param.step === "number"
          ? param.step
          : getLowerRateLimitStep(currentValue - 1);
      return param.min === undefined || currentValue - step >= param.min;
    }
    return false;
  };

  // UI for parameter input fields
  const ParameterInputField = ({ param }: { param: Parameter }) => {
    const intervalRef = useRef<NodeJS.Timeout | null>(null);
    const timeoutRef = useRef<NodeJS.Timeout | null>(null);

    const startRepeating = useCallback((action: () => void) => {
      // Clear any existing intervals/timeouts
      if (intervalRef.current) clearInterval(intervalRef.current);
      if (timeoutRef.current) clearTimeout(timeoutRef.current);

      // Execute immediately
      action();

      // Start repeating after initial delay
      timeoutRef.current = setTimeout(() => {
        intervalRef.current = setInterval(action, 150); // Repeat every 150ms
      }, 500); // Initial delay of 500ms
    }, []);

    const stopRepeating = useCallback(() => {
      if (intervalRef.current) {
        clearInterval(intervalRef.current);
        intervalRef.current = null;
      }
      if (timeoutRef.current) {
        clearTimeout(timeoutRef.current);
        timeoutRef.current = null;
      }
    }, []);

    // Clean up on unmount
    useEffect(() => {
      return () => {
        stopRepeating();
      };
    }, [stopRepeating]);

    const handleIncrementStart = useCallback(() => {
      if (!canIncrement(param)) return;
      startRepeating(() => {
        if (canIncrement(param)) {
          incrementParameter(param);
        } else {
          stopRepeating();
        }
      });
    }, [param, startRepeating, stopRepeating]);

    const handleDecrementStart = useCallback(() => {
      if (!canDecrement(param)) return;
      startRepeating(() => {
        if (canDecrement(param)) {
          decrementParameter(param);
        } else {
          stopRepeating();
        }
      });
    }, [param, startRepeating, stopRepeating]);

    return (
      <div className="space-y-2">
        <Label htmlFor={param.id} className="text-sm font-medium text-gray-700">
          {param.name} {param.unit && `(${param.unit})`}
        </Label>
        <div className="relative flex items-center gap-2">
          <div className="flex-1 relative">
            <Input
              id={param.id}
              name={param.id}
              value={param.value}
              onChange={(e) =>
                updateParameter(param.id, Number(e.target.value))
              }
              type="text"
              readOnly
              className={`h-11 text-center ${
                param.isValid === false
                  ? "border-red-500 bg-red-50"
                  : param.isDirty
                  ? "border-blue-500 bg-blue-50"
                  : "bg-gray-50"
              }`}
              placeholder={param.value.toString()}
            />
            {param.isDirty && (
              <div className="absolute right-2 top-3 w-2 h-2 bg-blue-500 rounded-full"></div>
            )}
          </div>
          <div className="flex flex-col gap-1">
            <Button
              variant="outline"
              size="sm"
              className="h-5 w-8 p-0"
              onMouseDown={handleIncrementStart}
              onMouseUp={stopRepeating}
              onMouseLeave={stopRepeating}
              onTouchStart={handleIncrementStart}
              onTouchEnd={stopRepeating}
              disabled={!canIncrement(param)}
            >
              <ChevronUp className="h-3 w-3" />
            </Button>
            <Button
              variant="outline"
              size="sm"
              className="h-5 w-8 p-0"
              onMouseDown={handleDecrementStart}
              onMouseUp={stopRepeating}
              onMouseLeave={stopRepeating}
              onTouchStart={handleDecrementStart}
              onTouchEnd={stopRepeating}
              disabled={!canDecrement(param)}
            >
              <ChevronDown className="h-3 w-3" />
            </Button>
          </div>
        </div>
        <p className="text-xs text-gray-500">{param.range}</p>
      </div>
    );
  };

  return (
    <div className="max-w-7xl mx-auto p-6 space-y-6">
      {/* Header */}
      <div className="space-y-2">
        <h1 className="text-3xl font-semibold text-gray-900">
          Device Parameters
        </h1>
        <p className="text-gray-600">Configure pacemaker parameters</p>
      </div>

      {/* Validation Alerts */}
      {invalidCount > 0 && (() => {
        const lowerRateLimit = parameters.find((p) => p.id === "lowerRateLimit");
        const upperRateLimit = parameters.find((p) => p.id === "upperRateLimit");
        const maximumSensorRate = parameters.find((p) => p.id === "maximumSensorRate");
        const atrialRefractoryPeriod = parameters.find((p) => p.id === "atrialRefractoryPeriod");
        const atrialPulseWidth = parameters.find((p) => p.id === "atrialPulseWidth");
        const minimumDynamicAVDelay = parameters.find((p) => p.id === "minimumDynamicAVDelay");
        const fixedAVDelay = parameters.find((p) => p.id === "fixedAVDelay");
        const sensedAVDelayOffset = parameters.find((p) => p.id === "sensedAVDelayOffset");
        
        const cardiacCycleInvalid = !validateCardiacCycleTime(
          lowerRateLimit?.value,
          atrialRefractoryPeriod?.value,
          atrialPulseWidth?.value
        );
        
        const hasCardiacCycleError = cardiacCycleInvalid && (
          lowerRateLimit?.isValid === false ||
          atrialRefractoryPeriod?.isValid === false ||
          atrialPulseWidth?.isValid === false
        );
        
        const hasMSRError = (
          maximumSensorRate?.isValid === false ||
          (upperRateLimit?.isValid === false && upperRateLimit?.value !== undefined && maximumSensorRate?.value !== undefined && upperRateLimit.value >= maximumSensorRate.value) ||
          (lowerRateLimit?.isValid === false && lowerRateLimit?.value !== undefined && maximumSensorRate?.value !== undefined && lowerRateLimit.value >= maximumSensorRate.value)
        );
        
        const sensedAVDelay = calculateSensedAVDelay(fixedAVDelay?.value, sensedAVDelayOffset?.value);
        const hasAVDelayError = (
          minimumDynamicAVDelay?.isValid === false ||
          fixedAVDelay?.isValid === false ||
          sensedAVDelayOffset?.isValid === false ||
          (minimumDynamicAVDelay?.value !== undefined && fixedAVDelay?.value !== undefined && minimumDynamicAVDelay.value > fixedAVDelay.value) ||
          (minimumDynamicAVDelay?.value !== undefined && sensedAVDelay !== undefined && minimumDynamicAVDelay.value > sensedAVDelay)
        );
        
        return (
          <Alert variant="destructive">
            <AlertCircle className="h-4 w-4" />
            <AlertDescription>
              {hasCardiacCycleError ? (
                <>
                  <strong>Cardiac Cycle Time Error:</strong> At the programmed Lower Rate Limit, there is not enough time for one full cardiac cycle. 
                  The constraint requires: 60000 ms - (ARP + Atrial Pulse Width) × LRL &gt; 0. 
                  Please adjust Lower Rate Limit, Atrial Refractory Period, or Atrial Pulse Width.
                </>
              ) : hasMSRError ? (
                <>
                  <strong>Maximum Sensor Rate Error:</strong> Maximum Sensor Rate (MSR) must be greater than both Upper Rate Limit (URL) and Lower Rate Limit (LRL). 
                  Please adjust MSR, URL, or LRL to satisfy: MSR &gt; URL and MSR &gt; LRL.
                </>
              ) : hasAVDelayError ? (
                <>
                  <strong>AV Delay Error:</strong> Minimum Dynamic AV Delay must be less than or equal to both Fixed AV Delay and Sensed AV Delay. 
                  The constraints require: Minimum Dynamic AV Delay ≤ Fixed AV Delay, and Minimum Dynamic AV Delay ≤ Sensed AV Delay (where Sensed AV Delay = Fixed AV Delay + Sensed AV Delay Offset). 
                  Please adjust Minimum Dynamic AV Delay, Fixed AV Delay, or Sensed AV Delay Offset.
                </>
              ) : (
                "Error: Invalid parameter values. Please check all parameters for validation errors."
              )}
            </AlertDescription>
          </Alert>
        );
      })()}

      {/* Mode Unavailable Alert */}
      {modeUnavailableAlert && (
        <Alert variant="destructive">
          <AlertCircle className="h-4 w-4" />
          <AlertDescription>
            This pacing mode is not available. 
          </AlertDescription>
        </Alert>
      )}


      <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">
        {/* Left Column - Parameter Sections */}
        <div className="lg:col-span-2 space-y-6">
          {/* Basic Rate Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">Basic Rate Parameters</CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "lowerRateLimit")!}
                />
                <ParameterInputField
                  param={parameters.find((p) => p.id === "upperRateLimit")!}
                />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "maximumSensorRate")!}
                />
              </div>
            </CardContent>
          </Card>

          {/* AV Delay Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">AV Delay Parameters</CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "fixedAVDelay")!}
                />
                <ParameterInputField
                  param={parameters.find((p) => p.id === "dynamicAVDelay")!}
                />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={
                    parameters.find((p) => p.id === "minimumDynamicAVDelay")!
                  }
                />
                <ParameterInputField
                  param={
                    parameters.find((p) => p.id === "sensedAVDelayOffset")!
                  }
                />
              </div>
            </CardContent>
          </Card>

          {/* Amplitude Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">Amplitude Parameters</CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="space-y-2">
                <h3 className="font-semibold text-sm text-gray-700">
                  Regulated
                </h3>
                <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                  <ParameterInputField
                    param={
                      parameters.find(
                        (p) => p.id === "atrialAmplitudeRegulated"
                      )!
                    }
                  />
                  <ParameterInputField
                    param={
                      parameters.find(
                        (p) => p.id === "ventricularAmplitudeRegulated"
                      )!
                    }
                  />
                </div>
              </div>
              <div className="space-y-2">
                <h3 className="font-semibold text-sm text-gray-700">
                  Unregulated
                </h3>
                <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                  <ParameterInputField
                    param={
                      parameters.find(
                        (p) => p.id === "atrialAmplitudeUnregulated"
                      )!
                    }
                  />
                  <ParameterInputField
                    param={
                      parameters.find(
                        (p) => p.id === "ventricularAmplitudeUnregulated"
                      )!
                    }
                  />
                </div>
              </div>
            </CardContent>
          </Card>

          {/* Pulse Width Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">Pulse Width Parameters</CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "atrialPulseWidth")!}
                />
                <ParameterInputField
                  param={
                    parameters.find((p) => p.id === "ventricularPulseWidth")!
                  }
                />
              </div>
            </CardContent>
          </Card>

          {/* Sensitivity Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">Sensitivity Parameters</CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "atrialSensitivity")!}
                />
                <ParameterInputField
                  param={
                    parameters.find((p) => p.id === "ventricularSensitivity")!
                  }
                />
              </div>
            </CardContent>
          </Card>

          {/* Refractory Period Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                Refractory Period Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={
                    parameters.find(
                      (p) => p.id === "ventricularRefractoryPeriod"
                    )!
                  }
                />
                <ParameterInputField
                  param={
                    parameters.find((p) => p.id === "atrialRefractoryPeriod")!
                  }
                />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "pvarp")!}
                />
                <ParameterInputField
                  param={parameters.find((p) => p.id === "pvarpExtension")!}
                />
              </div>
            </CardContent>
          </Card>

          {/* Rate Control Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">Rate Control Parameters</CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={
                    parameters.find((p) => p.id === "hysteresisRateLimit")!
                  }
                />
                <ParameterInputField
                  param={parameters.find((p) => p.id === "rateSmoothing")!}
                />
              </div>
            </CardContent>
          </Card>

          {/* ATR Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">ATR Parameters</CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "atrMode")!}
                />
                <ParameterInputField
                  param={parameters.find((p) => p.id === "atrDuration")!}
                />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "atrFallbackTime")!}
                />
              </div>
            </CardContent>
          </Card>

          {/* Blanking & Activity Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                Blanking & Activity Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={
                    parameters.find((p) => p.id === "ventricularBlanking")!
                  }
                />
                <ParameterInputField
                  param={parameters.find((p) => p.id === "activityThreshold")!}
                />
              </div>
            </CardContent>
          </Card>

          {/* Rate Response Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                Rate Response Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "reactionTime")!}
                />
                <ParameterInputField
                  param={parameters.find((p) => p.id === "responseFactor")!}
                />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField
                  param={parameters.find((p) => p.id === "recoveryTime")!}
                />
              </div>
            </CardContent>
          </Card>
        </div>

        {/* Right Column - Controls */}
        <div className="space-y-6">
          {/* Parameter Controls */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">Parameter Controls</CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              {/* Pacing Mode Selection */}
              <div className="space-y-3">
                <Label className="text-sm font-medium text-gray-700">
                  Pacing Mode
                </Label>
                <div className="grid grid-cols-3 gap-2">
                  {modes.map((mode) => (
                    <ModeButton
                      key={mode}
                      mode={mode}
                      isSelected={selectedMode === mode}
                      onClick={() => handleModeSelection(mode)}
                    />
                  ))}
                </div>
                <div className="mt-2 p-3 bg-blue-50 rounded-lg">
                  <p className="text-sm text-blue-800">
                    <strong>Selected Mode: {selectedMode}</strong>
                  </p>
                </div>
              </div>

              {/* Status */}
              <div className="space-y-3">
                <Label className="text-sm font-medium text-gray-700">
                  Status
                </Label>
                <div className="space-y-2">
                  <div className="flex items-center justify-between">
                    <span className="text-sm">Changes</span>
                    <Badge variant={hasChanges ? "destructive" : "secondary"}>
                      {hasChanges ? "Unsaved" : "Saved"}
                    </Badge>
                  </div>
                  <div className="flex items-center justify-between">
                    <span className="text-sm">Validation</span>
                    <Badge
                      variant={invalidCount > 0 ? "destructive" : "default"}
                    >
                      {invalidCount > 0 ? `${invalidCount} errors` : "Valid"}
                    </Badge>
                  </div>
                  <div className="flex items-center justify-between">
                    <span className="text-sm">Received & Verified</span>
                    <Badge
                      variant={
                        verificationStatus?.status === "verified"
                          ? "default"
                          : verificationStatus?.status === "failed"
                          ? "destructive"
                          : verificationStatus?.status === "pending"
                          ? "secondary"
                          : "outline"
                      }
                    >
                      {verificationStatus?.status === "verified"
                        ? "Verified"
                        : verificationStatus?.status === "failed"
                        ? "Failed"
                        : verificationStatus?.status === "pending"
                        ? "Pending..."
                        : "Not sent"}
                    </Badge>
                  </div>
                </div>
              </div>

              {/* Action Buttons */}
              <div className="space-y-3">
                <Button
                  onClick={handleResetToNominal}
                  className="w-full h-11"
                  variant="secondary"
                >
                  Reset to Nominal Values
                </Button>

                <Button
                  onClick={handleSaveChanges}
                  disabled={!canSave}
                  className="w-full h-11"
                  variant="outline"
                  title={!isModeAvailable ? "Cannot save: mode not available" : !canSave ? "No changes to save or validation errors present" : ""}
                >
                  Save Changes
                </Button>

                <Button
                  onClick={handleSendToPacemaker}
                  disabled={!canSend}
                  className="w-full h-11 bg-gray-900 hover:bg-gray-800"
                  title={
                    !isConnected 
                      ? "Cannot send: device not connected" 
                      : !isModeAvailable 
                        ? "Cannot send: mode not available" 
                        : !canSend 
                          ? "Save changes first or fix validation errors" 
                          : ""
                  }
                >
                  Send to Pacemaker
                </Button>
              </div>
            </CardContent>
          </Card>
        </div>
      </div>
    </div>
  );
}
