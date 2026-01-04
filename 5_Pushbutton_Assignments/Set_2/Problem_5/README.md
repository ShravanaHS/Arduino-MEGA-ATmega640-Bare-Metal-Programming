# Set 2 Problem 5: PB7 Sequence (0, 1, 4, 7)

## Problem Statement
Write a program to blink LEDs in the sequence **0 -> 1 -> 4 -> 7** when **PB7** is pressed.

## Simple Explanation
-   **Trigger**: Press PB7 (Port B Bit 7).
-   **Sequence**: LED 0 -> LED 1 -> LED 4 -> LED 7.

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.
-   **Button**: Connected to **PORT B (PB7)**.

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
    TCNT1 = 0; TCCR1A = 0x00; TCCR1B = 0x05; 
    while(TCNT1 < 15625); TCCR1B = 0x00;
}

int main(void){
    DDRA = 0xFF; // Output
    DDRB = 0x00; // Input
    while(1){
        // Bit 7 is 1000 0000 (0x80)
        if (PINB & (1 << 7)) { // PB7 Pressed
            // Sequence: 0, 1, 4, 7
            PORTA = (1 << 0); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 1); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 4); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 7); delay1sec(); PORTA = 0; delay1sec();
        } else {
            PORTA = 0x00;
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452196801538531329)
