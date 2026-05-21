# 🌡️ ENVIROTIME: Digital Clock with Real-Time Temperature Monitoring

<div align="center">

⚡ ARM7 LPC2148 Based Embedded System  
🔒 Password Protected • ⏰ Real-Time Clock • 🌡️ Temperature Monitoring • 🔔 Alarm System  

📖 [User Guide](Documents/userguide.md) •
🔌 [Hardware Setup](Documents/hardware.md) •
🏗️ [Architecture](Documents/architecture.md) •
📄 [Project Report](Project_Report/full%20project%20report.pdf)

</div>

---

## 🎯 Project Overview

EnviroTime is a real-time embedded system developed using the LPC2148 ARM7 microcontroller. The system continuously displays current time, date, day, and ambient temperature on a 16x2 LCD.

The project provides:

- Password protected edit mode
- Real-time clock modification
- Alarm setting
- Wrong password security lock
- Alarm indication using buzzer/LED
- User interaction through 4x4 keypad

This project demonstrates real-time monitoring, embedded security, sensor interfacing, and user-controlled configuration.

---

## ✨ Features

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

---

## 🔩 Hardware Components

- 🧠 LPC2148 ARM7 Microcontroller  
- 📺 16x2 LCD Display  
- ⌨️ 4x4 Matrix Keypad  
- 🌡️ LM35 Temperature Sensor  
- 🔘 Push Buttons / Switches  
- 🔔 Buzzer / LED  
- 🔌 USB-UART Programming Interface  
- ⏱️ 12 MHz Crystal Oscillator  
- ⚡ Resistors  
- 🔋 5V Power Supply  

> 📌 For complete hardware connections, wiring diagrams, and flashing instructions, refer to  
> 🔌 [Hardware Setup Guide](Documents/hardware.md)

---

## 🧑‍💻 Software Tools

- 👨‍💻 Embedded C Programming  
- 🛠️ Keil uVision 4 IDE  
- 🖥️ Proteus Design Suite  
- ⚡ Flash Magic Programmer  

---

## ⚙️ Technical Specifications

### 🧠 Microcontroller

- Controller : LPC2148
- Core : ARM7TDMI-S
- Clock Speed : Up to 60 MHz
- Flash Memory : 512 KB
- RAM : 32 KB

### 🌡️ Sensor

- Sensor : LM35
- Output : Analog
- Temperature Range : 0°C to 100°C

### 📺 Display

- Type : 16x2 LCD
- Mode : 8-bit GPIO interface

### ⌨️ Input Devices

- 4x4 Matrix Keypad
- Push Switches

### 🔔 Output Devices

- Buzzer / LED
- LCD Display

> 📌 For complete module architecture, software structure, and program flow, refer to  
> 🏗️ [Architecture Document](Documents/architecture.md)

---

## 🔄 System Working

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

- Buzzer / LED turns ON

Alarm stops only when stop switch is pressed.

> 📌 For complete menu navigation and user operations, refer to  
> 📖 [User Guide](Documents/userguide.md)

---

## 🔌 Pin Configuration Summary

| Peripheral | Signals | LPC2148 Pins | Direction | Description |
|------------|---------|--------------|-----------|-------------|
| LCD Control | RS, RW, EN | P0.16, P0.17, P0.18 | Output | LCD control signals |
| LCD Data Bus | D0–D7 | P0.8–P0.15 | Output | 8-bit LCD data lines |
| Keypad Rows | Row A–D | P1.16–P1.19 | Output | Keypad row scanning |
| Keypad Columns | Column 1–4 | P1.20–P1.23 | Input | Keypad column detection |
| Edit Switch | SW1 | P0.0 | Input | Enter edit mode |
| Alarm Stop Switch | SW2 | P0.1 | Input | Stop alarm |
| Temperature Sensor | LM35 (AD0.1) | P0.28 | Input | Analog temperature input |
| Alarm Output | Buzzer / LED | P0.25 | Output | Alarm indication |

> 📌 For complete board connections, refer to  
> 🔌 [Hardware Setup Guide](Documents/hardware.md)

---

## 📂 Project Structure

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

## 📸 Images

📂 [View All Images](Images/)

### 🖥️ Proteus Simulation

📸 [View Proteus Circuit](Images/FULL_PROTEUS_CONNECTIONS.png)

### 🔄 Flowchart

📸 [View Flowchart](Images/FLOWCHART.png)

### 📺 Main Screen

📸 [View LCD Output](Images/MAIN_TIME_TEMP_DATE_DAY_DISPLAY.png)

> 📌 For complete simulation files, refer to  
> 🖥️ [Proteus Simulation Folder](Proteus_Simulation/)

---

## 📊 Results

Successfully implemented:

✔ Real-time clock display  
✔ Temperature monitoring  
✔ Password security  
✔ Alarm indication  
✔ User configuration menu  
✔ Real-time simulation in Proteus  
✔ Embedded C implementation on LPC2148  

> 📌 For complete implementation details, refer to  
> 📄 [Project Report](Project_Report/full%20project%20report.pdf)

---

## 🌍 Applications

- Used in homes for displaying time and room temperature
- Used in offices for real-time clock and temperature monitoring
- Used in laboratories where temperature monitoring is important
- Used in hospitals to monitor room temperature and time
- Used in industrial areas for environmental monitoring
- Used in educational institutions for embedded learning
- Can be extended for smart home automation

---

## 🚀 Future Scope

- ESP8266 / Bluetooth integration
- Cloud-based monitoring
- Mobile application integration
- Data logging using EEPROM / Flash
- Additional sensor interfacing
- IoT dashboard implementation

---

## 🎯 Outcomes

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

## 📜 License

This project is licensed under the MIT License.

---

## 👩‍💻 Author

**Gayathri Kolli**  
Mini Project – LPC2148 Embedded System
