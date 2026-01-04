# Set 1 Problem 4: Reverse Sequential Blink (Any Button)

## Problem Statement
Write a program to blink LEDs from **7 down to 0** (Reverse Order) when **any** pushbutton on Port B is pressed.

## Simple Explanation
-   **Input**: Any button press on Port B (checking if input is not zero).
-   **Output**: The LEDs light up in a "reverse chaser" pattern, starting from LED 7 (Pin 29) down to LED 0 (Pin 22).

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
        // Check if ANY button is pressed (PINB is not 0)
        if (PINB != 0x00) { 
            // Loop from 7 down to 0
            for (int8_t j = 7; j >= 0; j--) {
                PORTA = (1 << j); // Turn on LED at position j
                delay1sec();
            }
            PORTA = 0x00; // Ensure all off after sequence
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452186460932438017)
