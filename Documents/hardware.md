# 🔌 Hardware Setup Guide

---

# Table of Contents

1. Required Hardware
2. Hardware Overview
3. Complete Pin Connections
4. Component Wiring
5. Programming the LPC2148
6. First Power-On Checklist
7. Troubleshooting

---

# 1. Required Hardware

| Component | Specification |
|-----------|---------------|
| Microcontroller | LPC2148 ARM7 |
| LCD | 16x2 LCD |
| Keypad | 4x4 Matrix Keypad |
| Sensor | LM35 |
| Alarm | Buzzer / LED |
| Switches | Push Buttons |
| Power Supply | 5V DC |
| Programming Tool | USB-UART |
| Software | Keil + Flash Magic |

---

# 2. Hardware Overview

The EnviroTime hardware consists of:

```text
┌─────────────────────────────────────────────┐
│                ENVIROTIME                  │
├─────────────────────────────────────────────┤
│                                             │
│ 16x2 LCD          4x4 Keypad                │
│                                             │
│ LM35 Sensor       LPC2148 MCU               │
│                                             │
│ Edit Switch       Alarm Stop Switch         │
│                                             │
│ Buzzer / LED      UART Programming Port     │
│                                             │
└─────────────────────────────────────────────┘
```

---

# 3. Complete Pin Connection Table

# LCD Connections

| LCD Pin | Signal | LPC2148 Pin |
|---------|--------|-------------|
| 1 | VSS | GND |
| 2 | VDD | +5V |
| 3 | VEE | Potentiometer |
| 4 | RS | P0.16 |
| 5 | RW | P0.17 |
| 6 | EN | P0.8 |
| 7 | D0 | P0.9 |
| 8 | D1 | P0.10 |
| 9 | D2 | P0.11 |
| 10 | D3 | P0.12 |
| 11 | D4 | P0.13 |
| 12 | D5 | P0.14 |
| 13 | D6 | P0.15 |
| 14 | D7 | P0.18 |

---

# Keypad Connections

| Keypad Pin | LPC2148 Pin |
|------------|-------------|
| Row A | P1.16 |
| Row B | P1.17 |
| Row C | P1.18 |
| Row D | P1.19 |
| Column 1 | P1.20 |
| Column 2 | P1.21 |
| Column 3 | P1.22 |
| Column 4 | P1.23 |

---

# LM35 Connections

| LM35 Pin | Signal | LPC2148 Pin |
|----------|--------|-------------|
| 1 | VCC | +5V |
| 2 | Output | P0.28 (AD0.1) |
| 3 | GND | GND |

---

# Switch Connections

## Edit Switch

| Signal | LPC2148 Pin |
|--------|-------------|
| Input | P0.0 |

Type:

```text
Active LOW
```

---

## Alarm Stop Switch

| Signal | LPC2148 Pin |
|--------|-------------|
| Input | P0.1 |

Type:

```text
Active LOW
```

---

# Alarm Output

| Device | LPC2148 Pin |
|--------|-------------|
| Buzzer / LED | P0.25 |

Type:

```text
Active HIGH
```

---

# 4. Component Wiring

# LM35 Wiring

```text
      LM35

   ┌──────────┐
   │ +V    ○  │──── +5V
   │ OUT   ○  │──── P0.28
   │ GND   ○  │──── GND
   └──────────┘
```

Temperature formula:

```text
Temperature = ADC × 330 / 1023
```

---

# 5. Programming the LPC2148

Using Flash Magic:

## Step 1

Compile project in Keil:

```text
F7
```

Generate:

```text
EnviroTime.hex
```

## Step 2

Open Flash Magic.

Settings:

| Parameter | Value |
|-----------|-------|
| Device | LPC2148 |
| Baud Rate | 38400 |
| Crystal | 12 MHz |
| Interface | ISP |

Select:

```text
EnviroTime.hex
```

Click:

```text
START
```

---

# 6. First Power-On Checklist

After programming:

✅ LCD shows:

```text
ENVIRO TIME
CLOCK & TEMP
```

✅ Time displayed

✅ Temperature displayed

✅ Edit switch opens password menu

✅ Default password:

```text
1234
```

✅ Alarm works

✅ Stop switch turns OFF buzzer

---

# 7. Troubleshooting

| Problem | Solution |
|---------|----------|
| LCD blank | Adjust potentiometer |
| Keypad not working | Check P1.16–P1.23 |
| Temperature = 0 | Check LM35 wiring |
| Buzzer not working | Check P0.25 |
| RTC not running | Check RTC initialization |
| Flash Magic error | Verify COM port |

---

*This document is part of the EnviroTime project documentation.*
