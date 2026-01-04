# Set 1 Problem 6: Odd LED Blink (PB6)

## Problem Statement
Write a program to blink only the **Odd** LEDs (1, 3, 5, 7) when the pushbutton **PB6** is pressed.

## Simple Explanation
-   **Input**: Button on PB6 (Pin 12 / Mega Pin 12? No, PB6 is Pin 12 on Arduino mapping for Mega usually 20-53 block, wait. PB6 on Mega is Pin 12. Let's verify: PB0-PB7 are 53, 52, 51, 50, 10, 11, 12, 13).
-   **Output**: The LEDs at positions 1, 3, 5, 7 light up.
-   **Logic**: The loop starts at 1 and increments by 2.

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.
-   **Button**: Connected to **PORT B (PB6)** (Pin 12).

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
        // Check PB6 (Bit 6)
        if (PINB & (1 << 6)) { 
            // Loop 1, 3, 5, 7
            for (uint8_t j = 1; j < 8; j += 2) {
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
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452187512824093697)
