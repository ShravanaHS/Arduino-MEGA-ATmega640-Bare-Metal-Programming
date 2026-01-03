# Set 2 Problem 1: Display 0-9 Sequence

## Objective
Connect a 7-Segment Display to **Port A** and display the numbers 0 to 9 in sequence with a 1-second delay.

## Hardware Configuration
- **Port:** Port A
- **Device:** 7-Segment Display
- **Connections:**
  - Port A (PA0-PA7) -> Segments A-DP

## Registers Used
- `DDRA`
- `PORTA`
- `TCCR1A`, `TCCR1B`, `TCNT1` (Timer1)

## Code Analysis
The code defines the `seg` lookup table for digits 0-9.
The `delay1sec` function is defined to create a 1-second delay using Timer1.
**Note:** In the provided code, `delay1sec()` is defined but **not called** inside the loop. The loop cycles through `PORTA = seg[i]` as fast as possible. To function as intended (1-second counter), the `delay1sec()` call should be uncommented or added.

## Source Code
```c
// print 0-9 on 7 segment display with the 1sec delay hardware same as assignment 1 set 1 problem 2

#include <stdint.h>

#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t seg[10] = {
    0x3F,
    0x06,
    0x5B,
    0x4F,
    0x66,
    0x6D,
    0x7D,
    0x07,
    0x7F,
    0x6F
};

void delay1sec(void){
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

int main(void){
    DDRA = 0x7F;

    while (1){
        volatile uint8_t i = 0;
        for(i = 0; i < 10; i++){
            PORTA = seg[i];
            // delay1sec(); // Missing call
        }
    }
}
```

## Simulation
[View Simulation on Wokwi](https://wokwi.com/projects/452037027766689793)

## Visuals
![Simulation Screenshot](./simulation_screenshot.png)
