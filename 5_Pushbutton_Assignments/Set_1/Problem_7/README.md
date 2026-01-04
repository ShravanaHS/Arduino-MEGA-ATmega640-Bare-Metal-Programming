# Set 1 Problem 7: Direct LED Mapping

## Problem Statement
Write a program where pressing a specific pushbutton (PB0-PB7) turns on the corresponding LED (LED0-LED7). For example, pressing PB4 turns on LED4.

## Simple Explanation
-   **Input**: Any button on Port B.
-   **Output**: The matching LED on Port A.
-   **Logic**: We scan all 8 bits. If a specific bit `i` is set in the input (button pressed), we turn on the corresponding bit `i` in the output.

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.
-   **Buttons**: Connected to **PORT B**.

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
        uint8_t btn = PINB;
        if(btn != 0x00){
            for(uint8_t i=0; i<8; i++){
                // Check if the i-th button is pressed
                if(btn == (1<<i)){
                    PORTA = (1<<i); // Turn on i-th LED
                    delay1sec();
                    PORTA = 0x00;
                    delay1sec();
                }
            }
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452187995574876161)
