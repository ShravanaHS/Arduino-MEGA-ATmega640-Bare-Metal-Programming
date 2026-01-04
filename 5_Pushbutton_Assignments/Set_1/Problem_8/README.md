# Set 1 Problem 8: Reverse Mapping (PB0 -> LED7)

## Problem Statement
Write a program where pressing a specific pushbutton turns on the LED at the **opposite** end of the array.
-   PB0 (Bit 0) -> Turns on LED 7 (Bit 7).
-   PB1 (Bit 1) -> Turns on LED 6 (Bit 6).
-   ...
-   PB7 (Bit 7) -> Turns on LED 0 (Bit 0).

## Simple Explanation
-   **Input**: Any button press.
-   **Logic**: Calculate the target LED by subtracting the button index from 7 (`7 - i`).
-   **Output**: The "mirrored" LED lights up.

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
    DDRA = 0xFF; // Output
    DDRB = 0x00; // Input
    
    while(1){
        uint8_t btn = PINB;
        if(btn != 0x00){
            for(uint8_t i=0; i<8; i++){
                if(btn == (1<<i)){
                    // The logic here is (7 - i)
                    PORTA = (1 << (7 - i));
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
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452188840668442625)
