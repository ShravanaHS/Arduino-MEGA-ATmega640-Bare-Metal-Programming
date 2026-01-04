# Set 2 Problem 3: PB3 Sequence (0, 1, 5, 6)

## Problem Statement
Write a program to blink LEDs in the sequence **0 -> 1 -> 5 -> 6** when **PB3** is pressed.

## Simple Explanation
-   **Trigger**: Press PB3 (Port B Bit 3).
-   **Sequence**: LED 0 -> LED 1 -> LED 5 -> LED 6.

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.
-   **Button**: Connected to **PORT B (PB3)**.

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
        if (PINB & (1 << 3)) { // PB3 Pressed
            // Sequence: 0, 1, 5, 6
            PORTA = (1 << 0); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 1); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 5); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 6); delay1sec(); PORTA = 0; delay1sec();
        } else {
            PORTA = 0x00;
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452196801538531329)
