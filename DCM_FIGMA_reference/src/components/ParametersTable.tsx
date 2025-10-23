import { useState, useEffect } from "react";
import { Button } from "./ui/button";
import { Input } from "./ui/input";
import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Label } from "./ui/label";
import { Alert, AlertDescription } from "./ui/alert";
import { Badge } from "./ui/badge";
import { AlertCircle, ChevronUp, ChevronDown } from "lucide-react";

interface Parameter {
  id: string;
  name: string;
  value: string | number;
  unit?: string;
  type: 'select' | 'number' | 'text';
  options?: string[];
  min?: number;
  max?: number;
  step?: number | 'custom';
  isDirty?: boolean;
  isValid?: boolean;
  range?: string;
}

interface ParametersSectionProps {
  selectedPatient: any;
  onParametersSaved: (parameters: any) => void;
}

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

// Helper function to get the correct step value for Lower Rate Limit
const getLowerRateLimitStep = (value: number): number => {
  if (value < 50) return 5;
  if (value <= 90) return 1;
  return 5;
};

export function ParametersTable({ selectedPatient, onParametersSaved }: ParametersSectionProps) {
  const [selectedMode, setSelectedMode] = useState('DDD');
  const [hasChanges, setHasChanges] = useState(false);
  
  // Initialize parameters based on selected patient
  const getInitialParameters = (): Parameter[] => {
    const patientParams = selectedPatient?.parameters || {};
    return [
      // Basic Rate Parameters
      { 
        id: 'lowerRateLimit', 
        name: 'Lower Rate Limit', 
        value: patientParams.lowerRateLimit || 60, 
        unit: 'ppm',
        type: 'number', 
        min: 30, 
        max: 175,
        step: 'custom', // Custom step based on value
        range: '30-175 ppm (5 ppm: 30-50, 1 ppm: 50-90, 5 ppm: 90-175)',
        isValid: true 
      },
      { 
        id: 'upperRateLimit', 
        name: 'Upper Rate Limit', 
        value: patientParams.upperRateLimit || 120, 
        unit: 'ppm',
        type: 'number', 
        min: 50, 
        max: 175,
        step: 5,
        range: '50-175 ppm, 5 ppm increments',
        isValid: true 
      },
      { 
        id: 'maximumSensorRate', 
        name: 'Maximum Sensor Rate', 
        value: patientParams.maximumSensorRate || 120, 
        unit: 'ppm',
        type: 'number', 
        min: 50, 
        max: 175,
        step: 5,
        range: '50-175 ppm, 5 ppm increments',
        isValid: true 
      },

      // AV Delay Parameters
      { 
        id: 'fixedAVDelay', 
        name: 'Fixed AV Delay', 
        value: patientParams.fixedAVDelay || 150, 
        unit: 'ms',
        type: 'number', 
        min: 70, 
        max: 300,
        step: 10,
        range: '70-300 ms, 10 ms increments',
        isValid: true 
      },
      { 
        id: 'dynamicAVDelay', 
        name: 'Dynamic AV Delay', 
        value: patientParams.dynamicAVDelay || 'Off', 
        type: 'select',
        options: ['Off', 'On'],
        range: 'Off or On',
        isValid: true 
      },
      { 
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
      { 
        id: 'sensedAVDelayOffset', 
        name: 'Sensed AV Delay Offset', 
        value: patientParams.sensedAVDelayOffset || 'Off', 
        type: 'select',
        options: ['Off', '-10', '-20', '-30', '-40', '-50', '-60', '-70', '-80', '-90', '-100'],
        range: 'Off or -10 to -100 ms in -10 ms steps',
        isValid: true 
      },

      // Amplitude Parameters (Regulated)
      { 
        id: 'atrialAmplitudeRegulated', 
        name: 'Atrial Amplitude (Regulated)', 
        value: patientParams.atrialAmplitudeRegulated || 3.5, 
        unit: 'V',
        type: 'select',
        options: ['Off', '0.5', '0.6', '0.7', '0.8', '0.9', '1.0', '1.1', '1.2', '1.3', '1.4', '1.5', '1.6', '1.7', '1.8', '1.9', '2.0', '2.1', '2.2', '2.3', '2.4', '2.5', '2.6', '2.7', '2.8', '2.9', '3.0', '3.1', '3.2', '3.5', '4.0', '4.5', '5.0', '5.5', '6.0', '6.5', '7.0'],
        range: 'Off, 0.5-3.2 V (0.1 V), 3.5-7.0 V (0.5 V)',
        isValid: true 
      },
      { 
        id: 'ventricularAmplitudeRegulated', 
        name: 'Ventricular Amplitude (Regulated)', 
        value: patientParams.ventricularAmplitudeRegulated || 3.5, 
        unit: 'V',
        type: 'select',
        options: ['Off', '0.5', '0.6', '0.7', '0.8', '0.9', '1.0', '1.1', '1.2', '1.3', '1.4', '1.5', '1.6', '1.7', '1.8', '1.9', '2.0', '2.1', '2.2', '2.3', '2.4', '2.5', '2.6', '2.7', '2.8', '2.9', '3.0', '3.1', '3.2', '3.5', '4.0', '4.5', '5.0', '5.5', '6.0', '6.5', '7.0'],
        range: 'Off, 0.5-3.2 V (0.1 V), 3.5-7.0 V (0.5 V)',
        isValid: true 
      },

      // Amplitude Parameters (Unregulated)
      { 
        id: 'atrialAmplitudeUnregulated', 
        name: 'Atrial Amplitude (Unregulated)', 
        value: patientParams.atrialAmplitudeUnregulated || 3.75, 
        unit: 'V',
        type: 'select',
        options: ['Off', '1.25', '2.5', '3.75', '5.0'],
        range: 'Off, 1.25, 2.5, 3.75, 5.0 V',
        isValid: true 
      },
      { 
        id: 'ventricularAmplitudeUnregulated', 
        name: 'Ventricular Amplitude (Unregulated)', 
        value: patientParams.ventricularAmplitudeUnregulated || 3.75, 
        unit: 'V',
        type: 'select',
        options: ['Off', '1.25', '2.5', '3.75', '5.0'],
        range: 'Off, 1.25, 2.5, 3.75, 5.0 V',
        isValid: true 
      },

      // Pulse Width Parameters
      { 
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
      { 
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

      // Sensitivity Parameters
      { 
        id: 'atrialSensitivity', 
        name: 'Atrial Sensitivity', 
        value: patientParams.atrialSensitivity || 0.75, 
        unit: 'mV',
        type: 'select',
        options: ['0.25', '0.5', '0.75', '1.0', '1.5', '2.0', '2.5', '3.0', '3.5', '4.0', '4.5', '5.0', '5.5', '6.0', '6.5', '7.0', '7.5', '8.0', '8.5', '9.0', '9.5', '10.0'],
        range: '0.25, 0.5, 0.75, 1.0-10 mV (0.5 mV increments)',
        isValid: true 
      },
      { 
        id: 'ventricularSensitivity', 
        name: 'Ventricular Sensitivity', 
        value: patientParams.ventricularSensitivity || 2.5, 
        unit: 'mV',
        type: 'select',
        options: ['0.25', '0.5', '0.75', '1.0', '1.5', '2.0', '2.5', '3.0', '3.5', '4.0', '4.5', '5.0', '5.5', '6.0', '6.5', '7.0', '7.5', '8.0', '8.5', '9.0', '9.5', '10.0'],
        range: '0.25, 0.5, 0.75, 1.0-10 mV (0.5 mV increments)',
        isValid: true 
      },

      // Refractory Period Parameters
      { 
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
      { 
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
      { 
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
      { 
        id: 'pvarpExtension', 
        name: 'PVARP Extension', 
        value: patientParams.pvarpExtension || 'Off', 
        type: 'select',
        options: ['Off', '50', '100', '150', '200', '250', '300', '350', '400'],
        range: 'Off or 50-400 ms in 50 ms increments',
        isValid: true 
      },

      // Rate Control Parameters
      { 
        id: 'hysteresisRateLimit', 
        name: 'Hysteresis Rate Limit', 
        value: patientParams.hysteresisRateLimit || 'Off', 
        type: 'select',
        options: ['Off', '30', '35', '40', '45', '50', '55', '60', '65', '70', '75', '80', '85', '90', '95', '100', '105', '110', '115', '120', '125', '130', '135', '140', '145', '150', '155', '160', '165', '170', '175'],
        range: 'Off or same as Lower Rate Limit',
        isValid: true 
      },
      { 
        id: 'rateSmoothing', 
        name: 'Rate Smoothing', 
        value: patientParams.rateSmoothing || 'Off', 
        type: 'select',
        options: ['Off', '3%', '6%', '9%', '12%', '15%', '18%', '21%', '25%'],
        range: 'Off, 3, 6, 9, 12, 15, 18, 21, 25%',
        isValid: true 
      },

      // ATR Parameters
      { 
        id: 'atrMode', 
        name: 'ATR Mode', 
        value: patientParams.atrMode || 'Off', 
        type: 'select',
        options: ['Off', 'On'],
        range: 'On or Off',
        isValid: true 
      },
      { 
        id: 'atrDuration', 
        name: 'ATR Duration', 
        value: patientParams.atrDuration || 20, 
        unit: 'cc',
        type: 'select',
        options: ['10', '20', '40', '60', '80', '100', '200', '300', '400', '500', '600', '700', '800', '900', '1000', '1100', '1200', '1300', '1400', '1500', '1600', '1700', '1800', '1900', '2000'],
        range: '10, 20-80, 100-2000 cardiac cycles',
        isValid: true 
      },
      { 
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

      // Blanking Parameters
      { 
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

      // Activity/Rate Response Parameters
      { 
        id: 'activityThreshold', 
        name: 'Activity Threshold', 
        value: patientParams.activityThreshold || 'Med', 
        type: 'select',
        options: ['V-Low', 'Low', 'Med-Low', 'Med', 'Med-High', 'High', 'V-High'],
        range: 'V-Low, Low, Med-Low, Med, Med-High, High, V-High',
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

  const [parameters, setParameters] = useState<Parameter[]>(getInitialParameters);

  // Update parameters when patient changes
  useEffect(() => {
    setParameters(getInitialParameters());
    setHasChanges(false);
  }, [selectedPatient]);

  const modes = ['AAT', 'VVT', 'AOO', 'AAI', 'VOO', 'VVI', 'VDD', 'DOO', 'DDI', 'DDD', 'AOOR', 'AAIR', 'VOOR', 'VVIR', 'VDDR', 'DOOR', 'DDIR', 'DDDR'];

  const updateParameter = (id: string, value: string | number) => {
    setParameters(prev => prev.map(param => {
      if (param.id === id) {
        const numValue = param.type === 'number' ? Number(value) : value;
        
        let isValid = true;
        if (param.type === 'number') {
          // Check if value is empty, NaN, or out of range
          if (value === '' || isNaN(numValue as number)) {
            isValid = false;
          } else if (param.min !== undefined && numValue < param.min) {
            isValid = false;
          } else if (param.max !== undefined && numValue > param.max) {
            isValid = false;
          }
        }
        
        return {
          ...param,
          value: numValue,
          isDirty: true,
          isValid
        };
      }
      return param;
    }));
    setHasChanges(true);
  };

  const incrementParameter = (param: Parameter) => {
    if (param.type === 'select' && param.options) {
      const currentIndex = param.options.indexOf(String(param.value));
      if (currentIndex < param.options.length - 1) {
        updateParameter(param.id, param.options[currentIndex + 1]);
      }
    } else if (param.type === 'number') {
      const currentValue = Number(param.value);
      let step: number;
      
      if (param.step === 'custom' && param.id === 'lowerRateLimit') {
        step = getLowerRateLimitStep(currentValue);
      } else {
        step = param.step as number;
      }
      
      const newValue = currentValue + step;
      if (param.max === undefined || newValue <= param.max) {
        updateParameter(param.id, newValue);
      }
    }
  };

  const decrementParameter = (param: Parameter) => {
    if (param.type === 'select' && param.options) {
      const currentIndex = param.options.indexOf(String(param.value));
      if (currentIndex > 0) {
        updateParameter(param.id, param.options[currentIndex - 1]);
      }
    } else if (param.type === 'number') {
      const currentValue = Number(param.value);
      let step: number;
      
      if (param.step === 'custom' && param.id === 'lowerRateLimit') {
        step = getLowerRateLimitStep(currentValue - 1);
      } else {
        step = param.step as number;
      }
      
      const newValue = currentValue - step;
      if (param.min === undefined || newValue >= param.min) {
        updateParameter(param.id, newValue);
      }
    }
  };

  const handleResetToNominal = () => {
    // Define nominal values
    const nominalValues: Record<string, string | number> = {
      lowerRateLimit: 60,
      upperRateLimit: 120,
      maximumSensorRate: 120,
      fixedAVDelay: 150,
      dynamicAVDelay: 'Off',
      minimumDynamicAVDelay: 50,
      sensedAVDelayOffset: 'Off',
      atrialAmplitudeRegulated: 3.5,
      ventricularAmplitudeRegulated: 3.5,
      atrialAmplitudeUnregulated: 3.75,
      ventricularAmplitudeUnregulated: 3.75,
      atrialPulseWidth: 0.2,
      ventricularPulseWidth: 0.2,
      atrialSensitivity: 0.75,
      ventricularSensitivity: 2.5,
      ventricularRefractoryPeriod: 320,
      atrialRefractoryPeriod: 250,
      pvarp: 250,
      pvarpExtension: 'Off',
      hysteresisRateLimit: 'Off',
      rateSmoothing: 'Off',
      atrMode: 'Off',
      atrDuration: 20,
      atrFallbackTime: 1,
      ventricularBlanking: 40,
      activityThreshold: 'Med',
      reactionTime: 30,
      responseFactor: 8,
      recoveryTime: 5
    };

    // Reset all parameters to nominal values
    setParameters(prev => prev.map(param => ({
      ...param,
      value: nominalValues[param.id] ?? param.value,
      isDirty: true,
      isValid: true
    })));
    setHasChanges(true);
  };

  const handleSaveChanges = () => {
    // Prevent saving if there are any invalid parameters
    if (!canSave || invalidCount > 0) return;
    
    const parameterValues = parameters.reduce((acc, param) => {
      acc[param.id] = param.value;
      return acc;
    }, {} as any);
    
    onParametersSaved(parameterValues);
    setParameters(prev => prev.map(p => ({ ...p, isDirty: false })));
    setHasChanges(false);
  };

  const handleSendToPacemaker = () => {
    // Prevent sending if there are any invalid parameters
    if (!canSave || invalidCount > 0) return;
    
    console.log("Sending parameters to pacemaker:", parameters);
    console.log("Sending to Simulink...");
    // Simulate sending to pacemaker/Simulink
  };

  const invalidCount = parameters.filter(p => p.isValid === false).length;
  const canSave = hasChanges && invalidCount === 0 && parameters.every(p => p.isValid !== false);

  const getStepValue = (param: Parameter): number | undefined => {
    if (param.type !== 'number') return undefined;
    
    if (param.step === 'custom' && param.id === 'lowerRateLimit') {
      return getLowerRateLimitStep(Number(param.value));
    }
    
    return param.step as number;
  };

  const canIncrement = (param: Parameter): boolean => {
    if (param.type === 'select' && param.options) {
      const currentIndex = param.options.indexOf(String(param.value));
      return currentIndex < param.options.length - 1;
    } else if (param.type === 'number') {
      const currentValue = Number(param.value);
      let step: number;
      
      if (param.step === 'custom' && param.id === 'lowerRateLimit') {
        step = getLowerRateLimitStep(currentValue);
      } else {
        step = param.step as number;
      }
      
      return param.max === undefined || (currentValue + step) <= param.max;
    }
    return false;
  };

  const canDecrement = (param: Parameter): boolean => {
    if (param.type === 'select' && param.options) {
      const currentIndex = param.options.indexOf(String(param.value));
      return currentIndex > 0;
    } else if (param.type === 'number') {
      const currentValue = Number(param.value);
      let step: number;
      
      if (param.step === 'custom' && param.id === 'lowerRateLimit') {
        step = getLowerRateLimitStep(currentValue - 1);
      } else {
        step = param.step as number;
      }
      
      return param.min === undefined || (currentValue - step) >= param.min;
    }
    return false;
  };

  const ParameterInputField = ({ param }: { param: Parameter }) => {
    return (
      <div className="space-y-2">
        <Label className="text-sm font-medium text-gray-700">
          {param.name} {param.unit && `(${param.unit})`}
        </Label>
        <div className="relative flex items-center gap-2">
          <div className="flex-1 relative">
            <Input
              value={param.value}
              onChange={(e) => updateParameter(param.id, e.target.value)}
              type={param.type === 'number' ? 'number' : 'text'}
              step={getStepValue(param)}
              readOnly={param.type === 'select'}
              className={`h-11 text-center ${param.isValid === false ? 'border-red-500 bg-red-50' : param.isDirty ? 'border-blue-500 bg-blue-50' : 'bg-gray-50'}`}
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
              onClick={() => incrementParameter(param)}
              disabled={!canIncrement(param)}
            >
              <ChevronUp className="h-3 w-3" />
            </Button>
            <Button
              variant="outline"
              size="sm"
              className="h-5 w-8 p-0"
              onClick={() => decrementParameter(param)}
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
        <h1 className="text-3xl font-semibold text-gray-900">Device Parameters</h1>
        <p className="text-gray-600">Configure pacemaker parameters</p>
      </div>

      {/* Validation Alerts */}
      {invalidCount > 0 && (
        <Alert variant="destructive">
          <AlertCircle className="h-4 w-4" />
          <AlertDescription>
            {invalidCount} parameter(s) have invalid values. Please correct them before saving.
          </AlertDescription>
        </Alert>
      )}

      <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">
        {/* Left Column - Parameter Sections */}
        <div className="lg:col-span-2 space-y-6">
          {/* Basic Rate Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                Basic Rate Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'lowerRateLimit')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'upperRateLimit')!} />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'maximumSensorRate')!} />
              </div>
            </CardContent>
          </Card>

          {/* AV Delay Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                AV Delay Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'fixedAVDelay')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'dynamicAVDelay')!} />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'minimumDynamicAVDelay')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'sensedAVDelayOffset')!} />
              </div>
            </CardContent>
          </Card>

          {/* Amplitude Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                Amplitude Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="space-y-2">
                <h3 className="font-semibold text-sm text-gray-700">Regulated</h3>
                <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                  <ParameterInputField param={parameters.find(p => p.id === 'atrialAmplitudeRegulated')!} />
                  <ParameterInputField param={parameters.find(p => p.id === 'ventricularAmplitudeRegulated')!} />
                </div>
              </div>
              <div className="space-y-2">
                <h3 className="font-semibold text-sm text-gray-700">Unregulated</h3>
                <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                  <ParameterInputField param={parameters.find(p => p.id === 'atrialAmplitudeUnregulated')!} />
                  <ParameterInputField param={parameters.find(p => p.id === 'ventricularAmplitudeUnregulated')!} />
                </div>
              </div>
            </CardContent>
          </Card>

          {/* Pulse Width Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                Pulse Width Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'atrialPulseWidth')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'ventricularPulseWidth')!} />
              </div>
            </CardContent>
          </Card>

          {/* Sensitivity Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                Sensitivity Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'atrialSensitivity')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'ventricularSensitivity')!} />
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
                <ParameterInputField param={parameters.find(p => p.id === 'ventricularRefractoryPeriod')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'atrialRefractoryPeriod')!} />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'pvarp')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'pvarpExtension')!} />
              </div>
            </CardContent>
          </Card>

          {/* Rate Control Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                Rate Control Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'hysteresisRateLimit')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'rateSmoothing')!} />
              </div>
            </CardContent>
          </Card>

          {/* ATR Parameters */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                ATR Parameters
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'atrMode')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'atrDuration')!} />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'atrFallbackTime')!} />
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
                <ParameterInputField param={parameters.find(p => p.id === 'ventricularBlanking')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'activityThreshold')!} />
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
                <ParameterInputField param={parameters.find(p => p.id === 'reactionTime')!} />
                <ParameterInputField param={parameters.find(p => p.id === 'responseFactor')!} />
              </div>
              <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                <ParameterInputField param={parameters.find(p => p.id === 'recoveryTime')!} />
              </div>
            </CardContent>
          </Card>
        </div>

        {/* Right Column - Controls */}
        <div className="space-y-6">
          {/* Parameter Controls */}
          <Card>
            <CardHeader className="pb-4">
              <CardTitle className="text-xl">
                Parameter Controls
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-6">
              {/* Pacing Mode Selection */}
              <div className="space-y-3">
                <Label className="text-sm font-medium text-gray-700">Pacing Mode</Label>
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
                <Label className="text-sm font-medium text-gray-700">Status</Label>
                <div className="space-y-2">
                  <div className="flex items-center justify-between">
                    <span className="text-sm">Changes</span>
                    <Badge variant={hasChanges ? "destructive" : "secondary"}>
                      {hasChanges ? 'Unsaved' : 'Saved'}
                    </Badge>
                  </div>
                  <div className="flex items-center justify-between">
                    <span className="text-sm">Validation</span>
                    <Badge variant={invalidCount > 0 ? "destructive" : "default"}>
                      {invalidCount > 0 ? `${invalidCount} errors` : 'Valid'}
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
