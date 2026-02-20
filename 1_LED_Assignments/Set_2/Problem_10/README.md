# Set 2 Problem 10: Reverse Lower Nibble Blink (Port F)

## Problem Statement
**Goal**: Blink LEDs from 3 down to 0 on **Port F**.
**Important Note on Code Discrepancy**: The original objective states "3 to 0", but the provided code actually implements "7 to 4" (identical to Problem 9). We document the code *as typically provided in the assignment codebase*, but acknowledge this mismatch.

## Simple Explanation
Intended Behavior: Start at Light 3 -> Light 2 -> Light 1 -> Light 0.
Actual Code Behavior: Same as Problem 9 (7 -> 6 -> 5 -> 4).

## Hardware Setup
-   **Port F**: Address `0x31`.

## Code Analysis

```c
#include <stdint.h>
#define DDRF  (*(volatile uint8_t*)0x30)
#define PORTF (*(volatile uint8_t*)0x31)

void delay1sec(void){
    TCNT1  = 0; TCCR1A = 0x00; TCCR1B = 0x05;          
    while (TCNT1 < 15625);
    TCCR1B = 0x00;          
}

void setup() {
    // Configures upper bits (4-7)
    DDRF |= (1<<4) | (1<<5) | (1<<6) | (1<<7);   
}

void loop() {
    // Loops from 7 down to 4
    for (int8_t i = 7; i >= 4; i--) {
        PORTF = (1 << i);   
        delay1sec();
        PORTF = 0x00;       
        delay1sec();
    }
}
```

## What I Learnt
-   **Code Verification**: Sometimes the code doesn't match the comment/objective! Reading the `for` loop parameters (`i=7`, `i>=4`) reveals the *real* behavior of the hardware.
-   **Debugging**: If I connected LEDs to pins 0-3 and ran this code, nothing would happen. This teaches the importance of checking your loop bounds.

## Circuit Diagram (JSON Schematic)

```json
{
  "version": 1,
  "author": "ShravanaHS",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-resistor", "id": "r1", "top": 50,  "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led1", "top": 50,  "left": 310, "attrs": { "color": "gray" } },
    { "type": "wokwi-resistor", "id": "r2", "top": 100, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led2", "top": 100, "left": 310, "attrs": { "color": "gray" } },
    { "type": "wokwi-resistor", "id": "r3", "top": 150, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led3", "top": 150, "left": 310, "attrs": { "color": "gray" } },
    { "type": "wokwi-resistor", "id": "r4", "top": 200, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led4", "top": 200, "left": 310, "attrs": { "color": "gray" } },
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
    [ "mega:A0", "r1:1", "gray",  [] ], [ "r1:2", "led1:A", "gray",  [] ], [ "led1:K", "mega:GND.1", "black", [] ],
    [ "mega:A1", "r2:1", "gray",  [] ], [ "r2:2", "led2:A", "gray",  [] ], [ "led2:K", "mega:GND.1", "black", [] ],
    [ "mega:A2", "r3:1", "gray",  [] ], [ "r3:2", "led3:A", "gray",  [] ], [ "led3:K", "mega:GND.1", "black", [] ],
    [ "mega:A3", "r4:1", "gray",  [] ], [ "r4:2", "led4:A", "gray",  [] ], [ "led4:K", "mega:GND.1", "black", [] ],
    [ "mega:A4", "r5:1", "green", [] ], [ "r5:2", "led5:A", "green", [] ], [ "led5:K", "mega:GND.1", "black", [] ],
    [ "mega:A5", "r6:1", "blue",  [] ], [ "r6:2", "led6:A", "blue",  [] ], [ "led6:K", "mega:GND.1", "black", [] ],
    [ "mega:A6", "r7:1", "green", [] ], [ "r7:2", "led7:A", "green", [] ], [ "led7:K", "mega:GND.1", "black", [] ],
    [ "mega:A7", "r8:1", "blue",  [] ], [ "r8:2", "led8:A", "blue",  [] ], [ "led8:K", "mega:GND.1", "black", [] ]
  ]
}
```

> **Pin Mapping**: Port F Bits 0-7 = MEGA Analog Pins A0-A7. Code behavior is 7→4 reverse (same as P9). Objective states 3→0 but code discrepancy noted.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451214741914558465)
