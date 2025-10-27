# DCM (Device Control Monitor)

A React + TypeScript single-page app for a pacemaker monitoring prototype. It provides a login/create-account flow, a patient dashboard with tabs (Connection, Parameters, Strip Chart, Reports, About), and simulated device telemetry. Data is persisted locally using `localStorage` for easy demos.

## Features

- Login and create account (client-side; persisted to `localStorage`)
- One user → one patient data model (device info + parameters)
- Tabbed interface:
  - Device Connection: account + device info, connect/disconnect/retry, live status
  - Parameters: view/edit/sync pacemaker parameters
  - Strip Chart (EGM): placeholder viewer component
  - Reports: printable reports scaffold
  - About: utilities page (user admin list with delete)
- Visual status in header: current user, live clock, connection badge + icon
- UI kit using shadcn-style components over Radix + Tailwind
- Icons via `lucide-react`

## Tech Stack

- Framework: React 18
- Language: TypeScript (TS/TSX)
- Bundler/Dev: Vite
- UI primitives: Radix UI (`@radix-ui/react-*`)
- UI patterns: shadcn-style components (in `src/components/ui`)
- Styling: Tailwind CSS utility classes (via project styles)
- Icons: `lucide-react`
- Charts: `recharts` (available), EKG viewer component (app-specific)
- Persistence: `localStorage`

## Project Structure

```
DCM/
  index.html                 # App shell (root <div id="root" />)
  package.json               # Scripts and deps
  vite.config.ts             # Vite config
  images/                    # Static images
  imports/                   # Extra TS/TSX assets for charts/icons
    Parameters.tsx
    svg-km06274vuy.ts
  src/
    main.tsx                 # React entry (createRoot + <App />)
    index.css                # Global styles (Tailwind entry)
    App.tsx                  # Main app page (auth + dashboard + tabs)
    components/
      AboutPage.tsx          # About / utilities (user list + delete)
      CreateUserLogin.tsx    # Create-account form
      DeviceCard.tsx         # TelemetryWidget (connect/disconnect)
      EKGViewer.tsx          # Strip chart placeholder/viewer
      ParametersTable.tsx    # Parameters editor
      PrintedReports.tsx     # Reports panel scaffold
      UserLogin.tsx          # Login form
      ui/                    # shadcn-style UI wrappers over Radix
        button.tsx, card.tsx, dialog.tsx, tabs.tsx, ...
  styles/
    globals.css              # Theme variables and base styles
```

## Getting Started

Prereqs:

- Node.js 20+ (recommended). Vite v6 runs on Node 18+, but newer Vite versions may require 20. If you see Node warnings, update Node.
- npm (ships with Node). On Windows, commands below use PowerShell syntax.

Install dependencies:

```powershell
cd "C:\Users\akash\Documents\3K04-Pacemaker-Project\DCM"
npm install
```

Run the dev server:

```powershell
npm run dev
```

