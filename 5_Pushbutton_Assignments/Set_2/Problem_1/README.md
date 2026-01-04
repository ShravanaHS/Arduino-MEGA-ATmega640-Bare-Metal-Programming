# Set 2 Problem 1: PB1 Sequence (1, 2, 5, 6)

## Problem Statement
Write a program to blink LEDs in the sequence **1 -> 2 -> 5 -> 6** when **PB1** is pressed.

## Simple Explanation
-   **Trigger**: Press PB1 (Pin 52 - Arduino / Port B Bit 1).
-   **Sequence**: LED 1 ON/OFF -> LED 2 ON/OFF -> LED 5 ON/OFF -> LED 6 ON/OFF.
-   **Delay**: 1 second between steps using Timer1.

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.
-   **Button**: Connected to **PORT B (PB1)**.

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
        if (PINB & (1 << 1)) { // PB1 Pressed
            // Sequence: 1, 2, 5, 6
            PORTA = (1 << 1); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 2); delay1sec(); PORTA = 0; delay1sec();
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
