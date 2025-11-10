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
}

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
  if (value >= 30 && value < 50) return 5;
  if (value >= 50 && value < 90) return 1;
  if (value >= 90 && value <= 175) return 5;
  return 1;
};

export function ParametersTable({
  selectedPatient,
  onParameterSaved,
}: ParametersTableProps) {
  const [selectedMode, setSelectedMode] = useState("DDD"); // current selected pacing mode
  const [hasChanges, setHasChanges] = useState(false); // true when any parameters have been changed

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
        step: getLowerRateLimitStep(patientParams.lowerRateLimit || 60),
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

  // Update parameter value and validity
  const updateParameter = (id: string, value: number) => {
    setParameters((prev) => {
      // Get current rate limits for cross-validation
      const currentLowerRate = prev.find((p) => p.id === "lowerRateLimit")?.value;
      const currentUpperRate = prev.find((p) => p.id === "upperRateLimit")?.value;

      return prev.map((param) => {
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
        
        return param;
      });
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
      let step: number =
        typeof param.step === "number"
          ? param.step
          : getLowerRateLimitStep(currentValue) || 1;
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
      let step: number =
        typeof param.step === "number"
          ? param.step
          : getLowerRateLimitStep(currentValue - 1) || 1;
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

  // Send parameters to pacemaker (deliverable 2)
  const handleSendToPacemaker = () => {
    if (!canSave || invalidCount > 0) return;
    console.log("Sending parameters to pacemaker:", parameters);
  };

  const invalidCount = parameters.filter((p) => p.isValid === false).length;
  const canSave =
    hasChanges &&
    invalidCount === 0 &&
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
        <Label className="text-sm font-medium text-gray-700">
          {param.name} {param.unit && `(${param.unit})`}
        </Label>
        <div className="relative flex items-center gap-2">
          <div className="flex-1 relative">
            <Input
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
      {invalidCount > 0 && (
        <Alert variant="destructive">
          <AlertCircle className="h-4 w-4" />
          <AlertDescription>
            Error invalid values. Lower Rate Limit cannot exceed Upper Rate Limit.
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
                      onClick={() => setSelectedMode(mode)}
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
                >
                  Save Changes
                </Button>

                <Button
                  onClick={handleSendToPacemaker}
                  disabled={!canSave}
                  className="w-full h-11 bg-gray-900 hover:bg-gray-800"
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
