# Set 4 Problem 10: Reverse Pair Blink

## Problem Statement
Blink pairs of LEDs in reverse order (7-6 to 1-0) on **Port A** and **Port B**.
Pairs: (6,7), (4,5), (2,3), (0,1).

## Code Analysis

```c
#include <stdint.h>

#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

#define DDRB (*(volatile uint8_t*)0x24)
#define PORTB (*(volatile uint8_t*)0x25)

void delay1sec(void){
  TCNT1 = 0;
  TCCR1A = 0x00;
  TCCR1B = 0x05;      // prescaler 1024
  while (TCNT1 < 15625);
  TCCR1B = 0x00;
}

void setup() {
  DDRA = 0xFF;        // Row 1 output
  DDRB = 0xFF;        // Row 2 output
}

void loop() {
  // i starts at 6 and goes down to 0
  for (int8_t i = 6; i >= 0; i -= 2) {
    // 0x03 is 00000011.
    // Shifting it by 6 gives 11000000 (Bits 7 and 6).
    uint8_t mask = (0x03 << i);  

    PORTA = mask;      // Row 1
    PORTB = mask;      // Row 2

    delay1sec();
  }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451306204462786561)
