
# STM32 JSON Nodes Project

## Project Overview
This project involves developing an STM32-based application capable of:
- Receiving and sending JSON messages for node initialization, modification, or activation.
- Interfacing with a UART monitor to send JSON messages and display node responses.
- Integrating a temperature sensor, light sensor, and relay actuator.
- Managing tasks using FreeRTOS.

## System Requirements
- **Firmware Development Tools**: Eclipse IDE or any compatible STM32 toolchain
- **Hardware Simulation Tools**: Proteus
- **Libraries**: FreeRTOS, cJSON

## Architecture and Design
The system is designed to:
1. Utilize UART communication for message exchange.
2. Incorporate custom drivers for sensor and actuator interfacing.
3. Employ FreeRTOS for efficient task scheduling and management.

## Functional Specifications
- **Temperature Sensor**: Measure and report temperature values.
- **Light Sensor**: Monitor and report ambient light levels.
- **Relay Actuator**: Control activation/deactivation based on received commands.
- **UART Integration**: Communicate JSON data between the STM32 and a UART monitor.

## Setup and Installation
### Prerequisites
- STM32CubeMX for hardware configuration
- STM32 development board
- Proteus for hardware simulation
- GCC ARM toolchain for compilation

### Steps to Install
1. Clone the repository:  
   ```bash
   git clone https://github.com/AhmedMohamedomar74/STM32-JSON-Nodes
   ```
2. Open the project in your preferred STM32 development environment.
3. Configure the peripherals (UART, ADC, GPIO) using STM32CubeMX.
4. Build and flash the firmware.
5. Use Proteus to simulate the circuit with sensors and actuators.

## Testing and Validation
1. **Simulation Testing**:  
   Use the Proteus simulation file included in the repository to test the system’s functionality.
2. **Functional Testing**:  
   Validate JSON message parsing, sensor readings, and actuator control via UART.

### Test Commands
Use the following JSON commands to test the system. Copy any of these commands and send them via the UART interface to observe the corresponding functionality:

#### Relay
```json
{"command":"ENA", "nodeID":"0x50", "data":"NULL"} // Enable Relay Actuator
{"command":"ACT", "nodeID":"0x50", "data":"1"} // Activate Relay Actuator
{"command":"ACT", "nodeID":"0x50", "data":"0"} // Deactivate Relay Actuator
{"command":"STA","nodeID":"0x50","data":"NULL"} // Get Relay Actuator Status
{"command":"DIS","nodeID":"0x50","data":"NULL"} // Disable Relay Actuator
```

#### Temperature Sensor
```json
{"command":"ENA", "nodeID":"0x80", "data":"NULL"} // Enable temp sensor
{"command":"DUR", "nodeID":"0x80", "data":"5"} // Make temp sensor send value every 5 sec
{"command":"DIS","nodeID":"0x80","data":"NULL"} // Disable temp sensor
```

#### LDR
```json
{"command":"ENA", "nodeID":"0x81", "data":"NULL"} // Enable LDR sensor
{"command":"DUR", "nodeID":"0x81", "data":"5"} // Make LDR sensor send value every 5 sec
{"command":"DIS","nodeID":"0x81","data":"NULL"} // Disable LDR sensor
```

## Known Issues
- FreeRTOS integration with the Proteus simulation environment is currently not functional. Efforts to resolve this issue are ongoing and updates will be provided.

## Deliverables
- **GitHub Repository**: Contains firmware source code and project documentation.
- **Proteus Simulation File**: Circuit design with sensors and actuators.
- **Video Demonstration**: Shows the implemented functionality and explains the current limitations.

## Resources
- [GitHub Repository](https://github.com/AhmedMohamedomar74/STM32-JSON-Nodes)
- [Video Demonstration](https://drive.google.com/drive/folders/1BTrJEyA87ykYwzaS-UNg11ssfMj1YT2L?usp=drive_link)
