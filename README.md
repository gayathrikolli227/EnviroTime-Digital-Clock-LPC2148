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

## Hardware Requirements

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

## Software Requirements

-> Embedded C
-> Keil uVision 4
-> Proteus Design Suite
-> Flash Magic

## Tech Specifications

### Microcontroller

-> Controller : LPC2148
-> Core : ARM7TDMI-S
-> Clock Speed : Up to 60 MHz
-> Flash Memory : 512 KB
-> RAM : 32 KB

### Sensor

-> Sensor : LM35
-> Output : Analog
-> Temperature Range : 0°C to 100°C

### Display

-> Type : 16x2 LCD
-> Mode : 8-bit GPIO interface

### Input Devices

-> 4x4 Matrix Keypad
-> Push Switches

### Output Devices

-> Buzzer / LED
-> LCD Display

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

## Pin Connections

### LCD Interface

| LCD Pin | LPC2148 Pin |
|---------|-------------|
| RS | P0.16 |
| RW | P0.17 |
| EN | P0.8 |
| D0-D7 | P0.9 – P0.18 |

### LM35 Interface

| LM35 Pin | LPC2148 Pin |
|----------|-------------|
| Output | P0.28 (AD0.1) |

### Switches

| Function | LPC2148 Pin |
|----------|-------------|
| Edit Switch | P0.0 |
| Alarm Stop | P0.1 |

### Alarm Output

| Device | LPC2148 Pin |
|--------|-------------|
| Buzzer / LED | P0.25 |

---

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

(Add your hardware image here)

```markdown
![Hardware Setup](Images/hardware_setup.jpg)
```

### Proteus Simulation

(Add your Proteus screenshot here)

```markdown
![Proteus Simulation](Images/proteus_simulation.png)
```

### LCD Output

(Add LCD output image here)

```markdown
![LCD Output](Images/lcd_output.png)
```

### Flowchart

(Add flowchart image here)

```markdown
![Flowchart](Images/flowchart.png)
```

---

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
Embedded Systems Engineer  
Mini Project – LPC2148 Embedded System
