# Set 1 Problem 10: Specific Pattern Blink (Port E)

## Problem Statement
Connect LEDs to **Port E**.
Blink specifically the LEDs at **Bits 5, 4, 3, and 1**.

## Simple Explanation
We are picking a specific group of lights to control.
-   We want 5, 4, 3, 1 ON.
-   We want 7, 6, 2, 0 OFF.
-   Binary Map: `0` (7) `0` (6) `1` (5) `1` (4) `1` (3) `0` (2) `1` (1) `0` (0) -> `00111010` (Hex `0x3A`).

## Hardware Setup
-   **Port Used**: Port E
-   **Pins**: Bits 1, 3, 4, 5.
-   **Registers**:
    -   `DDRE` (Data Direction Register E): Address `0x2D`.
    -   `PORTE` (Port E Data Register): Address `0x2E`.

## Code Analysis

```c
#include <stdint.h>

// --- Register Definitions ---
#define PORTE (*(volatile uint8_t*)0x2E)
#define DDRE  (*(volatile uint8_t*)0x2D)

void setup() {
  // Set all pins to Output
  DDRE = 0xFF;
}

void delay_ms(void){
  volatile uint32_t i;
  for(i = 0; i < 400000; i++);
}

void loop() {
  // 1. Apply our specific pattern
  // 0x3A is Hex for 00111010.
  // Breaks down as: 
  // 3 (0011) -> Bits 5 and 4 ON
  // A (1010) -> Bits 3 and 1 ON
  PORTE = 0x3A;
  delay_ms();

  // 2. Turn everything OFF
  PORTE = 0x00;
  delay_ms();
}
```

## What I Learnt
-   **Custom Patterns**: How to convert any requested LED combination into a single Hex number.
-   **Hex Conversion**:
    -   `0011` (Upper 4 bits) -> `3`
    -   `1010` (Lower 4 bits) -> `A` (Ten)
    -   Combined -> `0x3A`.
-   **Register Mapping**: Standardizing on names like `PORTE` helps anyone reading the code understand exactly which hardware block is being used.

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
    { "type": "wokwi-led",      "id": "led2", "top": 140, "left": 310, "attrs": { "color": "blue" } },
    { "type": "wokwi-resistor", "id": "r3", "top": 200, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led3", "top": 200, "left": 310, "attrs": { "color": "green" } },
    { "type": "wokwi-resistor", "id": "r4", "top": 260, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led4", "top": 260, "left": 310, "attrs": { "color": "yellow" } }
  ],
  "connections": [
    [ "mega:2",  "r1:1", "green",  [] ], [ "r1:2", "led1:A", "green",  [] ], [ "led1:K", "mega:GND.1", "black", [] ],
    [ "mega:5",  "r2:1", "blue",   [] ], [ "r2:2", "led2:A", "blue",   [] ], [ "led2:K", "mega:GND.1", "black", [] ],
    [ "mega:3",  "r3:1", "green",  [] ], [ "r3:2", "led3:A", "green",  [] ], [ "led3:K", "mega:GND.1", "black", [] ],
    [ "mega:4",  "r4:1", "yellow", [] ], [ "r4:2", "led4:A", "yellow", [] ], [ "led4:K", "mega:GND.1", "black", [] ]
  ]
}
```

> **Pin Mapping**: Port E Bits 1,3,4,5 = MEGA Pins 2,5,3,4 respectively. Pattern 0x3A = 00111010.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/450288106353088513)
