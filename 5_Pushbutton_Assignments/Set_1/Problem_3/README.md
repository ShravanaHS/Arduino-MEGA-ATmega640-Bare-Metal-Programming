# Set 1 Problem 3: Sequential LED Blink (PB3)

## Problem Statement
Write a program to blink LEDs 0 through 7 sequentially (one by one) when the pushbutton on **PB3** is pressed.

## Simple Explanation
When you press the button connected to Pin 3 of Port B:
1.  The system helps detection.
2.  It then runs a "chaser" light pattern: LED 0 turns ON, then LED 1, and so on up to LED 7.
3.  Each LED stays on for approx 1 second (using a precise timer delay).

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.
-   **Button**: Connected to **PORT B (PB3)** (Arduino Mega digital pin 50).

## Code Analysis

```c
#include <stdint.h>
#define DDRA   (*(volatile uint8_t*)0x21)
#define PORTA  (*(volatile uint8_t*)0x22)
#define PINB   (*(volatile uint8_t*)0x23)
#define DDRB   (*(volatile uint8_t*)0x24)

// Timer Registers for precise delay
#define TCNT1  (*(volatile uint16_t*)0x84)
#define TCCR1A (*(volatile uint8_t*)0x80)
#define TCCR1B (*(volatile uint8_t*)0x81)

void delay1sec(void){
    TCNT1 = 0;              // Reset Timer Counter to 0
    TCCR1A = 0x00;          // Normal operation
    TCCR1B = 0x05;          // Set Prescaler to 1024 (slows down clock)
    while(TCNT1 < 15625);   // Wait for count to reach 15625 (approx 1s at 16MHz/1024)
    TCCR1B = 0x00;          // Stop timer
}

int main(void){
    DDRA = 0xFF;
    DDRB = 0x00;
    
    while(1){
        // Check PB3: 0x08 is 00001000 in binary (4th bit, index 3)
        if((PINB & 0x08) == 0x08){ 
            for(uint8_t j=0; j<8; j++){
                // Shift '1' to the left by 'j' positions to turn on specific LED
                PORTA = (1<<j); 
                delay1sec();
                PORTA = 0x00; // Turn off before next
                delay1sec();
            }
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452185839910126593)
