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
│ 12:30:25 T:28C │
│ 03/05/2026 WED │ 
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
│ENTER PASSWORD  │
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

The main menu appears.

Use:

- **U** → move up
- **D** → move down
- **S** → select

---

# Main Menu

```text
┌──────────────┐   ┌──────────────┐
│ 1. EDIT RTC  │   │ 2. SET ALARM │
└──────────────┘   └──────────────┘

┌──────────────┐   ┌──────────────┐
│ 3. PIN UPDATE│   │   4. EXIT    │
└──────────────┘   └──────────────┘
```

---

# RTC Editing

Select:

```text
1.RTC
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
Enter Hour 0-23
```

Example:

To set 14:

Press:

```text
1 → 4 → S
```

LCD shows:

```text
HOUR UPDATED
```

---

## Setting Minute

Range:

```text
0–59
```

Press:

```text
value → S
```

---

## Setting Second

Range:

```text
0–59
```

Press:

```text
value → S
```

---

## Setting Day

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

---

## Setting Date

Range:

```text
1–31
```

Date validation is automatic.

Leap year supported.

---

## Setting Month

Range:

```text
1–12
```

---

## Setting Year

Range:

```text
2000–2099
```

Example:

```text
2 → 0 → 2 → 6 → S
```

---

# Alarm Setting

Select:

```text
2.ALARM
```

Enter:

## Alarm Hour

```text
0–23
```

## Alarm Minute

```text
0–59
```

After saving:

```text
ALARM SAVED
```

Example:

```text
07:30
```

---

# When Alarm Triggers

If current RTC time matches alarm:

```text
┌────────────────┐
│ ALARM ACTIVE  │
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
3.PASSWORD
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

# Quick Reference

| Action | Steps |
|--------|-------|
| Enter edit mode | Press EDIT switch |
| Confirm input | Press S |
| Delete digit | Press B |
| Move menu up | Press U |
| Move menu down | Press D |
| Stop alarm | Press Alarm Stop switch |
| Default password | 1234 |

---

*This document is part of the EnviroTime project documentation.*
