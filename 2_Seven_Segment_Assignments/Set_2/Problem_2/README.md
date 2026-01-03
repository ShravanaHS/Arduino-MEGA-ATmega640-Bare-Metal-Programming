# Set 2 Problem 2: Common Anode 0-9 Sequence

## Objective
Connect a **Common Anode** 7-Segment Display to **Port A** and display the numbers 0 to 9 in sequence.

## Hardware Configuration
- **Port:** Port A
- **Device:** 7-Segment Display (Common Anode)
- **Connections:**
  - Port A (PA0-PA7) -> Segments A-DP
  - Common Pin -> VCC (5V)

## Registers Used
- `DDRA`
- `PORTA`
- `TCCR1A`, `TCCR1B`, `TCNT1` (Timer1)

## Code Analysis
The code uses the same `seg` lookup table as Problem 1.
To display digits on a Common Anode display:
- Logic 0 turns a segment ON.
- Logic 1 turns a segment OFF.
The code uses the bitwise NOT operator `~seg[i]` to invert the signals for the Common Anode configuration.
It iterates 0-9 with a 1-second delay (loop calls `delay1sec()`).

## Source Code
```c
// print 0-9 on  common anode 7 segment display with the 1sec delay hardware same as assignment 1 set 1 for all exp
//select common anode and connect common pin to vcc
#include <stdint.h>

#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t seg[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

void delay1sec(void){
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

int main(void){
    DDRA = 0x7F; // Set Port A (PA0-PA6) as output

    while (1){
      volatile uint8_t i = 0;
      for(i = 0; i<10; i++){
        PORTA = ~seg[i]; // Bitwise NOT for common anode
        delay1sec();
      }
    }
}
```

## Simulation
[View Simulation on Wokwi](https://wokwi.com/projects/452037095608515585)

## Visuals
![Simulation Screenshot](./simulation_screenshot.png)
