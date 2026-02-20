# Class Exercise 1: 2x2 Switch Matrix Implementation

## Problem Statement
Implement a 2x2 switch matrix using the Keypad interface.

## Code Analysis
The code configures PORTA and PORTB for scanning the matrix rows and columns.
- `PORTA` is used for Keypad rows (Output).
- `PINB` is used for Keypad columns (Input).
- `PORTF` drives the LEDs to indicate key presses.

The `main` function continuously scans the 2 rows (`i=0` to `1`).
For each row, it activates the corresponding bit in `PORTA` and reads the input from `PINB` onto `PORTF`.

## Simulation
[Wokwi Simulation Link](https://wokwi.com/projects/454448194463354881)

![Simulation Screenshot](simulation_screenshot.png)

## Circuit Diagram (JSON Schematic)

```json
{
  "version": 1,
  "author": "ShravanaHS",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-pushbutton", "id": "btn00", "top": 50, "left": 350, "attrs": {} },
    { "type": "wokwi-pushbutton", "id": "btn01", "top": 80, "left": 350, "attrs": {} },
    { "type": "wokwi-pushbutton", "id": "btn10", "top": 50, "left": 390, "attrs": {} },
    { "type": "wokwi-pushbutton", "id": "btn11", "top": 80, "left": 390, "attrs": {} },
    { "type": "wokwi-resistor", "id": "r1", "top": 50, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l1", "top": 50, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r2", "top": 80, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l2", "top": 80, "left": 290, "attrs": { "color": "red" } }
  ],
  "connections": [
    ["mega:22", "btn00:1.l", "orange", []],
    ["mega:22", "btn10:1.l", "orange", []],
    ["mega:23", "btn01:1.l", "orange", []],
    ["mega:23", "btn11:1.l", "orange", []],
    ["btn00:2.r", "mega:53", "green", []],
    ["btn01:2.r", "mega:53", "green", []],
    ["btn10:2.r", "mega:52", "green", []],
    ["btn11:2.r", "mega:52", "green", []],
    ["mega:97", "r1:1", "blue", []], ["r1:2", "l1:A", "blue", []], ["l1:K", "mega:GND.1", "black", []],
    ["mega:96", "r2:1", "blue", []], ["r2:2", "l2:A", "blue", []], ["l2:K", "mega:GND.1", "black", []]
  ]
}
```

> **Pin Mapping**: PORTA (Pins 22-23) = Row outputs. PINB (Pins 53-52) = Column inputs. PORTF (Pins 97-96) = LED outputs.
