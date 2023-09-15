# Automotive Monitor System

![Project Image](https://raw.githubusercontent.com/MohamadAbdelmoniem/Automotive-Monitor-System/main/Automotive%20Monitor%20System%20Source/Automotive%20Monitor%20System.PNG)

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Components](#components)
- [Installation](#installation)
- [Usage](#usage)


## Description

The **Automotive Monitor System** is a microcontroller-based project designed for automotive applications, powered by the STM32F401CC microcontroller. It provides various functionalities related to vehicle control, monitoring, and security. This system is built using various hardware and software components to create a comprehensive automotive control solution.

## Features

- **Password Protection**: The system features password protection for access control, ensuring authorized use only.

- **Temperature Monitoring**: It can monitor the temperature inside the vehicle and display it on an LCD screen. It will alert the user if the temperature goes above a certain threshold.

- **Distance Sensing**: The system uses ultrasonic sensors to measure the distance between the vehicle and an obstacle, providing warnings if an obstacle is too close.

- **Pressure Monitoring**: It can measure and display pressure readings, with alerts for high or low-pressure conditions.

- **Engine Control**: The system can start and stop the engine, provided certain conditions are met, such as the correct password and safety checks.

- **User Interface**: An LCD screen and keypad provide a user-friendly interface for interaction with the system.

- **LED and Buzzer Indicators**: LED indicators and a buzzer are used to provide visual and audible feedback to the user.

## Components

The project consists of the following main components:

- Microcontroller Unit (MCU) - STM32F401CC
- LCD Display
- Keypad
- Ultrasonic Sensors
- Temperature Sensor (LM35)
- Pressure Sensor (MPX4115)
- DC Motor Control
- Push Buttons
- LEDs
- Buzzer
- Switches

## Installation

To set up the **Automotive Monitor System**, follow these steps:

1. **Hardware Assembly**: Connect all the hardware components according to the provided circuit diagram.

2. **Software Setup**: Install the necessary software development tools and libraries on your development computer, including STM32CubeMX and STM32CubeIDE.

3. **Programming**: Load the provided source code onto the STM32F401CC microcontroller using STM32CubeIDE and an ST-Link programmer.

4. **Power On**: Connect the system to the power supply and ensure all components are working correctly.

## Usage

Here's how to use the Automotive Control System:

1. **Power On**: Turn on the system using the power supply.

2. **Password Entry**: Enter the correct password using the keypad to access the system.

3. **Main Menu**: Once logged in, you'll see the main menu on the LCD screen. Choose an option by pressing the corresponding key on the keypad.

4. **Functionality**:
   - Option 1: Check All - This option performs safety checks and provides feedback.
   - Option 2: Temperature - Displays and alerts about the temperature.
   - Option 3: Distance - Measures and alerts about the distance from obstacles.
   - Option 4: Pressure - Displays and alerts about pressure conditions.

5. **Engine Control**: If you choose to start the engine, ensure that safety conditions are met, such as a closed door.

6. **Feedback**: The system provides visual and audible feedback through LEDs and a buzzer.

