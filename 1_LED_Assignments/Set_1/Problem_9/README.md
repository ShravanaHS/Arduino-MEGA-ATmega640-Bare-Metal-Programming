# Set 1 Problem 9: Even LED Blink (Port L)

## Problem Statement
Connect eight LEDs to **Port L**.
Blink only the **Even** position LEDs (Bits 0, 2, 4, 6).

## Simple Explanation
We want to light up every alternate socket starting from the first one.
-   Pattern: 1 (On), 0 (Off), 1 (On), 0 (Off), 1 (On), 0 (Off), 1 (On), 0 (Off).
-   Binary: `01010101` (Hex `0x55`). Note: bit 0 is at the right end.

## Hardware Setup
-   **Port Used**: Port L
-   **Pins**: Even bits (0, 2, 4, 6).
-   **Registers**:
    -   `DDRL` (Data Direction Register L): Address `0x10A`.
    -   `PORTL` (Port L Data Register): Address `0x10B`.

## Code Analysis

```c
#include <stdint.h>

// --- Register Definitions ---
#define PORTL (*(volatile uint8_t*)0x10B)
#define DDRL  (*(volatile uint8_t*)0x10A)

void setup() {
  // Set all pins of Port L to Output mode.
  // Even though we only use the Even pins, setting 0xFF makes all 8 pins outputs.
  DDRL = 0xFF;
}

void delay_ms(void){
  volatile uint32_t i;
  for(i = 0; i < 400000; i++);
}

void loop() {
  // 1. Turn ON Even LEDs
  // 0x55 is the Hex code for 01010101.
  // This lights up bits 0, 2, 4, 6.
  PORTL = 0x55;
  delay_ms();

  // 2. Turn OFF all LEDs
  PORTL = 0x00;
  delay_ms();
}
```

## What I Learnt
-   **Magic Number `0x55`**: Memorizing that `0x55` (`01010101`) is the pattern for "Alternating bits starting with 1 at LSB".
-   **Efficient Port Writing**: We can set the complex pattern in a single instruction (`PORTL = 0x55`) rather than setting 4 different pins individually.
-   **Code Clarity**: Using `0x55` makes the intent (alternating pattern) immediately recognizable to experienced programmers.

## Circuit Diagram (JSON Schematic)

```json
{
  "version": 1,
  "author": "ShravanaHS",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-resistor", "id": "r1", "top": 50,  "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led1", "top": 50,  "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r2", "top": 100, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led2", "top": 100, "left": 310, "attrs": { "color": "gray" } },
    { "type": "wokwi-resistor", "id": "r3", "top": 150, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led3", "top": 150, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r4", "top": 200, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led4", "top": 200, "left": 310, "attrs": { "color": "gray" } },
    { "type": "wokwi-resistor", "id": "r5", "top": 250, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led5", "top": 250, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r6", "top": 300, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led6", "top": 300, "left": 310, "attrs": { "color": "gray" } },
    { "type": "wokwi-resistor", "id": "r7", "top": 350, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led7", "top": 350, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r8", "top": 400, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led8", "top": 400, "left": 310, "attrs": { "color": "gray" } }
  ],
  "connections": [
    [ "mega:49", "r1:1", "green", [] ], [ "r1:2", "led1:A", "green", [] ], [ "led1:K", "mega:GND.1", "black", [] ],
    [ "mega:48", "r2:1", "gray",  [] ], [ "r2:2", "led2:A", "gray",  [] ], [ "led2:K", "mega:GND.1", "black", [] ],
    [ "mega:47", "r3:1", "green", [] ], [ "r3:2", "led3:A", "green", [] ], [ "led3:K", "mega:GND.1", "black", [] ],
    [ "mega:46", "r4:1", "gray",  [] ], [ "r4:2", "led4:A", "gray",  [] ], [ "led4:K", "mega:GND.1", "black", [] ],
    [ "mega:45", "r5:1", "green", [] ], [ "r5:2", "led5:A", "green", [] ], [ "led5:K", "mega:GND.1", "black", [] ],
    [ "mega:44", "r6:1", "gray",  [] ], [ "r6:2", "led6:A", "gray",  [] ], [ "led6:K", "mega:GND.1", "black", [] ],
    [ "mega:43", "r7:1", "green", [] ], [ "r7:2", "led7:A", "green", [] ], [ "led7:K", "mega:GND.1", "black", [] ],
    [ "mega:42", "r8:1", "gray",  [] ], [ "r8:2", "led8:A", "gray",  [] ], [ "led8:K", "mega:GND.1", "black", [] ]
  ]
}
```

> **Pin Mapping**: Port L Bits 0-7 = MEGA Pins 49-42. Active (even) LEDs at Bits 0,2,4,6 (Pins 49,47,45,43). Pattern = 0x55.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/450288081398026241)
