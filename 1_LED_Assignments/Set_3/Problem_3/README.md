# Set 3 Problem 3: Knight Rider Full (Forward & Reverse)

## Problem Statement
Connect 8 LEDs to **Port A**.
1.  Scan Forward: Light 0 to 7 one by one.
2.  Scan Backward: Light 7 to 0 one by one.
This creates a back-and-forth animation.

## Simple Explanation
This is the full "Scanner" effect. The light bounces off the walls.
-   0 -> 1 ... -> 6 -> 7 (Bounce)
-   7 -> 6 ... -> 1 -> 0 (Bounce)

## Hardware Setup
-   **Port A**: Address `0x22`.

## Code Analysis

```c
#include <stdint.h>
#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

void delay1sec(void){
    TCNT1  = 0; TCCR1A = 0x00; TCCR1B = 0x05;        
    while (TCNT1 < 15625);
    TCCR1B = 0x00;        
}

void setup() {
    DDRA = 0xFF;          
}

void loop() {
    // 1. Forward Trace (0 to 7)
    for (uint8_t i = 0; i < 8; i++) {
        PORTA = (1 << i);
        delay1sec();
    }

    // 2. Backward Trace (7 to 0)
    // Note: This will light 7 twice in a row (end of Forward, start of Backward).
    // To make it smooth, we usually start this loop at 6. But let's follow the code given.
    for (int8_t i = 7; i >= 0; i--) {
        PORTA = (1 << i);
        delay1sec();
    }
}
```

## What I Learnt
-   **Two-Phase Animation**: Combining two simple loops (Forward and Reverse) to create a complex behavior.
-   **Signed Integers**: Crucial for the reverse loop `i >= 0`. If `i` was `uint8_t`, `0 - 1` would be `255`, and the loop `255 >= 0` is true, causing a crash/infinite loop.

## Visuals
![Simulation Output](./set3_prob3_screenshot_1766806590750.webp)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451230371206518785)
