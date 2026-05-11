# 🌡️ ENVIROTIME: Digital Clock with Real-Time Temperature Monitoring

<div align="center">

⚡ ARM7 LPC2148 Based Embedded System  
🔒 Password Protected • ⏰ Real-Time Clock • 🌡️ Temperature Monitoring • 🔔 Alarm System  

📖 [User Guide](Documents/USER_GUIDE.md) •
🔌 [Hardware Setup](Documents/HARDWARE_SETUP.md) •
🏗️ [Architecture](Documents/architecture.md) •


</div>

---

## Project Overview 
EnviroTime is a real-time embedded system developed using the LPC2148 ARM7 microcontroller. The system continuously displays current time, date, day and ambient temperature on a 16x2 LCD.

The project also provides:

- Password protected edit mode
- Real-time clock modification
- Alarm setting
- Wrong password security lock
- Alarm indication using buzzer/LED
- User interaction through 4x4 keypad

This project demonstrates real-time monitoring, embedded security,sensor interfacing, and user-controlled configuration.

## Features

✔ Real-Time Clock (RTC) display  
✔ Temperature monitoring using LM35  
✔ Password-based secure access  
✔ Alarm setting and alarm indication  
✔ Edit mode using switch polling  
✔ Wrong-attempt lock system  
✔ Date, day, month, year editing  
✔ Keypad-based menu navigation  
✔ LCD user interface  
✔ Real-time hardware simulation in Proteus  

## Hardware 

- LPC2148 ARM7 Microcontroller
- 16x2 LCD Display
- 4x4 Matrix Keypad
- LM35 Temperature Sensor
- Push Buttons / Switches
- Buzzer/LED
- USB-UART Converter
- Crystal Oscillator
- Resistors
- Power Supply

## Software

- Embedded C
- Keil uVision 4
- Proteus Design Suite
- Flash Magic

## Tech Specifications

### Microcontroller

- Controller : LPC2148
- Core : ARM7TDMI-S
- Clock Speed : Up to 60 MHz
- Flash Memory : 512 KB
- RAM : 32 KB

### Sensor

- Sensor : LM35
- Output : Analog
- Temperature Range : 0°C to 100°C

### Display

- Type : 16x2 LCD
- Mode : 8-bit GPIO interface

### Input Devices

- 4x4 Matrix Keypad
- Push Switches

### Output Devices

- Buzzer / LED
- LCD Display

## System Working

### 1. Initialization

System initializes:

- LCD
- RTC
- ADC
- Keypad
- Switches
- Alarm output

### 2. Real-Time Monitoring

System continuously displays:

- Time
- Date
- Day
- Temperature

### 3. Secure Edit Mode

When edit switch is pressed:

- Password is requested
- Access is granted only for correct password

User can edit:

- Time
- Date
- Alarm
- Password

### 4. Security

If wrong password is entered 3 times:

- System locks temporarily
- Alarm indication is generated

### 5. Alarm

When current time matches alarm time:

- Buzzer/LED turns ON

Alarm stops only when stop switch is pressed.

---

# 🔌 Pin Configuration Summary

| Peripheral | Signals | LPC2148 Pins | Direction | Description |
|------------|---------|--------------|-----------|-------------|
| LCD Control | RS, RW, EN | P0.16, P0.17, P0.8 | Output | LCD control signals |
| LCD Data Bus | D0–D7 | P0.9–P0.15, P0.18 | Output | 8-bit LCD data lines |
| Keypad Rows | Row A–D | P1.16–P1.19 | Output | Keypad row scanning |
| Keypad Columns | Column 1–4 | P1.20–P1.23 | Input | Keypad column detection |
| Edit Switch | SW1 | P0.0 | Input | Enter edit mode (Active LOW) |
| Alarm Stop Switch | SW2 | P0.1 | Input | Stop alarm (Active LOW) |
| Temperature Sensor | LM35 (AD0.1) | P0.28 | Input | Analog temperature input |
| Alarm Output | Buzzer / LED | P0.25 | Output | Alarm indication (Active HIGH) |


## Project Structure

```text
EnviroTime/
│
├── Documents/
├── Images/
├── Project_Report/
├── Proteus_Simulation/
├── Source_Code/
├── README.md
```

---

## Images
📂 [View All Images](Images/)
### Proteus Simulation 
📸 [View Flowchart](Images/FULL_PROTEUS_CONNECTIONS.png)
### Flowchart
📸 [View Flowchart](Images/FLOWCHART.png)
### Main Screen display
📸 [View Flowchart](Images/MAIN_TIME_TEMP_DATE_DAY_DISPLAY.png)

## Results

Successfully implemented:

✔ Real-time clock display  
✔ Temperature monitoring  
✔ Password security  
✔ Alarm indication  
✔ User configuration menu  
✔ Real-time simulation in Proteus  
✔ Embedded C implementation on LPC2148  

---

## Applications

- Used in homes for displaying time and room temperature. 
- Used in offices for real-time clock and temperature monitoring.
- Used in laboratories where temperature monitoring is important. 
- Used in hospitals to monitor room temperature and time. 
- Used in industrial areas for basic environmental monitoring. 
- Used in schools and colleges as a digital clock with alarm and security feature. 
- Can be used as a basic model for smart home automation systems. 

---

## Future Scope

- Wireless communication modules such as ESP8266 or Bluetooth can be integrated for remote monitoring and wireless data transmission. 
- Real-time clock and temperature data can be stored in non-volatile memory devices such as EEPROM or Flash Memory for data logging and analysis.
- Additional sensors such as humidity sensors, gas sensors, or motion sensors can be interfaced to enhance environmental monitoring capabilities.
- The system can be integrated with smart home and industrial automation platforms for intelligent monitoring applications.
- Implementation of temperature history recording for monitoring and analyzing environmental changes over time.
- Cloud-based monitoring and notification features can be implemented for IoT applications.

---

## Outcomes

Through this project, the following skills were developed:

- Embedded C programming
- ARM7 microcontroller programming
- RTC interfacing
- ADC interfacing
- Sensor integration
- LCD interfacing
- Keypad scanning
- Security implementation
- Proteus simulation
- Hardware debugging

---

## Author

**Gayathri Kolli**  
Mini Project – LPC2148 Embedded System
