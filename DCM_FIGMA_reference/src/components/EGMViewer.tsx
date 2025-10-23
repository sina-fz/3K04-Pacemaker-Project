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

const markerColors = {
  AS: '#22c55e', // Atrial Sensed - green
  VS: '#0ea5e9', // Ventricular Sensed - blue  
  VP: '#8b5cf6', // Ventricular Paced - purple
  AP: '#f59e0b', // Atrial Paced - amber
  AR: '#ef4444', // Atrial Refractory - red
  VR: '#dc2626'  // Ventricular Refractory - red
};

export function EGMViewer() {
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const [isStreaming, setIsStreaming] = useState(false);
  const [selectedChannels, setSelectedChannels] = useState(['Atrial', 'Ventricular']);
  const [gain, setGain] = useState([1]);
  const [timeScale, setTimeScale] = useState([1]);
  const [autoReconnect, setAutoReconnect] = useState(true);
  const [isConnectedToSimulink, setIsConnectedToSimulink] = useState(false);
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

  // Simulate Simulink connection status
  useEffect(() => {
    const interval = setInterval(() => {
      // Randomly toggle connection to simulate real behavior
      setIsConnectedToSimulink(prev => Math.random() > 0.1 ? true : prev);
    }, 5000);

    return () => clearInterval(interval);
  }, []);

  // Handle gain input changes with validation
  const handleGainInputChange = (channel: string, value: string) => {
    setGainInputs(prev => ({ ...prev, [channel]: value }));
    
    // Validate and apply gain
    const numValue = parseFloat(value);
    if (!isNaN(numValue) && numValue >= 0.1 && numValue <= 5.0) {
      setGain([numValue]);
    }
  };

  // Real-time data from Simulink (or simulated)
  useEffect(() => {
    if (!isStreaming) return;

    const canvas = canvasRef.current;
    if (!canvas) return;

    const ctx = canvas.getContext('2d');
    if (!ctx) return;

    let animationId: number;
    let time = 0;

    const draw = () => {
      // Clear canvas
      ctx.fillStyle = '#000000';
      ctx.fillRect(0, 0, canvas.width, canvas.height);

      // Draw grid
      ctx.strokeStyle = '#333333';
      ctx.lineWidth = 1;
      
      // Vertical grid lines (time)
      for (let x = 0; x < canvas.width; x += 50) {
        ctx.beginPath();
        ctx.moveTo(x, 0);
        ctx.lineTo(x, canvas.height);
        ctx.stroke();
      }
      
      // Horizontal grid lines (amplitude)
      for (let y = 0; y < canvas.height; y += 30) {
        ctx.beginPath();
        ctx.moveTo(0, y);
        ctx.lineTo(canvas.width, y);
        ctx.stroke();
      }

      // Draw traces
      const traces = selectedChannels.length;
      const traceHeight = (canvas.height - 40) / traces;
      
      selectedChannels.forEach((channel, index) => {
        const yOffset = 20 + (index * traceHeight) + (traceHeight / 2);
        
        // Channel label
        ctx.fillStyle = '#ffffff';
        ctx.font = '12px monospace';
        ctx.fillText(channel, 10, yOffset - traceHeight/2 + 15);
        
        // Simulate EGM waveform
        ctx.strokeStyle = channel === 'Atrial' ? '#22c55e' : channel === 'Ventricular' ? '#0ea5e9' : '#f59e0b';
        ctx.lineWidth = 2;
        ctx.beginPath();
        
        for (let x = 0; x < canvas.width; x += 2) {
          const t = (time + x) * 0.01;
          let y = yOffset;
          
          // Generate realistic EGM-like waveform
          if (channel === 'Atrial') {
            y += Math.sin(t * 2) * 20 * gain[0] + Math.random() * 5;
          } else if (channel === 'Ventricular') {
            y += Math.sin(t * 1.5) * 30 * gain[0] + Math.cos(t * 3) * 10 + Math.random() * 5;
          } else {
            y += Math.sin(t) * 15 * gain[0] + Math.random() * 3;
          }
          
          if (x === 0) {
            ctx.moveTo(x, y);
          } else {
            ctx.lineTo(x, y);
          }
        }
        ctx.stroke();
      });

      // Draw markers
      markers.forEach(marker => {
        const x = (marker.time * timeScale[0]) % canvas.width;
        ctx.fillStyle = markerColors[marker.type];
        ctx.fillRect(x - 1, 0, 3, canvas.height);
        
        // Marker label
        ctx.fillStyle = '#ffffff';
        ctx.font = '10px monospace';
        ctx.fillText(marker.type, x + 5, 15);
        
        if (marker.timeSinceLast) {
          ctx.fillText(`${marker.timeSinceLast}ms`, x + 5, 30);
        }
      });

      time += timeScale[0];
      animationId = requestAnimationFrame(draw);
    };

    draw();

    return () => {
      if (animationId) {
        cancelAnimationFrame(animationId);
      }
    };
  }, [isStreaming, selectedChannels, gain, timeScale, markers]);

  return (
    <Card className="w-full">
      <CardHeader className="pb-3">
        <div className="flex items-center justify-between">
          <CardTitle className="flex items-center gap-2">
            <Activity className="h-5 w-5" />
            Real-Time Electrogram
          </CardTitle>
          <div className="flex items-center gap-2">
            <Badge variant={isStreaming ? "default" : "secondary"} className="flex items-center gap-1">
              <div className={`w-2 h-2 rounded-full ${isStreaming ? 'bg-green-500 animate-pulse' : 'bg-gray-400'}`} />
              {isStreaming ? 'Streaming' : 'Stopped'}
            </Badge>
          </div>
        </div>
      </CardHeader>
      <CardContent className="space-y-4">
        {/* Simulink Connection Status */}
        <Alert className={isConnectedToSimulink ? "border-green-200 bg-green-50 dark:border-green-800 dark:bg-green-950/20" : "border-yellow-200 bg-yellow-50 dark:border-yellow-800 dark:bg-yellow-950/20"}>
          <div className="flex items-center gap-2">
            {isConnectedToSimulink ? (
              <Wifi className="h-4 w-4 text-green-600" />
            ) : (
              <WifiOff className="h-4 w-4 text-yellow-600" />
            )}
          </div>
          <AlertDescription className={isConnectedToSimulink ? "text-green-800 dark:text-green-300" : "text-yellow-800 dark:text-yellow-300"}>
            {isConnectedToSimulink 
              ? "Connected to Simulink - Real-time data available" 
              : "Simulink connection not available - Using simulated data"
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
            
            <Button variant="outline" size="icon" title="Reset View">
              <RotateCcw className="h-4 w-4" />
            </Button>
            
            <Button variant="outline" size="icon" title="Print Strip">
              <Printer className="h-4 w-4" />
            </Button>
          </div>
          
          <div className="flex items-center gap-4">
            <div className="flex items-center gap-2">
              <Switch
                id="auto-reconnect"
                checked={autoReconnect}
                onCheckedChange={setAutoReconnect}
              />
              <Label htmlFor="auto-reconnect" className="text-sm">Auto-reconnect</Label>
            </div>
            
            <Badge variant={isConnectedToSimulink ? "default" : "secondary"} className="flex items-center gap-1">
              <div className={`w-2 h-2 rounded-full ${isConnectedToSimulink ? 'bg-green-500' : 'bg-yellow-500'}`} />
              {isConnectedToSimulink ? 'Simulink' : 'Simulated'}
            </Badge>
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
                  <span className="text-xs">Slow</span>
                  <Slider
                    value={timeScale}
                    onValueChange={setTimeScale}
                    min={0.1}
                    max={3}
                    step={0.1}
                    className="flex-1"
                  />
                  <span className="text-xs">Fast</span>
                </div>
              </div>
            </div>
          </Card>
        </div>

        {/* EGM Display */}
        <div className="border rounded-lg overflow-hidden bg-black">
          <canvas
            ref={canvasRef}
            width={800}
            height={400}
            className="w-full h-auto"
            style={{ maxHeight: '400px' }}
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