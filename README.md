# bicopter-ardupilot-flightMode
Custom bicopter stabilization flight mode implemented in ArduPilot using cascade PID control (pitch-axis stabilization)

## Overview

This project implements a custom bicopter stabilization flight mode directly integrated into the ArduPilot / ArduCopter framework. The system focuses on real-time pitch-axis control using a cascade PID architecture.

The main experimental objective is **sequential angle tracking with increasing amplitude**, where the bicopter follows predefined angular setpoints and successfully converges to each target with stability and accuracy.

---

## Project Objective

The goal of this project is to design and implement a custom control system capable of:

- Stabilizing a bicopter on the pitch axis
- Tracking sequential angular setpoints
- Maintaining fast and accurate response
- Ensuring stable transitions between increasing amplitude references
- Validating control performance on real hardware

---

## Control Strategy

The system is based on a **cascade PID control architecture**:

- **Outer loop (Angle control)**  
  Computes pitch angle error and generates a desired angular rate reference.

- **Inner loop (Rate control)**  
  Uses gyroscope feedback to stabilize angular velocity and produce final actuator commands.

This architecture improves:
- Stability
- Response time
- Smoothness of motion
- Robustness against disturbances

---

## Demonstration

The system demonstrates sequential angle tracking with increasing amplitude. The bicopter successfully follows predefined angular setpoints, reaching each target quickly and accurately using the developed control system.

---

## Implementation Details

The project is implemented in C++ and integrated into the ArduCopter flight stack.

Main components:

- `mode_bicopter.cpp` → Custom bicopter flight mode with cascade PID control
- `mode.h` → Flight mode class definition
- `mode.cpp` → Core control loop execution and logic
- `config.h` → System configuration and setup
- `Parameters.cpp` → Custom parameter definitions and tuning setup
- `Copter.h` → Integration of the custom flight mode into ArduCopter

---

## Experimental Validation

The system was tested on a real bicopter platform under controlled conditions.

### Test procedure:
- Sequential pitch angle tracking
- Increasing amplitude reference steps (positive and negative angles)
- Real-time stabilization and recovery testing

### Observations:
- The bicopter successfully follows all predefined setpoints
- Fast convergence to target angles is achieved
- Stable behavior is maintained during transitions
- The controller handles increasing amplitude without instability

---

## Results

The implemented flight mode demonstrates:

- Stable pitch-axis control
- Accurate sequential angle tracking
- Improved dynamic response compared to baseline behavior
- Successful real-world validation on a physical bicopter platform

---

## Technologies Used

- C++ (embedded real-time control)
- ArduPilot / ArduCopter framework
- MAVLink ecosystem (communication and debugging)
- IMU-based feedback (AHRS system)

---

## ArduPilot Integration

This project extends the open-source ArduPilot autopilot system.

Only custom-developed files are included in this repository. The full ArduPilot source code is available here:

https://github.com/ArduPilot/ardupilot

---

## Experimental Media

- Bicopter stabilization test video: [Add YouTube / Drive link]
- Seminar presentation: [Add LinkedIn link]

---

## Author

Luiza Mkrtchyan  
Bachelor’s Degree in Computer Science  
Internship at CSIE (Center for Scientific Innovation and Education)
