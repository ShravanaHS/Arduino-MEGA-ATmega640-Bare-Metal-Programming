# Set 1 Problem 2: Alternate Pushbutton Blink (PB1)

## Problem Statement
Write a program to blink all LEDs connected to **PORT A** when the second pushbutton (PB1) on **PORT B** is pressed.

## Simple Explanation
This is very similar to Problem 1, but we are listening to a different switch.
-   **Input**: A button connected to Port B, pin 1 (the second pin).
-   **Logic**: We need to check the second bit of the input register. If it's High, we trigger the blink sequence.

## Hardware Setup
-   **LEDs**: Connected to **PORT A (PA0-PA7)**.
-   **Button**: Connected to **PORT B (PB1)** (Arduino Mega digital pin 52).
-   **Registers Used**: same as Problem 1.

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
    DDRA = 0xFF; // Output for LEDs
    DDRB = 0x00; // Input for Buttons

    while(1){
        // 3. Check if PB1 is pressed
        // We mask with 0x02 (00000010 in binary) to check the 2nd bit.
        if((PINB & 0x02) == 0x02){ 
            PORTA = 0xFF; // All LEDs ON
            delay();
            PORTA = 0x00; // All LEDs OFF
            delay();
        } else {
            PORTA = 0x00;
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452185679404594177)
