# 📖 ENVIROTIME — User Guide

---

# What You Will See After Power-On

When the board is powered ON, the LCD displays:

```text
┌────────────────┐
│ ENVIRO TIME    │
│ CLOCK & TEMP   │
└────────────────┘
```

This startup screen appears for approximately **1.5 seconds**.

After initialization, the main monitoring screen appears:

```text
┌────────────────┐
│ 12:30:00 T:28C │
│ 03/05/2026 MON │ 
└────────────────┘
```

Display information:

- Line 1 → Time + Temperature
- Line 2 → Date + Day

---

# Keypad Layout

```text
┌────────────────────┐
│ 7 │ 8 │ 9 │ U      │
│ 4 │ 5 │ 6 │ D      │
│ 1 │ 2 │ 3 │ C      │
│ B │ 0 │ S │ A      │
└────────────────────┘
```

Special keys:

| Key | Function |
|-----|----------|
| U | Move Up |
| D | Move Down |
| S | Select / Confirm |
| B | Backspace |
| 0–9 | Number Entry |

---

# Entering Edit Mode

Press the **EDIT switch (P0.0)**.


The LCD asks for password:

```text
┌────────────────┐
│ENTER PASSWORD: │
└────────────────┘
```

Default password:

```text
1234
```

Enter password using keypad.

Press:

```text
S
```

to confirm.

---

# If Password Is Correct
If the entered password is correct, the LCD briefly displays:

```text
┌────────────────┐
│ACCEPTED        │
└────────────────┘
```

This message is shown for approximately **1 second**.

After that, the main menu appears...

Use:

- **U** → move up
- **D** → move down
- **S** → select

---

# Main Menu

```text
┌──────────────┐   ┌──────────────┐
│1.EDIT RTC    │   │2.SET ALARM   │
└──────────────┘   └──────────────┘

┌──────────────┐   ┌──────────────┐
│3.PIN UPDATE  │   │4.EXIT        │
└──────────────┘   └──────────────┘
```
| Option | Function |
|--------|----------|
| 1 | Edit RTC settings (time, date, day, month, year) |
| 2 | Set alarm time |
| 3 | Update system PIN/password |
| 4 | Exit and return to main monitoring screen |

---

# RTC Editing

Select:

```text
1. EDIT RTC
```

RTC menu:

```text
1.HOUR
2.MINUTE
3.SECOND
4.DAY
5.DATE
6.MONTH
7.YEAR
8.EXIT
```

---

## Setting Hour

LCD shows:

```text
Enter Hour (0-23)
```

Example:

```text
1 → 4 → S
```

Valid range:

```text
0–23
```

If valid:

```text
HOUR UPDATED
```

If invalid:

```text
INVALID HOUR
```
---

## Setting Minute

LCD shows:

```text
Enter Minute (0-59)
```

Valid range:

```text
0–59
```

If valid:

```text
MIN UPDATED
```

If invalid:

```text
INVALID MIN
```
---

## Setting Second

LCD shows:

```text
Enter Second (0-59)
```

Valid range:

```text
0–59
```

If valid:

```text
SEC UPDATED
```

If invalid:

```text
INVALID SEC
```

---

## Setting Day

LCD shows:

```text
Enter Day (0-6)
```

Values:

```text
0 = Sunday
1 = Monday
2 = Tuesday
3 = Wednesday
4 = Thursday
5 = Friday
6 = Saturday
```

If invalid:

```text
INVALID DAY
```
---

## Setting Date

LCD shows:

```text
Enter Date (1-31)
```

Valid range:

```text
1–31
```

System also checks:

- Month
- Leap year
- Number of days in selected month

Examples:

```text
31/04  → INVALID DATE
29/02/2025 → INVALID DATE
32/01 → INVALID DATE
```

If valid:

```text
DATE UPDATED
```

If invalid:

```text
INVALID DATE
```

---

## Setting Month

LCD shows:

```text
Enter Month (1-12)
```

Valid range:

```text
1–12
```

If invalid:

```text
INVALID MONTH
```
---

## Setting Year

LCD shows:

```text
Enter Year
```

Valid range:

```text
2000–2099
```

Example:

```text
2 → 0 → 2 → 6 → S
```

If invalid:

```text
INVALID YEAR
```
---

To return to main menu:

```text
8.EXIT
```
# Alarm Setting
Select:

```text
2. SET ALARM
```

---

## Setting Alarm Hour

LCD shows:

```text
Enter Hour (0-23)
```

Valid range:

```text
0–23
```

Example:

```text
0 → 7 → S
```

If valid:

```text
HOUR SAVED
```

If invalid:

```text
INVALID HOUR
```
---

## Setting Alarm Minute

LCD shows:

```text
Enter Minute (0-59)
```

Valid range:

```text
0–59
```

Example:

```text
3 → 0 → S
```

If valid:

```text
MIN SAVED
```

If invalid:

```text
INVALID MIN
```

---

## Alarm Saved

If both values are valid, LCD shows:

```text
ALARM SAVED
```

The alarm is now enabled.


# When Alarm Triggers

If current RTC time matches alarm:

```text
┌────────────────┐
│ ALARM ACTIVE   │
└────────────────┘
```

Buzzer / LED turns ON.

---

# Stopping Alarm

Press:

```text
Alarm Stop Switch (P0.1)
```

Alarm turns OFF.

---

# Changing Password

Select:

```text
3.UPDATE PIN
```

Steps:

1. Enter old password
2. Enter new password
3. Confirm new password

If successful:

```text
PASSWORD UPDATED
```

---

# Wrong Password Handling

If wrong password entered:

```text
ACCESS DENIED
```

After 3 wrong attempts:

```text
SYSTEM LOCKED
WAIT: 45 SEC
```

Buzzer beeps 3 times.

After countdown, system unlocks automatically.

---

# Using Backspace

If entered wrong digit:

Press:

```text
B
```

Example:

Entered:

```text
145
```

Press B:

```text
14
```

---

# 📋 Summary

| Action | Steps |
|--------|-------|
| Enter menu | Press **EDIT Switch (SW1)** |
| Enter password | Type password → **S** |
| Set RTC | SW1 → Password → **1.Edit RTC** → Select parameter → Enter value → **S** |
| Set Alarm | SW1 → Password → **2.Set Alarm** → Enter Hour → Enter Minute → **S** |
| Stop Alarm | Press **ALARM STOP Switch (SW2)** |
| Change PIN | SW1 → Password → **3.PIN Update** → Old PIN → New PIN → Confirm |
| Exit Menu | Select **4.EXIT** or **8.EXIT** in RTC menu |
| Move Up | Press **U** |
| Move Down | Press **D** |
| Select / Confirm | Press **S** |
| Delete Last Digit | Press **B** |
| Default Password | **1234** |
| Wrong Password | **ACCESS DENIED** |
| 3 Wrong Attempts | **SYSTEM LOCKED (45 sec)** |

---

*This document is part of the EnviroTime project documentation.*
