# Set 3 Problem 10: Accumulate Reverse

## Problem Statement
Imagine filling a glass of water from the top down (conceptually). We want to turn on the LEDs starting from the highest number (LED 7) down to the lowest (LED 0).
**Crucially**, once an LED turns on, it **stays on**.
1.  Turn on LED 7 -> Wait.
2.  Turn on LED 6 (so 7 and 6 are now ON) -> Wait.
3.  Turn on LED 5 (so 7, 6, 5 are ON) -> Wait...
4.  Eventually, all LEDs from 7 to 0 will be ON.

## Simple Explanation
This is like building a tower of blocks, but we are placing the blocks from left to right (or high bit to low bit) and leaving them there.
-   We start with an empty set.
-   We Add "Bit 7".
-   We Add "Bit 6".
-   We are **Accumulating** (gathering) the lights.

## Hardware Setup
-   **Port Used**: Port A.
-   **Direction**: `i--` implies we are counting backwards (Countdown).

## Code Analysis

```c
#include <stdint.h>

// Addresses for Port A
#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

// Accurate 1-second delay using Timer 1
void delay1sec(void){
    TCNT1  = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

void setup() {
    DDRA = 0xFF; // Set all Port A pins to Output
}

void loop() {
    // The Loop: Start 'i' at 7, and go down as long as 'i' is greater than or equal to 0.
    // Decrement 'i' by 1 each time (i--).
    for (int8_t i = 7; i >= 0; i--) {
      
      // The Core Logic: Accumulation
      // We use the OR Operator (|=). 
      // PORTA |= (1<<i) says "Keep whatever bits are already ON, AND turn on bit 'i'".
      // If we used '=', it would erase the old lights. '|=' keeps them.
      PORTA |= (1<<i);
      
      delay1sec();
    }
}
```

## What I Learnt
-   **Accumulation with OR**: The most important lesson here is the difference between `=` (Assignment) and `|=` (Bitwise OR Assignment).
    -   `PORTA = (1<<i)` would turn ON only the current LED and turn OFF the rest.
    -   `PORTA |= (1<<i)` turns ON the current LED and **leaves the others alone**.
-   **Reverse Loops**: How to write a loop that counts backwards (`i--`).
-   **Signed vs Unsigned**: In the loop, we must use a signed integer (`int8_t`) or carefully check `i >= 0`. If we used an `unsigned` byte, `0 - 1` would wrap around to `255`, causing an infinite loop!

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451233531907399681)
