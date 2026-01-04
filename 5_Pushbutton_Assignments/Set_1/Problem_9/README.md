# Set 1 Problem 9: Continuous Sequence

## Problem Statement
Write a program to run a continuous LED chaser sequence (0 to 7) indefinitely. (Note: The simulation runs the sequence without waiting for a button, essentially testing the delay logic).

## Simple Explanation
-   **Logic**: No input check. Simply loop from 0 to 7 inside the main infinite loop.
-   **Output**: LEDs light up one after another continuously.

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.

## Code Analysis

```c
#include <stdint.h>
#define DDRA   (*(volatile uint8_t*)0x21)
#define PORTA  (*(volatile uint8_t*)0x22)
#define PINB   (*(volatile uint8_t*)0x23)
#define DDRB   (*(volatile uint8_t*)0x24)

#define TCNT1  (*(volatile uint16_t*)0x84)
#define TCCR1A (*(volatile uint8_t*)0x80)
#define TCCR1B (*(volatile uint8_t*)0x81)

void delay1sec(void){
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05; 
    while(TCNT1 < 15625);
    TCCR1B = 0x00;
}

int main(void){
    DDRA = 0xFF;
    DDRB = 0x00;
    
    while(1){
        // Loop 0 to 7
        for(uint8_t i = 0; i < 8; i++){
            PORTA = (1 << i);
            delay1sec();
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452189299531608065)