- Open the printed URL (usually http://localhost:5173)

Build for production:

```powershell
npm run build
```

- Output goes to `dist/`

## NPM Scripts

From `package.json`:

- `npm run dev` → start Vite dev server
- `npm run build` → build production bundle with Vite

## Application Architecture

### Data Models

```ts
interface Patient {
  id: string;
  name: string;
  dateOfBirth: string; // ISO string
  patientId: string;
  device: {
    model: string;
    serialNumber: string;
    lastInterrogation: string; // timestamp string
    isConnected: boolean;
  };
  parameters?: Record<string, number | string>;
}

interface User {
  username: string;
  password: string; // plaintext for prototype only
  accountNumber: number;
  createdAt: string; // ISO string
  patientData: Patient;
}
```

- One user → one patient by default. If you want multi-patient per user, change `patientData` to `patients: Patient[]` and add a selector.

### State and Effects

- `isLoggedIn`: toggles login vs dashboard UI
- `currentUser`: tracks the logged-in username
- `showCreateUser`: switch between login and create-account views
- `savedUsers`: list of users (in-memory + `localStorage`)
- `selectedPatient`: patient currently in view; set from the logged-in user
- `activeTab`: which dashboard tab is active
- `telemetryState`: connection status (Connected | Out of Range | Noise | Lost) and `isConnecting`
- `currentTime`: live clock (updated every 1s via `setInterval`)

Effects:

- On mount, start a clock interval; cleanup on unmount
- Whenever `savedUsers` changes, persist to `localStorage` as `"dcm_users"`
- When `isLoggedIn`/`currentUser`/`savedUsers` change, set `selectedPatient` from the current user

### Auth Flow

```ts
// Login
const handleLogin = (username: string, password: string): boolean => {
  const user = savedUsers.find(
    (u) => u.username === username && u.password === password
  );
  if (!user) return false;
  setCurrentUser(username);
  setSelectedPatient(user.patientData);
  setIsLoggedIn(true);
  return true;
};

// Create user (guards duplicates and max count)
const handleCreateUser = (username: string, password: string): boolean => {
  if (savedUsers.find((u) => u.username === username)) return false;
  if (savedUsers.length >= 10) return false;
  const newUser: User = {
    /* seed device + patient */
  };
  setSavedUsers((prev) => [...prev, newUser]);
  return true;
};
```

Security note: passwords are stored in plaintext (prototype only). For real apps, never store passwords in the client; use server auth + hashing.

### Tabs and Conditional Rendering

- Sidebar buttons set `activeTab`
- Each tab renders only when its condition is met, e.g.:
  - `activeTab === "connection" && selectedPatient && <ConnectionView />`
  - `activeTab === "parameters" && selectedPatient && <ParametersTable />`

### Telemetry Simulation

- `connect` sets `isConnecting`, then `connectionState = "Connected"`
- `disconnect` sets `connectionState = "Lost"`
- Header shows Wifi/WifiOff icon + badge according to state

## Persistence (localStorage)

- Key: `dcm_users`
- On first run, the app seeds a default user (e.g., `john/john`) with sample patient/device
- Users persist across reloads; you still need to log in again after refresh (session is not auto-restored)
- To clear: open DevTools → Application → Local Storage → remove `dcm_users`

## UI System

- Components in `src/components/ui/*` wrap Radix primitives with Tailwind classes (shadcn-style).
- Common imports: `button`, `card`, `tabs`, `dialog`, `dropdown-menu`, `popover`, etc.
- Icons from `lucide-react`, used as React components: `<Wifi />`, `<LogOut />`, etc.

## Troubleshooting

- Node/Vite version errors:
  - Ensure Node.js 20+. If you see messages like "Vite requires Node 20.19+", upgrade Node.
- "React is not defined" in TSX files:
  - Ensure `tsconfig.json` uses `"jsx": "react-jsx"` (automatic runtime), or import React in every TSX file.
- Line endings warning on Windows (CRLF/LF):
  - Git may normalize line endings. You can add a `.gitattributes` or run `git add --renormalize .`.
- Nothing persists after reload:
  - Check DevTools → Application → Local Storage for the `dcm_users` key.
  - Ensure your browser isn’t blocking localStorage (e.g., strict privacy/incognito settings).

## Extending

- Multi-patient support: change `User.patientData` → `patients: Patient[]`, add a `<Select>` to pick the active patient, and update save logic to target the selected one.
- Session persistence: write `currentUser` to `localStorage` on login and hydrate state on mount to auto-login.
- Mask sensitive data: remove or obfuscate password columns in admin lists; add a confirm dialog on delete.
- Extract tab content: move large JSX blocks to components (`<ConnectionView/>`, `<ReportsView/>`) for clarity.

## Contributing

- Branching: create a feature branch from `dcm` or `main` as your workflow requires.
- Commit messages: prefer concise, imperative messages (e.g., "Add parameters validation").
- PRs: include a short description, screenshots for UI changes, and test steps.

## License

This project is for academic/prototype purposes. If you need a formal license, add one (e.g., MIT) at the repository root.
