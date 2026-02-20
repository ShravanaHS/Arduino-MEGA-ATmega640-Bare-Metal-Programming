# Set 2 Problem 6: Countdown 9-0

## Objective
Connect a 7-Segment Display to **Port A** and display a countdown from 9 to 0 with a 1-second delay.

## Hardware Configuration
- **Port:** Port A
- **Device:** 7-Segment Display (Common Cathode)
- **Connections:**
  - Port A (PA0-PA7) -> Segments A-DP

## Registers Used
- `DDRA`
- `PORTA`
- `TCCR1A`, `TCCR1B`, `TCNT1` (Timer1)

## Code Analysis
- `seg` array: Standard 0-9 HEX codes.
- `main` loop: Counts down from 9 to 0.
- `delay1sec()`: Implemented correctly with Timer1.
- Logic: `PORTA = seg[i]`. This assumes a **Common Cathode** display (High = ON).
- (Note: Wokwi Project Title is "Problem 3", but listed as Problem 6 in assignment list).

## Source Code
```c
#include <stdint.h>

#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t seg[10] = {
  0x3F, // 0
  0x06, // 1
  0x5B, // 2
  0x4F, // 3
  0x66, // 4
  0x6D, // 5
  0x7D, // 6
  0x07, // 7
  0x7F, // 8
  0x6F  // 9
};

void delay1sec(void){
  TCNT1 = 0;
  TCCR1A = 0x00;
  TCCR1B = 0x05; // Timer1 with 1024 prescaler
  while (TCNT1 < 15625); // ~1 second delay at 16MHz
  TCCR1B = 0x00;
}

int main(void){
  DDRA = 0x7F; // Set first 7 bits of Port A as output

  while (1){
    for (int8_t i = 9; i >= 0; i--){
      PORTA = seg[i];
      delay1sec();
    }
  }
}
```

## Simulation
[View Simulation on Wokwi](https://wokwi.com/projects/452037077877093377)

## Circuit Diagram (JSON Schematic)

```json
{
  "version": 1,
  "author": "ShravanaHS",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-7segment", "id": "seg1", "top": 50, "left": 220, "attrs": { "common": "cathode" } }
  ],
  "connections": [
    ["mega:22", "seg1:A", "red", []],
    ["mega:23", "seg1:B", "red", []],
    ["mega:24", "seg1:C", "red", []],
    ["mega:25", "seg1:D", "red", []],
    ["mega:26", "seg1:E", "red", []],
    ["mega:27", "seg1:F", "red", []],
    ["mega:28", "seg1:G", "red", []],
    ["mega:29", "seg1:DP", "red", []],
    ["mega:GND.1", "seg1:COM", "black", []]
  ]
}
```

> **Pin Mapping**: Port A (PA0-PA7) → Pins 22-29 → Segments A, B, C, D, E, F, G, DP. Common Cathode tied to GND.

## Visuals
![Simulation Screenshot](./simulation_screenshot.png)
