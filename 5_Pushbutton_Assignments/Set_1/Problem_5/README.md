# Set 1 Problem 5: Even LED Blink (PB0)

## Problem Statement
Write a program to blink only the **Even** LEDs (0, 2, 4, 6) when the pushbutton **PB0** is pressed.

## Simple Explanation
-   **Input**: Button on PB0.
-   **Output**: The LEDs at positions 0, 2, 4, 6 light up one by one.
-   **Logic**: The loop counter increments by 2 (`j += 2`), starting from 0.

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.
-   **Button**: Connected to **PORT B (PB0)**.

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
        if (PINB & 0x01) { // Check PB0
            // Loop 0, 2, 4, 6
            for (uint8_t j = 0; j <= 6; j += 2) {
                PORTA = (1 << j);
                delay1sec();
                PORTA = 0x00;
                delay1sec();
            }
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452187170854083585)
