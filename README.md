# ENVIROTIME: Digital Clock with Real-Time Temperature Monitoring
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

| Peripheral | Signal | LPC2148 Pin | Direction | Description |
|------------|--------|-------------|-----------|-------------|
| LCD | RS | P0.16 | Output | Register Select |
| LCD | RW | P0.17 | Output | Read/Write Control |
| LCD | EN | P0.8 | Output | Enable Signal |
| LCD | D0 | P0.9 | Output | LCD Data Bit 0 |
| LCD | D1 | P0.10 | Output | LCD Data Bit 1 |
| LCD | D2 | P0.11 | Output | LCD Data Bit 2 |
| LCD | D3 | P0.12 | Output | LCD Data Bit 3 |
| LCD | D4 | P0.13 | Output | LCD Data Bit 4 |
| LCD | D5 | P0.14 | Output | LCD Data Bit 5 |
| LCD | D6 | P0.15 | Output | LCD Data Bit 6 |
| LCD | D7 | P0.18 | Output | LCD Data Bit 7 |
| Keypad | Row A | P1.16 | Output | Keypad Row 1 |
| Keypad | Row B | P1.17 | Output | Keypad Row 2 |
| Keypad | Row C | P1.18 | Output | Keypad Row 3 |
| Keypad | Row D | P1.19 | Output | Keypad Row 4 |
| Keypad | Column 1 | P1.20 | Input | Keypad Column 1 |
| Keypad | Column 2 | P1.21 | Input | Keypad Column 2 |
| Keypad | Column 3 | P1.22 | Input | Keypad Column 3 |
| Keypad | Column 4 | P1.23 | Input | Keypad Column 4 |
| Switch | EDIT Switch | P0.0 | Input | Enter Edit Mode (Active LOW) |
| Switch | Alarm Stop | P0.1 | Input | Stop Alarm (Active LOW) |
| Sensor | LM35 Output | P0.28 (AD0.1) | Input | Temperature Sensor |
| Alarm | Buzzer / LED | P0.25 | Output | Alarm Indication (Active HIGH) |
| UART | TXD0 | P0.0 | Output | Serial Communication |
| UART | RXD0 | P0.1 | Input | Serial Communication |


## Project Structure

```text
EnviroTime/
│
├── Source_Code/
├── Proteus_Simulation/
├── Project_Report/
├── Images/
├── README.md
```

---

## Screenshots

### Hardware Setup


### Proteus Simulation 

### LCD Output

### Flowchart


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

- Home automation
- Smart clocks
- Laboratory monitoring
- Industrial monitoring
- Security systems
- Real-time embedded devices

---

## Future Scope

- IoT cloud connectivity
- Mobile app monitoring
- Wi-Fi alerts
- Voice assistant integration
- Data logging

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
