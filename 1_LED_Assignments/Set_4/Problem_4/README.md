# Set 4 Problem 4: Parallel Sequential Blink

## Problem Statement
Blink LEDs from Left to Right (0 to 7) on **Port A** and **Port B** simultaneously.

## Code Analysis

```c
#include <stdint.h>

#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

#define DDRB  (*(volatile uint8_t*)0x24)
#define PORTB (*(volatile uint8_t*)0x25)

void delay1sec(void){
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;        // prescaler 1024
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

void setup() {
    DDRA = 0xFF;          // Row 1 output
    DDRB = 0xFF;          // Row 2 output
}

void loop() {
    // Both rows mirror each other
    for (uint8_t i = 0; i < 8; i++) {
        PORTA = (1 << i);    // Row 1 LED
        PORTB = (1 << i);    // Row 2 LED
        delay1sec();
    }
}
```

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/451306062951152641)
