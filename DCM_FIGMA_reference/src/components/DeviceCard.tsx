import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Badge } from "./ui/badge";
import { Battery, Clock, Wifi, WifiOff } from "lucide-react";

interface DeviceCardProps {
  model: string;
  serialNumber: string;
  lastInterrogation: string;
  batteryStatus: "BOL" | "ERN" | "ERT" | "ERP";
  isConnected: boolean;
  patientName: string;
}

const batteryColors = {
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

export function DeviceCard({
  model,
  serialNumber,
  lastInterrogation,
  batteryStatus,
  isConnected,
  patientName,
}: DeviceCardProps) {
  return (
    <Card className="w-full">
      <CardHeader className="pb-3">
        <div className="flex items-center justify-between">
          <CardTitle className="text-lg">{patientName}</CardTitle>
          <div className="flex items-center gap-2">
            {isConnected ? (
              <Wifi className="h-5 w-5 text-green-600" />
            ) : (
              <WifiOff className="h-5 w-5 text-gray-400" />
            )}
            <Badge variant={isConnected ? "default" : "secondary"}>
              {isConnected ? "Connected" : "Disconnected"}
            </Badge>
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
                  className={`w-3 h-3 rounded-full ${batteryColors[batteryStatus]}`}
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
