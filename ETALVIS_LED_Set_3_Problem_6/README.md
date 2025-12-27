# Set 3 Problem 6: Custom Pattern Reverse (Port A)

## Problem Statement
Connect 8 LEDs to **Port A**.
Flash them in the specified group order:
1.  Pairs (4,5).
2.  Pairs (2,3).
3.  Pairs (6,7).
4.  Pairs (0,1).

## Simple Explanation
We are playing a sequence of 2-LED combinations stored in a predefined list (Array).
We play the list in **Reverse** order (Index 3 down to 0).

## Hardware Setup
-   **Port A**: Address `0x22`.

## Code Analysis

```c
#include <stdint.h>
#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

/* Pattern Map:
 * Index 0 (0x03): Bits 0,1
 * Index 1 (0xC0): Bits 6,7
 * Index 2 (0x0C): Bits 2,3
 * Index 3 (0x30): Bits 4,5
 */
uint8_t pattern[4] = {
  0x03,   // 01
  0xC0,   // 67
  0x0C,   // 23
  0x30    // 45
};

void delay1sec(void){
  TCNT1  = 0; TCCR1A = 0x00; TCCR1B = 0x05;
  while (TCNT1 < 15625);
  TCCR1B = 0x00;
}

void setup() {
  DDRA = 0xFF;
}

void loop() {
  // Start at Index 3 (The last element: 0x30 aka Pair 4,5)
  // Count down to Index 0 (The first element: 0x03 aka Pair 0,1)
  for (int8_t i = 3; i >= 0; i--) {
    PORTA = pattern[i];
    delay1sec();
    PORTA = 0x00;
    delay1sec();
  }
}
```

## What I Learnt
-   **Reverse Array Traversal**: How to access data starting from the end of a list `pattern[3]` back to the start `pattern[0]`.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451230437858215937)
