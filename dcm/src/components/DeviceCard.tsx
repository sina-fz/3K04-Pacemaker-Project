import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Button } from "./ui/button";
import { Badge } from "./ui/badge";
import { Battery, Clock, Wifi, WifiOff, Power, AlertTriangle, RotateCcw } from "lucide-react";

// properties for device information card
interface DeviceCardProps {
    model: string;
    serialNumber: string;
    lastInterrogation: string;
    batteryStatus: "BOL" | "ERN" | "ERT" | "ERP";
    patientName: string;
}

// used to map tailwind colors and labels to battery status codes
const batteryStatusColors = {
    BOL: "bg-green-500",
    ERN: "bg-yellow-500",
    ERT: "bg-orange-500",
    ERP: "bg-red-500",
};
const batteryLabels = {
    BOL: "Beginning of Life",
    ERN: "Elective Replacement Near",
    ERT: "Elective Replacement Time",
    ERP: "End of Replacement Period",
};

// renders the device information card
export function DeviceCard({ model, serialNumber, lastInterrogation: lastSaved, batteryStatus, patientName }: DeviceCardProps) {
    return (
        <Card className="w-full">
        <CardHeader className="pb-3">
            <div className="flex items-center justify-between">
                <CardTitle className="text-lg">{patientName}</CardTitle>
                <div className="flex items-center gap-2">
                    <Wifi className="h-5 w-5 text-gray-400" />
                    <Badge variant="secondary">Status Placeholder</Badge>
                </div>
        </div>
        </CardHeader>
        <CardContent className="space-y-4">
        <div className="grid grid-cols-2 gap-4">
            <div>
                <p className="text-sm text-muted-foreground">Device Model</p>
                <p className="font-medium">{model}</p>
            </div>
            <div>
                <p className="text-sm text-muted-foreground">Serial Number</p>
                <p className="text-medium">{serialNumber}</p>
            </div>
        </div>

        <div className="flex items-center justify-between pt-2 border-t">
            <div className="flex items-center gap-2">
            <Battery className="h-4 w-4" />
            <div className="space-y-1">
                <div className="flex items-center gap-2">
                    <div
                    className={`w-3 h-3 rounded-full ${batteryStatusColors[batteryStatus]}`}
                    />
                <span className="text-sm font-medium">{batteryStatus}</span>
            </div>
            <p className="text-xs text-muted-foreground">
                {batteryLabels[batteryStatus]}
            </p>
        </div>
        </div>

        <div className="text-right">
            <div className="flex items-center gap-1 text-sm text-muted-foreground">
                <Clock className="h-4 w-4" />
                <span>Last Interrogation</span>
            </div>
            <p className="text-sm font-medium">{lastSaved}</p>
          </div>
        </div>
      </CardContent>
    </Card>
  );
}




// connection widget
interface TelemetryWidgetProps {
    connectionState: 'Connected' | 'Out of Range' | 'Noise' | 'Lost';
    onConnect: () => void;
    onDisconnect: () => void;
    onRetry: () => void;
    isConnecting: boolean;
}

// maps connection states to colors and icons
const stateColors = {
    'Connected': 'bg-green-500',
    'Out of Range': 'bg-yellow-500',
    'Noise': 'bg-orange-500',
    'Lost': 'bg-red-500'
};

const stateIcons = {
    'Connected': Wifi,
    'Out of Range': WifiOff,
    'Noise': AlertTriangle,
    'Lost': WifiOff
};

