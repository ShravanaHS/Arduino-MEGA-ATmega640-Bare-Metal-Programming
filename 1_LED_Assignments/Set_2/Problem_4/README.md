# Set 2 Problem 4: Single Blink with Total Clear (Port C)

## Problem Statement
Connect 8 LEDs to **Port C**.
Blink them one by one (0 to 7).
**Difference from Problem 3**: In Problem 3, we turned off the specific bit using `&= ~`. Here, we turn off *everything* using `= 0x00`.

## Simple Explanation
1.  Turn On Light X. Wait.
2.  Turn Off EVERYTHING. Wait.
3.  Turn On Light X+1. Wait.
4.  Turn Off EVERYTHING. Wait.

## Hardware Setup
-   **Port C**: Address `0x28`.

## Code Analysis

```c
#include <stdint.h>
#define DDRC  (*(volatile uint8_t*)0x27)
#define PORTC (*(volatile uint8_t*)0x28)

// Precise 1-second delay
void delay1sec(void){
    TCNT1  = 0; TCCR1A = 0x00; TCCR1B = 0x05;          
    while (TCNT1 < 15625);
    TCCR1B = 0x00;          
}

void setup() {
    DDRC = 0xFF;            
}

void loop() {
    for (uint8_t i = 0; i < 8; i++) {
        // 1. Turn ON ONLY the current LED
        // Using '=' (Assignment) instead of '|=' (OR).
        // This sets 'i' to 1 and FORCES all others to 0 immediately.
        PORTC = (1 << i);   
        delay1sec();
        
        // 2. Turn OFF everything
        PORTC = 0x00;       
        delay1sec();
    }
}
```

## What I Learnt
-   **Assignment (`=`) vs OR (`|=`)**:
    -   `PORTC = (1<<i)`: "Make Port C look exactly like this pattern (only bit i is ON)." Safe if you own the whole port.
    -   `PORTC |= (1<<i)`: "Turn on bit i, leave others alone." Safer if other pins serve different purposes.
-   **Simplification**: Clearing with `0x00` is simpler than calculating individual bitmasks if you know you want everything off.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451214774943659009)
