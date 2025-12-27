# Set 3 Problem 7: 3-Bit Groups (Port A)

## Problem Statement
Connect 8 LEDs to **Port A**.
Flash groups of LEDs in this order:
1.  Bottom Three (0, 1, 2).
2.  Top Three (5, 6, 7).
3.  Middle Two (3, 4).

## Simple Explanation
We are lighting up chunks of the LED strip.
-   Chunk A: `00000111` (0x07)
-   Chunk B: `11100000` (0xE0)
-   Chunk C: `00011000` (0x18)

## Hardware Setup
-   **Port A**: Address `0x22`.

## Code Analysis

```c
#include <stdint.h>
#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t pattern[3] = {
    0x07,   // Binary: 00000111 (LEDs 0,1,2)
    0xE0,   // Binary: 11100000 (LEDs 5,6,7)
    0x18    // Binary: 00011000 (LEDs 3,4)
};

void delay1sec(void){
    TCNT1  = 0; TCCR1A = 0x00; TCCR1B = 0x05;
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

void setup() {
    DDRA = 0xFF;
}

void loop() {
    // Cycle through the 3 patterns defined above
    for (uint8_t i = 0; i < 3; i++) {
        PORTA = pattern[i];
        delay1sec();
        PORTA = 0x00;
        delay1sec();
    }
}
```

## What I Learnt
-   **Irregular Groups**: Logic doesn't always have to be mathematical (like "Even numbers"). With Hex Patterns, we can control absolutely any random grouping of LEDs we want.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451233275591356417)
