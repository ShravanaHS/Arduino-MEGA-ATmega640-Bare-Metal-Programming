# Set 3 Problem 4: Custom Array Sequence (Port A)

## Problem Statement
Connect 8 LEDs to **Port A**.
Blink them in a **Custom Chaotic Order**: 0, 2, 1, 3, 4, 6, 5, 7.

## Simple Explanation
Instead of 1-2-3-4 (Counting), we want to jump around.
We use a "lookup table" (an Array) to tell us where to go next.
-   Step 0: Go to LED 0.
-   Step 1: Go to LED 2.
-   Step 2: Go to LED 1.
...

## Hardware Setup
-   **Port A**: Address `0x22`.

## Code Analysis

```c
#include <stdint.h>
#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

// The Lookup Table
// We define the specific order we want here.
uint8_t pattern[8] = {0, 2, 1, 3, 4, 6, 5, 7};

void delay1sec(void){
    TCNT1  = 0; TCCR1A = 0x00; TCCR1B = 0x05;
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

void setup() {
    DDRA = 0xFF; // All Output
}

void loop() {
    // Iterate through the 8 steps of our sequence
    for (uint8_t i = 0; i < 8; i++) {
        // Read the target LED pin from the array using 'i' as the index.
        uint8_t targetPin = pattern[i];
        
        // Turn ON that pin
        PORTA = (1 << targetPin);
        delay1sec();
        
        // Turn OFF
        PORTA = 0x00;
        delay1sec();
    }
}
```

## What I Learnt
-   **Lookup Tables (LUTs)**: Using an array to store data (the sequence) separates the *Logic* (the loop) from the *Data* (the pattern). This is powerful. If we want to change the visual pattern later, we only change the numbers in `{...}`, not the code!

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451230395192699905)
