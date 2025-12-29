# Set 3 Problem 8: Scrambled Groups (Port A)

## Problem Statement
Connect 8 LEDs to **Port A**.
Flash groups in this order:
1.  Middle Two (3, 4).
2.  Top Three (5, 6, 7).
3.  Bottom Three (0, 1, 2).

## Simple Explanation
This repeats the patterns from Problem 7 but changes the **sequence** in which they are played.
-   Start with the center.
-   Jump to the top.
-   Jump to the bottom.

## Hardware Setup
-   **Port A**: Address `0x22`.

## Code Analysis

```c
#include <stdint.h>
#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

// The same hex codes as Problem 7, just re-arranged!
uint8_t pattern[3] = {
    0x18,   // LEDs 3,4
    0xE0,   // LEDs 5,6,7
    0x07    // LEDs 0,1,2
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
    for (uint8_t i = 0; i < 3; i++) {
        PORTA = pattern[i];
        delay1sec();
        PORTA = 0x00;
        delay1sec();
    }
}
```

## What I Learnt
-   **Data-Driven Logic**: To change the animation, I didn't touch the `loop` code at all. I only changed the `pattern` array. This is good software design.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451233349303119873)
