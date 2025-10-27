# DCM (Device Control Monitor)

A React + TypeScript single-page app for a pacemaker monitoring prototype. It provides a login/create-account flow, a patient dashboard with tabs (Connection, Parameters, Strip Chart, Reports, About). Data is persisted locally using `localStorage` for easy demos.

## Getting Started

Prereqs:

Windows Node Setup:

- Node.js 20+ (recommended). (https://nodejs.org/en)

Linux Node Setup:

- npm (ships with Node). On Windows, commands below use PowerShell syntax.
- curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash
  Install dependencies:

```powershell
cd "C:\...\3K04-Pacemaker-Project\DCM"
npm install
```

Run the dev server:

```powershell
npm run dev


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
index.html # App shell (root <div id="root" />)
package.json # Scripts and deps
vite.config.ts # Vite config
images/ # Static images
imports/ # Extra TS/TSX assets for charts/icons
Parameters.tsx
svg-km06274vuy.ts
src/
main.tsx # React entry (createRoot + <App />)
index.css # Global styles (Tailwind entry)
App.tsx # Main app page (auth + dashboard + tabs)
components/
AboutPage.tsx # About / utilities (user list + delete)
CreateUserLogin.tsx # Create-account form
DeviceCard.tsx # TelemetryWidget (connect/disconnect)
EKGViewer.tsx # Strip chart placeholder/viewer
ParametersTable.tsx # Parameters editor
PrintedReports.tsx # Reports panel scaffold
UserLogin.tsx # Login form
ui/ # shadcn-style UI wrappers over Radix
button.tsx, card.tsx, dialog.tsx, tabs.tsx, ...
styles/
globals.css # Theme variables and base styles

```

This project is for academic/prototype purposes.
```
