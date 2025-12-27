# Set 3 Problem 9: Accumulate Forward (Port A)

## Problem Statement
Connect 8 LEDs to **Port A**.
Turn them on one-by-one, **keeping them ON**.
1. Light 0.
2. Light 0 + 1.
3. Light 0 + 1 + 2.
...
8. All ON.

## Simple Explanation
This is a "Progress Bar" loading from 0% to 100%.
-   We add one light every second.
-   We never turn them off (until the microcontroller resets or the loop restarts, though the current code doesn't explicitly clear them at the end, so they just stay ON forever after the first pass).

## Hardware Setup
-   **Port A**: Address `0x22`.

## Code Analysis

```c
#include <stdint.h>
#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

void delay1sec(void){
    TCNT1 = 0; TCCR1A = 0x00; TCCR1B = 0x05;
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

void setup() {
    DDRA = 0xFF;
}

void loop() {
    for (uint8_t i = 0; i < 8; i++) {
        // Accumulate
        // '|=' adds the new bit 'i' to the existing pattern.
        PORTA |= (1<<i);
        delay1sec();
    }
    // After this loop finishes, everything stays ON because there is no 'PORTA = 0' command.
}
```

## What I Learnt
-   **Accumulation**: The power of `|=` to Build Up a state over time.
-   **Persistence**: Understanding that hardware output registers hold their value until explicitly changed.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451233426803376129)
