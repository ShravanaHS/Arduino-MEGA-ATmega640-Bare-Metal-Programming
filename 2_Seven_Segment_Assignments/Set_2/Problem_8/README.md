# Set 2 Problem 8: Even and Odd Sequence

## Objective
Connect a 7-Segment Display to **Port A** and display **Even Numbers** (0, 2, 4, 6, 8) followed by **Odd Numbers** (1, 3, 5, 7, 9).

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
- `main` loop:
  1.  Loop `i` from 0 to 8 step 2 -> Displays Even numbers.
  2.  Loop `i` from 1 to 9 step 2 -> Displays Odd numbers.
- Uses `delay1sec()` for timing.

## Source Code
```c
// code to display both even and odd numbers from 0-9

#include <stdint.h>

#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t seg[10] = {
    0x3F,  // 0
    0x06,  // 1
    0x5B,  // 2
    0x4F,  // 3
    0x66,  // 4
    0x6D,  // 5
    0x7D,  // 6
    0x07,  // 7
    0x7F,  // 8
    0x6F   // 9
};

void delay1sec(void){
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

int main(void){
    DDRA = 0x7F;

    while (1){

        // EVEN numbers
        for (uint8_t i = 0; i <= 8; i += 2){
            PORTA = seg[i];
            delay1sec();
        }

        // ODD numbers
        for (uint8_t i = 1; i <= 9; i += 2){
            PORTA = seg[i];
            delay1sec();
        }
    }
}
```

## Simulation
[View Simulation on Wokwi](https://wokwi.com/projects/452037043151397889)

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
