// EKG Viewer Component
// 
// Usage Example with Real Data:
// 
// const myChannelData = {
//   Atrial: [
//     { x: 0, y: 0 },
//     { x: 10, y: 5 },
//     { x: 20, y: 10 },
//     { x: 30, y: 5 },
//     { x: 40, y: 0 },
//     // ... more points
//   ],
//   Ventricular: [
//     { x: 0, y: 0 },
//     { x: 15, y: 8 },
//     { x: 30, y: 15 },
//     { x: 45, y: 8 },
//     { x: 60, y: 0 },
//     // ... more points
//   ],
//   ECG: [
//     { x: 0, y: 0 },
//     { x: 5, y: 3 },
//     // ... more points
//   ]
// };
//
// <EKGViewer 
//   isDeviceConnected={true} 
//   channelData={myChannelData}
// />

import { useState, useRef, useEffect } from "react";
import { Card, CardContent, CardHeader, CardTitle } from "./ui/card";
import { Button } from "./ui/button";
import { Input } from "./ui/input";
import { Badge } from "./ui/badge";
import { Slider } from "./ui/slider";
import { Switch } from "./ui/switch";
import { Label } from "./ui/label";
import { Alert, AlertDescription } from "./ui/alert";
import { Activity, Play, Pause, Printer, RotateCcw, ZoomIn, ZoomOut, Settings, Wifi, WifiOff } from "lucide-react";

interface EGMMarker {
  time: number;
  type: 'AS' | 'VS' | 'VP' | 'AP' | 'AR' | 'VR';
  timeSinceLast?: number;
}

interface DataPoint {
  x: number;
  y: number;
}

interface ChannelData {
  Atrial?: DataPoint[];
  Ventricular?: DataPoint[];
  ECG?: DataPoint[];
}

const markerColors = {
  AS: '#22c55e', // Atrial Sensed - green
  VS: '#0ea5e9', // Ventricular Sensed - blue  
  VP: '#8b5cf6', // Ventricular Paced - purple
  AP: '#f59e0b', // Atrial Paced - amber
  AR: '#ef4444', // Atrial Refractory - red
  VR: '#dc2626'  // Ventricular Refractory - red
};

interface EKGViewerProps {
  isDeviceConnected?: boolean;
  channelData?: ChannelData;
}

