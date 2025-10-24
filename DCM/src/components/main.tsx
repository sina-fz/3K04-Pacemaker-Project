import React, { useState } from 'react';
import ReactDOM from 'react-dom/client';
import { UserLogin } from './UserLogin';
import { CreateUserLogin } from './CreateUserLogin';

function App() {
  const [showCreateUser, setShowCreateUser] = useState(false);

  // Dummy user creation logic
  const handleCreateUser = (username: string, password: string) => {
    // Implement your user creation logic here
    // Return true if successful, false otherwise
    return true;
  };

  return (
    <>
      {showCreateUser ? (
        <CreateUserLogin
          onCreateUser={handleCreateUser}
          onBackToLogin={() => setShowCreateUser(false)}
        />
      ) : (
        <UserLogin
          onCreateUserClick={() => setShowCreateUser(true)}
        />
      )}
    </>
  );
}

ReactDOM.createRoot(document.getElementById('root')!).render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);