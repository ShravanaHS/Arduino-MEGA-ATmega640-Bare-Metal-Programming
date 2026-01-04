# Set 1 Problem 10: Multi-LED Pattern (PB0)

## Problem Statement
Write a program to turn on LEDs **0, 3, 4, and 7** simultaneously when **PB0** is pressed.

## Simple Explanation
-   **Input**: PB0 (Bit 0).
-   **Output**: A specific pattern of LEDs.
-   **Binary Logic**: We want bits 0, 3, 4, 7 to be 1.
    -   Bit 0: `0000 0001` (0x01)
    -   Bit 3: `0000 1000` (0x08)
    -   Bit 4: `0001 0000` (0x10)
    -   Bit 7: `1000 0000` (0x80)
    -   Combined: `1001 1001` -> Hex **0x99**.

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

void delay(void){
    for(volatile uint32_t i=0;i<50000;i++);
}

int main(void){
    DDRA = 0xFF;
    DDRB = 0x00;
    
    while(1){
        if(PINB & (1 << 0)){ // PB0
            PORTA = 0x99; // Turn on LEDs 0, 3, 4, 7
        } else {
            PORTA = 0x00;
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452189448813191169)