export function EKGViewer({ isDeviceConnected = false, channelData }: EKGViewerProps) {
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const [isStreaming, setIsStreaming] = useState(false);
  const [selectedChannels, setSelectedChannels] = useState(['Atrial', 'Ventricular']);
  const [gain, setGain] = useState([1]);
  const [timeScale, setTimeScale] = useState([1]);
  const [channelGains, setChannelGains] = useState({
    atrial: 1.0,
    ventricular: 1.0,
    ecg: 1.0
  });
  const [gainInputs, setGainInputs] = useState({
    atrial: '1.0',
    ventricular: '1.0',
    ecg: '1.0'
  });
  const [markers] = useState<EGMMarker[]>([
    { time: 100, type: 'AS', timeSinceLast: 850 },
    { time: 250, type: 'VP', timeSinceLast: 150 },
    { time: 400, type: 'VS', timeSinceLast: 150 },
    { time: 550, type: 'AS', timeSinceLast: 150 },
    { time: 700, type: 'VP', timeSinceLast: 150 }
  ]);

  const [scrollOffset, setScrollOffset] = useState(0);

  // Function to reset the view
  const handleResetView = () => {
    setScrollOffset(0);
  };

  // Fake test data 
  const fakeAtrialData: DataPoint[] = [
    { x: 0, y: 0 }, { x: 5, y: 2 }, { x: 10, y: 8 }, { x: 15, y: 15 }, { x: 20, y: 20 },
    { x: 25, y: 22 }, { x: 30, y: 20 }, { x: 35, y: 15 }, { x: 40, y: 8 }, { x: 45, y: 2 },
    { x: 50, y: 0 }, { x: 55, y: -1 }, { x: 60, y: 0 }, { x: 65, y: 0 }, { x: 70, y: 0 },
    { x: 75, y: 0 }, { x: 80, y: 0 }, { x: 85, y: 2 }, { x: 90, y: 8 }, { x: 95, y: 15 },
    { x: 100, y: 20 }, { x: 105, y: 22 }, { x: 110, y: 20 }, { x: 115, y: 15 }, { x: 120, y: 8 },
    { x: 125, y: 2 }, { x: 130, y: 0 }, { x: 135, y: -1 }, { x: 140, y: 0 }, { x: 145, y: 0 },
    { x: 150, y: 0 }, { x: 155, y: 0 }, { x: 160, y: 0 }, { x: 165, y: 2 }, { x: 170, y: 8 },
    { x: 175, y: 15 }, { x: 180, y: 20 }, { x: 185, y: 22 }, { x: 190, y: 20 }, { x: 195, y: 15 },
    { x: 200, y: 8 }, { x: 205, y: 2 }, { x: 210, y: 0 }, { x: 215, y: -1 }, { x: 220, y: 0 },
    { x: 225, y: 0 }, { x: 230, y: 0 }, { x: 235, y: 0 }, { x: 240, y: 0 }, { x: 245, y: 2 },
    { x: 250, y: 8 }, { x: 255, y: 15 }, { x: 260, y: 20 }, { x: 265, y: 22 }, { x: 270, y: 20 },
    { x: 275, y: 15 }, { x: 280, y: 8 }, { x: 285, y: 2 }, { x: 290, y: 0 }, { x: 295, y: -1 },
    { x: 300, y: 0 }, { x: 305, y: 0 }, { x: 310, y: 0 }, { x: 315, y: 0 }, { x: 320, y: 0 }
  ];

  const fakeVentricularData: DataPoint[] = [
    { x: 0, y: 0 }, { x: 5, y: 0 }, { x: 10, y: 0 }, { x: 15, y: 0 }, { x: 20, y: 0 },
    { x: 25, y: -5 }, { x: 30, y: -8 }, { x: 35, y: -5 }, { x: 40, y: 10 }, { x: 45, y: 30 },
    { x: 50, y: 45 }, { x: 55, y: 40 }, { x: 60, y: 20 }, { x: 65, y: -10 }, { x: 70, y: -12 },
    { x: 75, y: -5 }, { x: 80, y: 0 }, { x: 85, y: 3 }, { x: 90, y: 8 }, { x: 95, y: 12 },
    { x: 100, y: 13 }, { x: 105, y: 12 }, { x: 110, y: 8 }, { x: 115, y: 3 }, { x: 120, y: 0 },
    { x: 125, y: 0 }, { x: 130, y: 0 }, { x: 135, y: 0 }, { x: 140, y: 0 }, { x: 145, y: -5 },
    { x: 150, y: -8 }, { x: 155, y: -5 }, { x: 160, y: 10 }, { x: 165, y: 30 }, { x: 170, y: 45 },
    { x: 175, y: 40 }, { x: 180, y: 20 }, { x: 185, y: -10 }, { x: 190, y: -12 }, { x: 195, y: -5 },
    { x: 200, y: 0 }, { x: 205, y: 3 }, { x: 210, y: 8 }, { x: 215, y: 12 }, { x: 220, y: 13 },
    { x: 225, y: 12 }, { x: 230, y: 8 }, { x: 235, y: 3 }, { x: 240, y: 0 }, { x: 245, y: 0 },
    { x: 250, y: 0 }, { x: 255, y: 0 }, { x: 260, y: 0 }, { x: 265, y: -5 }, { x: 270, y: -8 },
    { x: 275, y: -5 }, { x: 280, y: 10 }, { x: 285, y: 30 }, { x: 290, y: 45 }, { x: 295, y: 40 },
    { x: 300, y: 20 }, { x: 305, y: -10 }, { x: 310, y: -12 }, { x: 315, y: -5 }, { x: 320, y: 0 }
  ];

  const fakeECGData: DataPoint[] = [
    { x: 0, y: 0 }, { x: 5, y: 3 }, { x: 10, y: 8 }, { x: 15, y: 10 }, { x: 20, y: 8 },
    { x: 25, y: 3 }, { x: 30, y: 0 }, { x: 35, y: 0 }, { x: 40, y: 0 }, { x: 45, y: -3 },
    { x: 50, y: -5 }, { x: 55, y: 5 }, { x: 60, y: 25 }, { x: 65, y: 30 }, { x: 70, y: 15 },
    { x: 75, y: -5 }, { x: 80, y: -8 }, { x: 85, y: -3 }, { x: 90, y: 0 }, { x: 95, y: 2 },
    { x: 100, y: 5 }, { x: 105, y: 10 }, { x: 110, y: 12 }, { x: 115, y: 10 }, { x: 120, y: 5 },
    { x: 125, y: 2 }, { x: 130, y: 0 }, { x: 135, y: 0 }, { x: 140, y: 0 }, { x: 145, y: 3 },
    { x: 150, y: 8 }, { x: 155, y: 10 }, { x: 160, y: 8 }, { x: 165, y: 3 }, { x: 170, y: 0 },
    { x: 175, y: 0 }, { x: 180, y: 0 }, { x: 185, y: -3 }, { x: 190, y: -5 }, { x: 195, y: 5 },
    { x: 200, y: 25 }, { x: 205, y: 30 }, { x: 210, y: 15 }, { x: 215, y: -5 }, { x: 220, y: -8 },
    { x: 225, y: -3 }, { x: 230, y: 0 }, { x: 235, y: 2 }, { x: 240, y: 5 }, { x: 245, y: 10 },
    { x: 250, y: 12 }, { x: 255, y: 10 }, { x: 260, y: 5 }, { x: 265, y: 2 }, { x: 270, y: 0 },
    { x: 275, y: 0 }, { x: 280, y: 0 }, { x: 285, y: 3 }, { x: 290, y: 8 }, { x: 295, y: 10 },
    { x: 300, y: 8 }, { x: 305, y: 3 }, { x: 310, y: 0 }, { x: 315, y: 0 }, { x: 320, y: 0 }
  ];

  const fakChannelData: ChannelData = {
    Atrial: fakeAtrialData,
    Ventricular: fakeVentricularData,
    ECG: fakeECGData
  };

  // Use fake data
  const dataToDisplay = channelData || fakChannelData;

  // Handle gain input changes with validation
  const handleGainInputChange = (channel: string, value: string) => {
    setGainInputs(prev => ({ ...prev, [channel]: value }));
    
    // Validate and apply gain
    const numValue = parseFloat(value);
    if (!isNaN(numValue) && numValue >= 0.1 && numValue <= 5.0) {
      setChannelGains(prev => ({ ...prev, [channel]: numValue }));
    }
  };

  // Real-time data plotting with actual (x,y) points
  useEffect(() => {
    if (!isStreaming) return;

    const canvas = canvasRef.current;
    if (!canvas) return;

    const ctx = canvas.getContext('2d');
    if (!ctx) return;

    // Set up high-DPI canvas for crisp rendering
    const dpr = window.devicePixelRatio || 1; // Adjust for display ratio
    const rect = canvas.getBoundingClientRect();
    
    canvas.width = rect.width * dpr;
    canvas.height = rect.height * dpr;
    
    ctx.scale(dpr, dpr);
    
    const displayWidth = rect.width;
    const displayHeight = rect.height;

    let animationId: number;

    const draw = () => {
      // Clear canvas
      ctx.fillStyle = '#000000';
      ctx.fillRect(0, 0, displayWidth, displayHeight);

      // Draw grid
      ctx.strokeStyle = '#333333';
      ctx.lineWidth = 1;
      
      // Vertical grid lines (time)
      for (let x = 0; x < displayWidth; x += 50) {
        ctx.beginPath();
        ctx.moveTo(x, 0);
        ctx.lineTo(x, displayHeight);
        ctx.stroke();
      }
      
      // Horizontal grid lines (amplitude)
      for (let y = 0; y < displayHeight; y += 30) {
        ctx.beginPath();
        ctx.moveTo(0, y);
        ctx.lineTo(displayWidth, y);
        ctx.stroke();
      }

      // Draw traces
      const traces = selectedChannels.length;
      const traceHeight = (displayHeight - 40) / traces;
      
      selectedChannels.forEach((channel, index) => {
        const yOffset = 20 + (index * traceHeight) + (traceHeight / 2);
        
        // Channel label
        ctx.fillStyle = '#ffffff';
        ctx.font = '12px monospace';
        ctx.fillText(channel, 10, yOffset - traceHeight/2 + 15);
        
        // Set color based on channel
        ctx.strokeStyle = channel === 'Atrial' ? '#22c55e' : channel === 'Ventricular' ? '#0ea5e9' : '#f59e0b';
        ctx.lineWidth = 2;
        ctx.beginPath();
        
        // Get data points for this channel
        const data = dataToDisplay?.[channel as keyof ChannelData];
        
        if (data && data.length > 0) {
          // Get the channel-specific gain
          const channelGain = channelGains[channel.toLowerCase() as keyof typeof channelGains];
          
          // Calculate the total width of the data in pixels
          const maxDataX = Math.max(...data.map(p => p.x));
          const dataWidth = maxDataX * timeScale[0];
          
          // Draw the data multiple times to create a seamless loop
          for (let repeatOffset = -dataWidth; repeatOffset < displayWidth + dataWidth; repeatOffset += dataWidth) {
            let isFirstPoint = true;
            
            data.forEach((point) => {
              // Apply time scale, scroll offset, and repeat offset for looping
              const x = (point.x * timeScale[0]) - (scrollOffset % dataWidth) + repeatOffset;
              
              // Apply both master gain and channel-specific gain
              const y = yOffset - (point.y * gain[0] * channelGain);
              
              // Only draw points that are visible on the canvas
              if (x >= 0 && x <= displayWidth) {
                if (isFirstPoint) {
                  ctx.moveTo(x, y);
                  isFirstPoint = false;
                } else {
                  ctx.lineTo(x, y);
                }
              }
            });
          }
        }
        // If no data, leave the channel blank (no fallback)
        
        ctx.stroke();
      });

      // Update scroll offset for continuous scrolling
      // Lower timeScale = slower scrolling (more spread out)
      // Higher timeScale = faster scrolling (more compressed)
      setScrollOffset(prev => prev + (2 / timeScale[0]));
      
      animationId = requestAnimationFrame(draw);
    };

    draw();

    return () => {
      if (animationId) {
        cancelAnimationFrame(animationId);
      }
    };
  }, [isStreaming, selectedChannels, gain, channelGains, timeScale, dataToDisplay, scrollOffset]);

  return (
    <Card className="w-full">
      <CardHeader className="pb-3">
        <div className="flex items-center justify-between">
          <CardTitle className="flex items-center gap-2">
            <Activity className="h-5 w-5" />
            Real-Time Electrogram
          </CardTitle>
          <div className="flex items-center gap-2">
          
          </div>
        </div>
      </CardHeader>
      <CardContent className="space-y-4">
        {/* Device Connection Status */}
        <Alert className={isDeviceConnected ? "border-green-200 bg-green-50 dark:border-green-800 dark:bg-green-950/20" : "border-yellow-200 bg-yellow-50 dark:border-yellow-800 dark:bg-yellow-950/20"}>
          <div className="flex items-center gap-2">
            {isDeviceConnected ? (
              <Wifi className="h-4 w-4 text-green-600" />
            ) : (
              <WifiOff className="h-4 w-4 text-yellow-600" />
            )}
          </div>
          <AlertDescription className={isDeviceConnected ? "text-green-800 dark:text-green-300" : "text-yellow-800 dark:text-yellow-300"}>
            {isDeviceConnected 
              ? "Connected to Pacemaker Device" 
              : "Pacemaker Device not Connected"
            }
          </AlertDescription>
        </Alert>

        {/* Controls */}
        <div className="flex items-center justify-between gap-4 p-3 bg-muted/50 rounded-lg">
          <div className="flex items-center gap-4">
            <Button
              onClick={() => setIsStreaming(!isStreaming)}
              variant={isStreaming ? "default" : "outline"}
              className="flex items-center gap-2"
            >
              {isStreaming ? <Pause className="h-4 w-4" /> : <Play className="h-4 w-4" />}
              {isStreaming ? 'Stop Stream' : 'Start Stream'}
            </Button>
            
            <Button variant="outline" size="icon" title="Reset View" onClick={handleResetView}>
              <RotateCcw className="h-4 w-4" />
            </Button>
          </div>
          
          <div className="flex items-center gap-4">
          
            
          </div>
        </div>

        {/* Channel and Gain Controls */}
        <div className="grid grid-cols-1 lg:grid-cols-2 gap-4">
          {/* Channel Selection */}
          <Card className="p-4">
            <div className="flex items-center gap-2 mb-3">
              <Settings className="h-4 w-4" />
              <Label className="font-medium">Channel Selection</Label>
            </div>
            <div className="space-y-3">
              {['Atrial', 'Ventricular', 'ECG'].map(channel => (
                <div key={channel} className="flex items-center justify-between">
                  <Badge
                    variant={selectedChannels.includes(channel) ? "default" : "outline"}
                    className="cursor-pointer min-w-[100px] justify-center"
                    onClick={() => {
                      setSelectedChannels(prev => 
                        prev.includes(channel) 
                          ? prev.filter(c => c !== channel)
                          : [...prev, channel]
                      );
                    }}
                  >
                    {channel}
                  </Badge>
                  <div className="flex items-center gap-2">
                    <Label className="text-xs">Gain:</Label>
                    <Input
                      type="number"
                      value={gainInputs[channel.toLowerCase() as keyof typeof gainInputs]}
                      onChange={(e) => handleGainInputChange(channel.toLowerCase(), e.target.value)}
                      className="w-16 h-8 text-xs"
                      min="0.1"
                      max="5.0"
                      step="0.1"
                      disabled={!selectedChannels.includes(channel)}
                    />
                    <span className="text-xs text-muted-foreground">x</span>
                  </div>
                </div>
              ))}
            </div>
          </Card>

          {/* Display Controls */}
          <Card className="p-4">
            <div className="flex items-center gap-2 mb-3">
              <ZoomIn className="h-4 w-4" />
              <Label className="font-medium">Display Controls</Label>
            </div>
            <div className="space-y-4">
              <div>
                <Label className="text-sm">Master Gain: {gain[0].toFixed(1)}x</Label>
                <div className="flex items-center gap-2 mt-2">
                  <ZoomOut className="h-4 w-4" />
                  <Slider
                    value={gain}
                    onValueChange={setGain}
                    min={0.1}
                    max={2}
                    step={0.1}
                    className="flex-1"
                  />
                  <ZoomIn className="h-4 w-4" />
                </div>
              </div>
              
              <div>
                <Label className="text-sm">Time Scale: {timeScale[0].toFixed(1)}x</Label>
                <div className="flex items-center gap-2 mt-2">
                  <span className="text-xs">Fast</span>
                  <Slider
                    value={timeScale}
                    onValueChange={setTimeScale}
                    min={0.1}
                    max={3}
                    step={0.1}
                    className="flex-1"
                  />
                  <span className="text-xs">Slow</span>
                </div>
              </div>
            </div>
          </Card>
        </div>

        {/* EGM Display */}
        <div className="border rounded-lg overflow-hidden bg-black">
          <canvas
            ref={canvasRef}
            style={{ 
              width: '100%', 
              height: '400px',
              display: 'block'
            }}
          />
        </div>

        {/* Marker Legend */}
        <div className="p-3 bg-muted/50 rounded-lg">
          <h4 className="font-medium mb-2">Event Markers</h4>
          <div className="grid grid-cols-2 md:grid-cols-6 gap-2 text-xs">
            {Object.entries(markerColors).map(([type, color]) => (
              <div key={type} className="flex items-center gap-2">
                <div className="w-3 h-3 rounded" style={{ backgroundColor: color }} />
                <span className="font-mono">{type}</span>
                <span className="text-muted-foreground">
                  {type === 'AS' ? 'Atrial Sensed' :
                   type === 'VS' ? 'Ventricular Sensed' :
                   type === 'VP' ? 'Ventricular Paced' :
                   type === 'AP' ? 'Atrial Paced' :
                   type === 'AR' ? 'Atrial Refractory' :
                   'Ventricular Refractory'}
                </span>
              </div>
            ))}
          </div>
        </div>
      </CardContent>
    </Card>
  );
}