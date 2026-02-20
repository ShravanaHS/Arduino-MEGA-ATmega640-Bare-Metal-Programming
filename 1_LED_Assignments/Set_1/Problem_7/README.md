# Set 1 Problem 7: All LEDs Blink (Port F)

## Problem Statement
Connect eight LEDs to the entire **Port F** (Bits 0-7).
Blink all 8 LEDs together.

## Simple Explanation
We are using the entire "power strip". All 8 sockets are active.
-   Turn EVERYTHING ON (`11111111`).
-   Turn EVERYTHING OFF (`00000000`).

## Hardware Setup
-   **Port Used**: Port F
-   **Pins**: Bits 0-7.
-   **Registers**:
    -   `DDRF` (Data Direction Register F): Address `0x30`.
    -   `PORTF` (Port F Data Register): Address `0x31`.

## Code Analysis

```c
#include <stdint.h>

// --- Register Definitions ---
#define DDRF  (*(volatile uint8_t*)0x30)
#define PORTF (*(volatile uint8_t*)0x31)

void setup() {
  // Set all 8 bits to Output.
  // 0xFF is Hex for 255, which is 11111111 in Binary.
  DDRF |= 0xFF;
}

void delay_ms(void){
  volatile uint32_t i;
  for(i=0; i<400000; i++);
}

void loop() {
  // 1. Turn ON all LEDs
  PORTF |= 0xFF;
  delay_ms();

  // 2. Turn OFF all LEDs
  // ~(0xFF) is 0x00 (00000000).
  // This clears all bits on Port F.
  PORTF &= ~0xFF;
  delay_ms();
}
```

## What I Learnt
-   **Hexadecimal `0xFF`**: The shortcut for "All bits ones". This is the standard way to manipulate a full byte.
-   **Port F**: Often used for Analog Inputs on Arduino, but perfectly capable of Digital Output.
-   **Efficiency**: Writing `PORTF = 0xFF` is faster and simpler than setting pins individualy.

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
    { "type": "wokwi-led",      "id": "led2", "top": 100, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r3", "top": 150, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led3", "top": 150, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r4", "top": 200, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led4", "top": 200, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r5", "top": 250, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led5", "top": 250, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r6", "top": 300, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led6", "top": 300, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r7", "top": 350, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led7", "top": 350, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r8", "top": 400, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led8", "top": 400, "left": 310, "attrs": { "color": "red" } }
  ],
  "connections": [
    [ "mega:A0", "r1:1", "green", [] ], [ "r1:2", "led1:A", "green", [] ], [ "led1:K", "mega:GND.1", "black", [] ],
    [ "mega:A1", "r2:1", "blue",  [] ], [ "r2:2", "led2:A", "blue",  [] ], [ "led2:K", "mega:GND.1", "black", [] ],
    [ "mega:A2", "r3:1", "green", [] ], [ "r3:2", "led3:A", "green", [] ], [ "led3:K", "mega:GND.1", "black", [] ],
    [ "mega:A3", "r4:1", "blue",  [] ], [ "r4:2", "led4:A", "blue",  [] ], [ "led4:K", "mega:GND.1", "black", [] ],
    [ "mega:A4", "r5:1", "green", [] ], [ "r5:2", "led5:A", "green", [] ], [ "led5:K", "mega:GND.1", "black", [] ],
    [ "mega:A5", "r6:1", "blue",  [] ], [ "r6:2", "led6:A", "blue",  [] ], [ "led6:K", "mega:GND.1", "black", [] ],
    [ "mega:A6", "r7:1", "green", [] ], [ "r7:2", "led7:A", "green", [] ], [ "led7:K", "mega:GND.1", "black", [] ],
    [ "mega:A7", "r8:1", "blue",  [] ], [ "r8:2", "led8:A", "blue",  [] ], [ "led8:K", "mega:GND.1", "black", [] ]
  ]
}
```

> **Pin Mapping**: Port F Bits 0-7 = MEGA Analog Pins A0-A7 (used as digital output). 8 LEDs each via 220Ω resistor to GND.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/450287734852019201)
