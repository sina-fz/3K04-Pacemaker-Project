# Heartburn - An Embedded Pacemaker Control System
Welcome to Heartburn, a fully functional testbed for a pacemacker embedded system. This project was conducted under the purview of the SFWRENG 3K04 course at McMaster University.

In this repository, you will find the following:

- Firmware: Contains the Simulink file used to generate embedded C code to run on an FDRM-K64F microcontroller. All control logic and hardware interfacing is handled within the firmware.

- DCM (Device Controller Monitor): Contains all code to run a web-app that allows for real-time telemetry updates and parameter tuning for the pacemaker system, via UART serial communication.

- Documentation: Contains requirements, design justification, assurance cases, and testing/verification for the safety-critical system.