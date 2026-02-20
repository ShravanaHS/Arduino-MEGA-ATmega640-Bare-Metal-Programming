# Set 1 Problem 6: Upper Nibble Blink (Port A)

## Problem Statement
Connect four LEDs to the upper half of **Port A** (Bits 4, 5, 6, 7).
Blink all four of them together.
*(Note: The original problem assignment might differ, but this solution is wired for Port A on the simulation).*

## Simple Explanation
We are lighting up the "Left Side" (Upper Nibble) of the 8-bit byte.
-   **Upper Nibble**: Bits 4, 5, 6, 7.
-   **Lower Nibble**: Bits 0, 1, 2, 3 (The right side).
-   Pattern: `11110000` (Hex `0xF0`).

## Hardware Setup
-   **Port Used**: Port A
-   **Pins**: Bits 4-7.
-   **Registers**:
    -   `DDRA` (Data Direction Register A): Address `0x21`.
    -   `PORTA` (Port A Data Register): Address `0x22`.

## Code Analysis

```c
#include <stdint.h>

// --- Register Definitions ---
#define PORTA (*(volatile uint8_t*) 0x22) // Port Data
#define DDRA  (*(volatile uint8_t*) 0x21) // Port Direction

void setup() {
  // Set Upper Nibble (4-7) as Output.
  // We can write Hex 0xF0 (11110000) directly, or shift bits.
  // (1<<7) | (1<<6) | (1<<5) | (1<<4) creates 11110000.
  DDRA |= 0xF0;
}

void delay_ms(void){
  volatile uint32_t i;
  for(i=0; i<400000; i++);
}

void loop() {
  // 1. Turn ON Upper Nibble
  // We use the OR operator to set the top 4 bits High.
  PORTA |= 0xF0;
  delay_ms();

  // 2. Turn OFF Upper Nibble
  // We use the AND operator with the inverse of 0xF0 (which is 0x0F)
  // to clear the top 4 bits while keeping the bottom 4 bits unchanged.
  PORTA &= ~0xF0;
  delay_ms();
}
```

## What I Learnt
-   **Nibbles**: How to target the Upper Nibble (`0xF0`) vs Lower Nibble (`0x0F`).
-   **Hex Notation**: `0xF0` is a very common shorthand for `11110000`.
-   **Addressing**: Always double-check your port addresses (`0x21` for `DDRA`).

## Circuit Diagram (JSON Schematic)

```json
{
  "version": 1,
  "author": "ShravanaHS",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-resistor", "id": "r1", "top": 80,  "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led1", "top": 80,  "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r2", "top": 140, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led2", "top": 140, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r3", "top": 200, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led3", "top": 200, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r4", "top": 260, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led4", "top": 260, "left": 310, "attrs": { "color": "red" } }
  ],
  "connections": [
    [ "mega:26", "r1:1", "green", [] ], [ "r1:2", "led1:A", "green", [] ], [ "led1:K", "mega:GND.1", "black", [] ],
    [ "mega:27", "r2:1", "blue",  [] ], [ "r2:2", "led2:A", "blue",  [] ], [ "led2:K", "mega:GND.1", "black", [] ],
    [ "mega:28", "r3:1", "green", [] ], [ "r3:2", "led3:A", "green", [] ], [ "led3:K", "mega:GND.1", "black", [] ],
    [ "mega:29", "r4:1", "blue",  [] ], [ "r4:2", "led4:A", "blue",  [] ], [ "led4:K", "mega:GND.1", "black", [] ]
  ]
}
```

> **Pin Mapping**: Port A Bits 4-7 = Pins 26-29 (PA4=Pin26, PA5=Pin27, PA6=Pin28, PA7=Pin29). Each LED via 220Ω to GND.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/450287714714116097)
