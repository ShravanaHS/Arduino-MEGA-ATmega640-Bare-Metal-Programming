# Set 1 Problem 1: Basic Pushbutton Blink (PB0)

## Problem Statement
Write a program to blink all LEDs connected to **PORT A** when the first pushbutton (PB0) on **PORT B** is pressed.

## Simple Explanation
We are building a simple "light switch" system.
-   **Input**: A button connected to Port B, pin 0. The microcontroller "reads" this pin to see if it's pressed (High/1) or not (Low/0).
-   **Output**: 8 LEDs connected to Port A. When the button is pressed, we send a signal to turn them all ON, wait, then turn them OFF.

## Hardware Setup
-   **LEDs**: Connected to **PORT A (PA0-PA7)** (Arduino Mega digital pins 22-29).
-   **Button**: Connected to **PORT B (PB0)** (Arduino Mega digital pin 53).
-   **Registers Used**:
    -   `DDRA`: Set to `0xFF` (Output) for LEDs.
    -   `DDRB`: Set to `0x00` (Input) for Buttons.
    -   `PORTA`: Writes data to LEDs (ON/OFF).
    -   `PINB`: Reads data from Buttons.

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
    // 1. Configure Port A as Output (LEDs)
    // 0xFF means 11111111 -> All 8 pins are outputs
    DDRA = 0xFF; 
    
    // 2. Configure Port B as Input (Buttons)
    // 0x00 means 00000000 -> All 8 pins are inputs
    DDRB = 0x00; 

    while(1){
        // 3. Check if PB0 is pressed
        // We us logic AND (&) with 0x01 (00000001) to isolate bit 0.
        // If the result is 0x01, it means pin 0 is HIGH (pressed).
        if((PINB & 0x01) == 0x01){ 
            PORTA = 0xFF; // Turn all LEDs ON
            delay();
            PORTA = 0x00; // Turn all LEDs OFF
            delay();
        } else {
            PORTA = 0x00; // Keep LEDs OFF if button not pressed
        }
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452183870812217345)
