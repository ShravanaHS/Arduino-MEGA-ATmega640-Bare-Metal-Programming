# Problem 1: Show Button Pressed on 7 Segment Display

## Problem Statement
Show the pressed button value on a 7-segment display using a 4x4 keypad.

## Code Analysis
The code scans the 4x4 keypad connected to PORTF (Rows) and PORTK (Columns).
- When a key press is detected, it determines the column using `column()`.
- It maps the `(row, col)` pair to a digit using `keymap`.
- It displays the corresponding 7-segment code `seg[digit]` on PORTA.

## Simulation
[Wokwi Simulation Link](https://wokwi.com/projects/454360648269822977)

![Simulation Screenshot](simulation_screenshot.png)

## Circuit Diagram (JSON Schematic)

```json
{
  "version": 1,
  "author": "ShravanaHS",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-membrane-keypad", "id": "keypad", "top": 50, "left": 350, "attrs": { "columns": "4" } },
    { "type": "wokwi-7segment", "id": "seg1", "top": 50, "left": 220, "attrs": { "common": "cathode" } }
  ],
  "connections": [
    ["mega:97", "keypad:R1", "orange", []],
    ["mega:96", "keypad:R2", "orange", []],
    ["mega:95", "keypad:R3", "orange", []],
    ["mega:94", "keypad:R4", "orange", []],
    ["mega:89", "keypad:C1", "green", []],
    ["mega:88", "keypad:C2", "green", []],
    ["mega:87", "keypad:C3", "green", []],
    ["mega:86", "keypad:C4", "green", []],
    ["mega:22", "seg1:A", "red", []],
    ["mega:23", "seg1:B", "red", []],
    ["mega:24", "seg1:C", "red", []],
    ["mega:25", "seg1:D", "red", []],
    ["mega:26", "seg1:E", "red", []],
    ["mega:27", "seg1:F", "red", []],
    ["mega:28", "seg1:G", "red", []],
    ["mega:GND.1", "seg1:COM", "black", []]
  ]
}
```

> **Pin Mapping**: PORTF (PF0-PF3) = Pins 97-94 = Keypad Rows 1-4. PORTK (PK0-PK3) = Pins 89-86 = Keypad Columns 1-4. PORTA (PA0-PA6) = Pins 22-28 = 7-Seg Segments A-G.