// renders the telemetry widget
export function TelemetryWidget({ 
    connectionState, 
    onConnect, 
    onDisconnect, 
    onRetry,
    isConnecting 
}: TelemetryWidgetProps) {
    const StateIcon = stateIcons[connectionState];
    const isConnected = connectionState === 'Connected';
  
    return (
        <Card className="w-full">
            <CardHeader className="pb-3">
                <CardTitle className="flex items-center gap-2">
                    Pacemaker Connection
                </CardTitle>
            </CardHeader>
            <CardContent className="space-y-4">
                {/* Connection Status */}
                <div className="flex items-center justify-between">
                    <div className="flex items-center gap-3">
                        <div className={`w-4 h-4 rounded-full ${stateColors[connectionState]} ${isConnected ? 'animate-pulse' : ''}`} />
                        <StateIcon className="h-5 w-5" />
                        <span className="font-medium">{connectionState}</span>
                    </div>
                </div>

                {/* Connection Controls */}
                <div className="flex gap-2 pt-2 border-t">
                    {!isConnected ? (
                        <>
                            <Button 
                                onClick={onConnect} 
                                disabled={isConnecting}
                                className="flex-1"
                                variant="default"
                            >
                                {isConnecting ? "Connecting..." : "Connect"}
                            </Button>
                            <Button 
                                onClick={onRetry} 
                                disabled={isConnecting}
                                variant="outline"
                                size="icon"
                            >
                                <RotateCcw className="h-4 w-4" />
                            </Button>
                        </>
                    ) : (
                        <Button 
                            onClick={onDisconnect} 
                            className="flex-1"
                            variant="outline"
                        >
                            Disconnect
                        </Button>
                    )}
                </div>
            </CardContent>
        </Card>
    );
}



// reference code dont delete yet 
/*
import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Badge } from "./ui/badge";
import { Battery, Clock, Wifi, WifiOff } from "lucide-react";

// landing page for device information
interface DeviceCardProps {
    model: string;
    serialNumber: string;
    lastInterrogation: string;
    batteryStatus: "BOL" | "ERN" | "ERT" | "ERP";
    patientName: string;
}

const batteryStatusColors = {
    BOL: "bg-green-500",
    ERN: "bg-yellow-500",
    ERT: "bg-orange-500",
    ERP: "bg-red-500",
};

const batteryLabels = {
    BOL: "Beginning of Life",
    ERN: "Elective Replacement Near",
    ERT: "Elective Replacement Time",
    ERP: "End of Replacement Period",
};

export function DeviceCard({ model, serialNumber, lastInterrogation, batteryStatus, patientName }: DeviceCardProps) {
    return (
        <Card className="w-full">
        <CardHeader className="pb-3">
            <div className="flex items-center justify-between">
                <CardTitle className="text-lg">{patientName}</CardTitle>
                <div className="flex items-center gap-2">
                    <Wifi className="h-5 w-5 text-gray-400" />
                    <Badge variant="secondary">Status Placeholder</Badge>
                </div>
        </div>
        </CardHeader>
        <CardContent className="space-y-4">
        <div className="grid grid-cols-2 gap-4">
            <div>
                <p className="text-sm text-muted-foreground">Device Model</p>
                <p className="font-medium">{model}</p>
            </div>
            <div>
                <p className="text-sm text-muted-foreground">Serial Number</p>
                <p className="font-mono text-sm">{serialNumber}</p>
            </div>
        </div>

        <div className="flex items-center justify-between pt-2 border-t">
            <div className="flex items-center gap-2">
            <Battery className="h-4 w-4" />
            <div className="space-y-1">
                <div className="flex items-center gap-2">
                    <div
                    className={`w-3 h-3 rounded-full ${batteryStatusColors[batteryStatus]}`}
                    />
                <span className="text-sm font-medium">{batteryStatus}</span>
            </div>
            <p className="text-xs text-muted-foreground">
                {batteryLabels[batteryStatus]}
            </p>
        </div>
        </div>

        <div className="text-right">
            <div className="flex items-center gap-1 text-sm text-muted-foreground">
                <Clock className="h-4 w-4" />
                <span>Last Interrogation</span>
            </div>
            <p className="text-sm font-medium">{lastInterrogation}</p>
          </div>
        </div>
      </CardContent>
    </Card>
  );
}



*/