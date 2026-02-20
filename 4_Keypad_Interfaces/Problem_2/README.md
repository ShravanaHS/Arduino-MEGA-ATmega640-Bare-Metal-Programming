# Problem 2: 4-Digit Display Keypad

## Problem Statement
Use a 4-digit 7-segment display to show 4 button presses from the keypad.

## Code Analysis
The code captures up to 4 key presses and stores them in the `digits` array.
- It multiplexes the 4-digit display using `display_4digit`, activating one digit at a time via PORTB.
- The keypad scanning loop detects presses, debounces them, and maps them to digits.
- The `digits` array acts as a buffer for the display.

## Simulation
[Wokwi Simulation Link](https://wokwi.com/projects/454754911592402945)

![Simulation Screenshot](simulation_screenshot.png)

## Circuit Diagram (JSON Schematic)

```json
{
  "version": 1,
  "author": "ShravanaHS",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-membrane-keypad", "id": "keypad", "top": 50, "left": 400, "attrs": { "columns": "4" } },
    { "type": "wokwi-7segment", "id": "seg1", "top": 50, "left": 220, "attrs": { "common": "cathode" } },
    { "type": "wokwi-7segment", "id": "seg2", "top": 80, "left": 260, "attrs": { "common": "cathode" } },
    { "type": "wokwi-7segment", "id": "seg3", "top": 110, "left": 300, "attrs": { "common": "cathode" } },
    { "type": "wokwi-7segment", "id": "seg4", "top": 140, "left": 340, "attrs": { "common": "cathode" } }
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
    ["mega:22", "seg1:A", "red", []], ["mega:22", "seg2:A", "red", []], ["mega:22", "seg3:A", "red", []], ["mega:22", "seg4:A", "red", []],
    ["mega:23", "seg1:B", "red", []], ["mega:23", "seg2:B", "red", []], ["mega:23", "seg3:B", "red", []], ["mega:23", "seg4:B", "red", []],
    ["mega:24", "seg1:C", "red", []], ["mega:24", "seg2:C", "red", []], ["mega:24", "seg3:C", "red", []], ["mega:24", "seg4:C", "red", []],
    ["mega:25", "seg1:D", "red", []], ["mega:25", "seg2:D", "red", []], ["mega:25", "seg3:D", "red", []], ["mega:25", "seg4:D", "red", []],
    ["mega:26", "seg1:E", "red", []], ["mega:26", "seg2:E", "red", []], ["mega:26", "seg3:E", "red", []], ["mega:26", "seg4:E", "red", []],
    ["mega:27", "seg1:F", "red", []], ["mega:27", "seg2:F", "red", []], ["mega:27", "seg3:F", "red", []], ["mega:27", "seg4:F", "red", []],
    ["mega:28", "seg1:G", "red", []], ["mega:28", "seg2:G", "red", []], ["mega:28", "seg3:G", "red", []], ["mega:28", "seg4:G", "red", []],
    ["mega:53", "seg1:COM", "blue", []],
    ["mega:52", "seg2:COM", "blue", []],
    ["mega:51", "seg3:COM", "blue", []],
    ["mega:50", "seg4:COM", "blue", []]
  ]
}
```

> **Pin Mapping**: PORTF (Pins 97-94) = Keypad Rows. PORTK (Pins 89-86) = Keypad Cols. PORTA (Pins 22-28) = Segments (shared bus). PORTB (Pins 53,52,51,50) = Digit enable.
