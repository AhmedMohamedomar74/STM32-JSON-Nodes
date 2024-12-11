
# STM32 JSON Nodes Project

## Overview
The STM32 JSON Nodes project focuses on creating an embedded application capable of:
- Sending and receiving JSON messages for node initialization, modification, or activation.
- Interfacing with a UART monitor for communication and debugging.
- Integrating temperature and light sensors, as well as a relay actuator.
- Utilizing FreeRTOS for efficient task management.

## Features
- **Temperature Sensor**: Monitors and reports temperature data.
- **Light Sensor**: Tracks and reports ambient light levels.
- **Relay Actuator**: Activates or deactivates based on received JSON commands.
- **UART Communication**: Transfers JSON messages between the STM32 microcontroller and an external monitor.
- **Task Management**: Employs FreeRTOS for scheduling and prioritizing tasks.

## System Requirements
- **Firmware Tools**: Eclipse IDE, STM32CubeMX, GCC ARM toolchain
- **Hardware Simulation Tools**: Proteus
- **Libraries**: FreeRTOS, cJSON
- **Hardware Components**: STM32F103C8, LDR, LM35, relay module, and resistors

## Installation and Setup

### Prerequisites
- Install STM32CubeMX for peripheral configuration.
- Install a compatible STM32 development environment (e.g., Eclipse IDE).
- Download Proteus for hardware simulation.

### Steps to Install
1. Clone the repository:
   ```bash
   git clone https://github.com/AhmedMohamedomar74/STM32-JSON-Nodes
   ```
2. Open the project in your preferred STM32 development environment.
3. Configure peripherals (UART, ADC, GPIO) using STM32CubeMX.
4. Build and flash the firmware to the STM32 board.
5. Simulate the hardware setup using the provided Proteus file.

## Architecture and Design
- **UART Communication**: Handles JSON message exchange.
- **Custom Drivers**: Facilitates interaction with sensors and actuators.
- **FreeRTOS**: Manages multitasking for sensor data acquisition and JSON message handling.

## Usage
### Testing the System
1. Connect the STM32 board to a UART monitor.
2. Send JSON commands to interact with the nodes.
3. Observe responses and functionality through the UART monitor.

### Example JSON Commands
#### Relay Actuator
```json
{"command":"ENA", "nodeID":"0x50", "data":"NULL"} // Enable relay actuator
{"command":"ACT", "nodeID":"0x50", "data":"1"}   // Activate relay actuator
{"command":"ACT", "nodeID":"0x50", "data":"0"}   // Deactivate relay actuator
{"command":"STA", "nodeID":"0x50", "data":"NULL"} // Get relay status
{"command":"DIS", "nodeID":"0x50", "data":"NULL"} // Disable relay actuator
```

#### Temperature Sensor
```json
{"command":"ENA", "nodeID":"0x80", "data":"NULL"} // Enable temperature sensor
{"command":"DUR", "nodeID":"0x80", "data":"5"}    // Set reporting duration to 5 seconds
{"command":"DIS", "nodeID":"0x80", "data":"NULL"} // Disable temperature sensor
```

#### Light Sensor
```json
{"command":"ENA", "nodeID":"0x81", "data":"NULL"} // Enable light sensor
{"command":"DUR", "nodeID":"0x81", "data":"5"}    // Set reporting duration to 5 seconds
{"command":"DIS", "nodeID":"0x81", "data":"NULL"} // Disable light sensor
```

## Hardware
### Components
- **Microcontroller**: STM32F103C8
- **Sensors**: LM35 (temperature), LDR (light)
- **Actuator**: Relay module
- **Miscellaneous**: Resistors, LEDs, and jumper wires

### Resources
- **Schematic File**: Circuit diagram illustrating sensor and actuator connections.
- **Proteus Simulation File**: Included in the repository for testing and validation.

## Known Issues
- FreeRTOS integration with Proteus simulation is not functional. Efforts to resolve this issue are in progress.

## Deliverables
- **Source Code**: Firmware available in the GitHub repository.
- **Simulation Files**: Proteus simulation for hardware testing.
- **Demonstration Video**: Explains functionality and showcases the system in action.

## Resources
- [GitHub Repository](https://github.com/AhmedMohamedomar74/STM32-JSON-Nodes)
- [Video Demonstration](https://drive.google.com/drive/folders/1BTrJEyA87ykYwzaS-UNg11ssfMj1YT2L?usp=drive_link)

---
**Author**: Ahmed Mohamed Omar
