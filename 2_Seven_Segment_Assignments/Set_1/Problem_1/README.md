# Set 1 Problem 1: Interface 7-Segment Display

## Objective
Connect a Common Cathode 7-Segment Display to **Port A** and display single digit numbers (0-9).

## Hardware Configuration
- **Port:** Port A
- **Device:** 7-Segment Display (Common Cathode)
- **Connections:**
  - Port A (PA0-PA7) -> Segments A-DP
  - Common Pin -> GND

## Registers Used
- `DDRA` (Direction Register for Port A)
- `PORTA` (Output Register for Port A)
- `TCCR1A`, `TCCR1B`, `TCNT1` (Timer1 Registers for Delay)

## Code Analysis
The code defines a lookup table `seg[]` containing hex codes for digits 0-9 for a Common Cathode display.
- `0x3F` -> 0
- `0x06` -> 1
etc.
A delay function using Timer1 `delay1sec` creates a 1-second interval. The main loop toggles displaying a digit (currently '0') and turning off the display.

## Source Code
```c
//set 1 assignments from 1-10 all can be executed using this one single code 
//the main tasks of set 1 assignemnts are displaying different single digit number 0-9
#include <stdint.h>

#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t seg[10] = {
    0x3F,
    0x06,
    0x5B,
    0x4F,
    0x66,
    0x6D,
    0x7D,
    0x07,
    0x7F,
    0x6F
};

void delay1sec(void){
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

int main(void){
    DDRA = 0x7F; // Set Port A as output (Pins 0-6)

    while (1){
        PORTA = seg[0]; // Display '0'
        delay1sec();
        PORTA = 0x00;   // Turn off
        delay1sec();
    }
}
```

## Simulation
[View Simulation on Wokwi](https://wokwi.com/projects/452036987984757761)

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

> **Pin Mapping**: Port A (PA0-PA7) → Pins 22-29 → Segments A, B, C, D, E, F, G, DP. Common Cathode (CC) tied to GND.

## Visuals
![Simulation Screenshot](./simulation_screenshot.png)
