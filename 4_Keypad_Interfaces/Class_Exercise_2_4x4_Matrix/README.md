# Class Exercise 2: 4x4 Switch Matrix Implementation

## Problem Statement
Implement a 4x4 switch matrix with keypad and LED.

## Code Analysis
The code scans a 4x4 matrix using PORTF (Rows) and PORTK (Columns).
- `PORTF` outputs the row scan signals.
- `PORTK` reads the column inputs.
- `PORTA` displays the column value (key press) on LEDs.
- `PORTb` (sic) is used to display the active row momentarily.

The `loop` function iterates through 4 rows, sets the row bit in `PORTF`, and reads `PORTK`.

## Simulation
[Wokwi Simulation Link](https://wokwi.com/projects/454720769713231873)

![Simulation Screenshot](simulation_screenshot.png)

## Circuit Diagram (JSON Schematic)

```json
{
  "version": 1,
  "author": "ShravanaHS",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-membrane-keypad", "id": "keypad", "top": 50, "left": 380, "attrs": { "columns": "4" } },
    { "type": "wokwi-resistor", "id": "r1", "top": 50, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l1", "top": 50, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r2", "top": 80, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l2", "top": 80, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r3", "top": 110, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l3", "top": 110, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r4", "top": 140, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l4", "top": 140, "left": 290, "attrs": { "color": "red" } }
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
    ["mega:22", "r1:1", "red", []], ["r1:2", "l1:A", "red", []], ["l1:K", "mega:GND.1", "black", []],
    ["mega:23", "r2:1", "red", []], ["r2:2", "l2:A", "red", []], ["l2:K", "mega:GND.1", "black", []],
    ["mega:24", "r3:1", "red", []], ["r3:2", "l3:A", "red", []], ["l3:K", "mega:GND.1", "black", []],
    ["mega:25", "r4:1", "red", []], ["r4:2", "l4:A", "red", []], ["l4:K", "mega:GND.1", "black", []]
  ]
}
```

> **Pin Mapping**: PORTF (Pins 97-94) = Keypad Row outputs. PORTK (Pins 89-86) = Keypad Column inputs. PORTA (Pins 22-25) = LED column indicator outputs.
