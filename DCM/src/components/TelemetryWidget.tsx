import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Button } from "./ui/button";
import { Badge } from "./ui/badge";
import { Wifi, WifiOff, Power, AlertTriangle, RotateCcw } from "lucide-react";

interface TelemetryWidgetProps {
  connectionState: 'Connected' | 'Out of Range' | 'Noise' | 'Lost';
  onConnect: () => void;
  onDisconnect: () => void;
  onRetry: () => void;
  isConnecting: boolean;
}

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
          <Power className="h-5 w-5" />
          Telemetry Connection
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
          <Badge variant={isConnected ? "default" : "destructive"}>
            {connectionState}
          </Badge>
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

        {/* Range Information */}
        <div className="bg-muted/50 rounded-lg p-3">
          <div className="flex items-center gap-2 text-sm text-muted-foreground">
            <AlertTriangle className="h-4 w-4" />
            <span>Optimal wand range: 0-5 cm from device</span>
          </div>
        </div>
      </CardContent>
    </Card>
  );
}