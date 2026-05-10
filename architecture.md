# 🏗️ ENVIROTIME — System Architecture

---

# Table of Contents

1. System Overview  
2. Hardware Architecture  
3. Software Module Architecture  
4. Program Flow  
5. Peripheral Architecture  
6. Memory Usage  
7. Clock Architecture  
8. Data Structures  

---

# 1. System Overview

EnviroTime is a real-time embedded monitoring and security system
developed using the **NXP LPC2148 ARM7 microcontroller**.

The system performs:

- Real-time clock monitoring
- Temperature sensing
- Password authentication
- Alarm generation
- User parameter editing

---

## High-Level Architecture

```text
┌──────────────────────────────────────────────────────────────────────────┐
│                          EnviroTime System                               │
│                                                                          │
│   INPUT                   PROCESSING CORE                 OUTPUT         │
│                                                                          │
│  ┌──────────┐             ┌──────────────┐          ┌──────────────┐     │
│  │  4×4     │  ──GPIO──►  │              │  ──GPIO─►│  16×2 LCD    │     │
│  │ Keypad   │             │   LPC2148    │          │   Display    │     │
│  └──────────┘             │  ARM7TDMI-S  │          └──────────────┘     │
│                           │   60 MHz     │                               │
│  ┌──────────┐             │              │          ┌──────────────┐     │
│  │  LM35    │  ──ADC───►  │  Flash:512KB │  ──GPIO─►│   Buzzer     │     │
│  │ Temp     │             │  RAM:  32KB  │          │   Alarm      │     │
│  │ Sensor   │             │              │          └──────────────┘     │
│  └──────────┘             │  RTC (32kHz) │                               │
│                           │  (built-in)  │          ┌──────────────┐     │
│  ┌──────────┐             │              │          │  Keil HEX    │     │
│  │  EDIT    │  ──GPIO───► │              │          │  via ISP     │     │
│  │  Switch  │             └──────────────┘          └──────────────┘     │
│  └──────────┘                                                            │
│  ┌──────────┐                                                            │
│  │  ALARM   │  ──GPIO───►  (Stops buzzer)                                │
│  │  Switch  │                                                            │
│  └──────────┘                                                            │
└──────────────────────────────────────────────────────────────────────────┘
```

---

# 2. Hardware Architecture

## Microcontroller LPC2148 Key Specifications

| Property | Value |
|----------|-------|
| CPU Core | ARM7TDMI-S (32-bit RISC) |
| Maximum Clock | 60 MHz |
| Flash Memory | 512 KB |
| SRAM | 32 KB |
| GPIO | 46 pins across Port 0 (P0) and Port 1 (P1) |
| Built-in RTC | Yes — supports external 32.768 kHz crystal or internal PCLK prescaler |
| ADC | 10-bit, 8-channel ADC (AD0) |
| UART | 2 UART interfaces (UART0 and UART1) |
| Package | LQFP64 |

---

## Pin Mapping

### LCD

| Signal | Pin |
|--------|-----|
| RS | P0.16 |
| RW | P0.17 |
| EN | P0.8 |
| D0–D7 | P0.9–P0.18 |

### Keypad

| Signal | Pin |
|--------|-----|
| Rows | P1.16–P1.19 |
| Columns | P1.20–P1.23 |

### LM35

| Signal | Pin |
|--------|-----|
| Output | P0.28 (AD0.1) |

### Switches

| Signal | Pin |
|--------|-----|
| Edit Switch | P0.0 |
| Alarm Stop | P0.1 |

### Alarm Output

| Signal | Pin |
|--------|-----|
| Buzzer / LED | P0.25 |

---

# 3. Software Module Architecture

```text
                     main.c
                        │
 ┌──────────────────────┼──────────────────────┐
 │                      │                      │
 ▼                      ▼                      ▼

init_system.c       display_rtc.c         alarm.c
      │                   │                   │
      ▼                   ▼                   ▼

lcd.c               rtc.c               adc.c
kpm.c               lm35.c              delay.c
password.c          device_settings.c   edit_rtc_settings.c
```

---

## Module Description

### main.c

Responsible for:

- Main loop
- Calling display function
- Checking switches
- Password validation
- Alarm handling

---

### init_system.c

Initializes:

- LCD
- RTC
- ADC
- Keypad
- GPIO

---

### display_rtc.c

Displays:

- Time
- Date
- Day
- Temperature

---

### alarm.c

Responsible for:

- Alarm setting
- Alarm comparison
- Buzzer ON/OFF

---

### password.c

Responsible for:

- Password verification
- Wrong attempt counting
- Lock mechanism

---

# 4. Program Flow

```text
Power ON
   │
   ▼
Initialize All Peripherals
   │
   ▼
Display Startup Message
   │
   ▼
Read RTC + Temperature
   │
   ▼
Display on LCD
   │
   ▼
Check Alarm
   │
   ▼
Check Edit Switch
   │
 ┌─┴─────────────┐
 │ Pressed ?     │
 └─┬─────────────┘
   │YES
   ▼
Ask Password
   │
 ┌─┴─────────────┐
 │ Correct ?     │
 └─┬─────────────┘
   │YES
   ▼
Open Edit Menu
   │
   ▼
Save Changes
   │
   ▼
Return to Main Loop
```

---

# 5. Peripheral Architecture

## RTC

Uses LPC2148 internal RTC.

Stores:

- Hour
- Minute
- Second
- Date
- Day
- Month
- Year

---

## ADC

LM35 sensor connected to:

```c
AD0.1 → P0.28
```

ADC resolution:

```text
10-bit
0–1023
```

Temperature formula:

```text
Temperature = ADC × 330 / 1023
```

---

## LCD

16x2 LCD in 8-bit mode.

Display format:

```text
12:30:25 T:28C
03/05/2026 WED
```

---

## Keypad

4x4 keypad used for:

- Password entry
- Time editing
- Alarm setting

---

# 6. Memory Usage

```text
FLASH : 512 KB
RAM   : 32 KB
```

Used for:

- Program code
- Password storage
- Alarm variables
- RTC data

---

# 7. Clock Architecture

```text
Crystal = 12 MHz

PLL = ×5

CPU Clock = 60 MHz

Peripheral Clock = 15 MHz
```

---

# 8. Data Structures

## Password

```c
default_password[5]
```

Default:

```text
1234
```

---

## Alarm Variables

```c
alarm_hour
alarm_min
alarm_flag
```

---

## RTC Variables

```c
h
mi
s
d
mo
y
da
```

---

# Conclusion

EnviroTime integrates:

✅ RTC  
✅ ADC  
✅ LCD  
✅ Keypad  
✅ Password Security  
✅ Alarm Management  
✅ Real-Time Embedded Control  

making it a complete real-time embedded monitoring system.
