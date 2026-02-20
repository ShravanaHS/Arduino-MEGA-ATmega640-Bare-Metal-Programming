# Set 1 Problem 8: Odd/Even LED Blink

## Problem Statement
Imagine you have 8 light bulbs connected in a row. Your goal is to make them light up in an alternating pattern:
1.  First, turn on all the LEDs at odd positions (1st, 3rd, 5th, 7th).
2.  Wait for a short time.
3.  Then, turn on all the LEDs at even positions (2nd, 4th, 6th, 8th).
4.  Repeat this forever to create a blinking pattern.

## Simple Explanation
Computers and microcontrollers (like the Arduino Mega) use numbers to control things. To control 8 LEDs at once, we use a single byte (8 bits) of information.
-   Each bit can be `0` (OFF) or `1` (ON).
-   To turn on every other light, we need a pattern like `10101010` or `01010101`.
-   This problem uses these "binary patterns" to switch between two states: "Odd" and "Even".

## Hardware Setup
-   **Port Used**: Port K (An 8-pin connector on the Arduino Mega).
-   **Registers**:
    -   `DDRK` (Data Direction Register K): Controls whether pins are Inputs or Outputs.
    -   `PORTK` (Port K Data Register): Controls whether the pins are High (5V, LED ON) or Low (0V, LED OFF).

## Code Analysis

Here is the code broken down line-by-line:

```c
#include <stdint.h> // Includes standard integer types like uint8_t

// --- Register Definitions ---
// We create "pointers" to the specific memory addresses that control Port K.
// 'volatile' tells the compiler "don't optimize this, the value can change outside your control" (triggered by hardware).
#define kport (*(volatile uint8_t*)0x108) // Address of PORTK
#define kddr  (*(volatile uint8_t*)0x107) // Address of DDRK

void setup() {
  // Set all 8 pins of Port K to OUTPUT mode.
  // 0xFF in Hexadecimal is 11111111 in Binary.
  // 1 means Output, 0 means Input.
  kddr = 0xFF;   
}

// A simple delay function to pause the program so we can see the LEDs blink.
void delayy(void){
  volatile uint32_t i;
  for(i = 0; i < 100000; i++); // Empty loop that just counting up to waste time
}

void loop() {
  // Step 1: Turn on EVEN LEDs
  // 0xAA in Hex is 10101010 in Binary.
  // This turns on LEDs at index 7, 5, 3, 1 (depending on how you count, let's say these are the Even slots).
  kport = 0xAA;  
  delayy(); // Wait

  // Step 2: Turn OFF all LEDs
  // 0x00 is 00000000.
  kport = 0x00;  
  delayy(); // Wait

  // Step 3: Turn on ODD LEDs
  // 0x55 in Hex is 01010101 in Binary.
  // This turns on the other set of LEDs (index 6, 4, 2, 0).
  kport = 0x55;  
  delayy(); // Wait

  // Step 4: Turn OFF all LEDs again
  kport = 0x00;  
  delayy(); // Wait
}
```

## What I Learnt
-   **Hexadecimal Patterns**: `0xAA` (`10101010`) and `0x55` (`01010101`) are perfect opposites. They are standard patterns for checking alternating bits.
-   **Port Manipulation**: Instead of turning on 8 LEDs one by one with `digitalWrite`, we can do it all instantly by writing one number (`0xAA`) to the Port register.
-   **Volatile Keyword**: Essential for Bare Metal programming to ensure the compiler doesn't ignore our direct hardware access.

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
    { "type": "wokwi-led",      "id": "led2", "top": 100, "left": 310, "attrs": { "color": "blue" } },
    { "type": "wokwi-resistor", "id": "r3", "top": 150, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led3", "top": 150, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r4", "top": 200, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led4", "top": 200, "left": 310, "attrs": { "color": "blue" } },
    { "type": "wokwi-resistor", "id": "r5", "top": 250, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led5", "top": 250, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r6", "top": 300, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led6", "top": 300, "left": 310, "attrs": { "color": "blue" } },
    { "type": "wokwi-resistor", "id": "r7", "top": 350, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led7", "top": 350, "left": 310, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r8", "top": 400, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "led8", "top": 400, "left": 310, "attrs": { "color": "blue" } }
  ],
  "connections": [
    [ "mega:A8",  "r1:1", "green", [] ], [ "r1:2", "led1:A", "green", [] ], [ "led1:K", "mega:GND.1", "black", [] ],
    [ "mega:A9",  "r2:1", "blue",  [] ], [ "r2:2", "led2:A", "blue",  [] ], [ "led2:K", "mega:GND.1", "black", [] ],
    [ "mega:A10", "r3:1", "green", [] ], [ "r3:2", "led3:A", "green", [] ], [ "led3:K", "mega:GND.1", "black", [] ],
    [ "mega:A11", "r4:1", "blue",  [] ], [ "r4:2", "led4:A", "blue",  [] ], [ "led4:K", "mega:GND.1", "black", [] ],
    [ "mega:A12", "r5:1", "green", [] ], [ "r5:2", "led5:A", "green", [] ], [ "led5:K", "mega:GND.1", "black", [] ],
    [ "mega:A13", "r6:1", "blue",  [] ], [ "r6:2", "led6:A", "blue",  [] ], [ "led6:K", "mega:GND.1", "black", [] ],
    [ "mega:A14", "r7:1", "green", [] ], [ "r7:2", "led7:A", "green", [] ], [ "led7:K", "mega:GND.1", "black", [] ],
    [ "mega:A15", "r8:1", "blue",  [] ], [ "r8:2", "led8:A", "blue",  [] ], [ "led8:K", "mega:GND.1", "black", [] ]
  ]
}
```

> **Pin Mapping**: Port K Bits 0-7 = MEGA Analog Pins A8-A15. Red LEDs = 0xAA pattern (bits 7,5,3,1). Blue LEDs = 0x55 pattern (bits 6,4,2,0).

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/450288060923527169)
