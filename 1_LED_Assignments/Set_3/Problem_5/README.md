# Set 3 Problem 5: Complex Hex Patterns (Port A)

## Problem Statement
Connect 8 LEDs to **Port A**.
Flash them in custom pair groups:
1.  0 & 1.
2.  6 & 7.
3.  2 & 3.
4.  4 & 5.

## Simple Explanation
We are lighting up 2-bit chunks (Pairs) at random locations.
We pre-calculate the "Hex Codes" for these pairs and store them in an array.

## Hardware Setup
-   **Port A**: Address `0x22`.

## Code Analysis

```c
#include <stdint.h>
#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

// Pre-Calculated Hex Patterns
// 0x03 (00000011) -> Bits 0, 1
// 0xC0 (11000000) -> Bits 6, 7
// 0x0C (00001100) -> Bits 2, 3
// 0x30 (00110000) -> Bits 4, 5
uint8_t pattern[4] = {
    0x03, 
    0xC0, 
    0x0C, 
    0x30  
};

void delay1sec(void){
    TCNT1 = 0; TCCR1A = 0x00; TCCR1B = 0x05;
    while (TCNT1 < 15625) ;
    TCCR1B = 0x00;
}

void setup() {
    DDRA = 0xFF;
}

void loop() {
    for (uint8_t i = 0; i < 4; i++) {
        // Directly write the hex pattern to the port
        PORTA = pattern[i];
        delay1sec();
        
        // Turn Off
        PORTA = 0x00;
        delay1sec();
    }
}
```

## What I Learnt
-   **Hexadecimal Mastery**: Instead of writing `(1<<0)|(1<<1)`, we can mathematically condense it to `0x03`. This makes the code shorter and faster to execute (no shifting math at runtime, just a direct memory copy).

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451230414750740481)
