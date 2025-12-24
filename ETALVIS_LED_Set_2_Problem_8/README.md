# ETALVIS_LED_Set_2_Problem_8

## Objective
connect 8 leds to port F blink 4-7 leds one by one

## Bare Metal Logic
This code configures **Port F** (Registers `DDRF`, `PORTF`) to drive LEDs 4-7.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRF (0x30)`: Data Direction Register for Port F. Bits 4-7 are set to 1.
  - `PORTF (0x31)`: Data Register for Port F.
  - `TCNT1`, `TCCR1A`, `TCCR1B`: Timer1 registers used for the 1-second delay.
- **Sequence**:
  - The loop iterates from 4 to 7.
  - It turns ON one LED at a time (`PORTF = (1 << i)`), waits 1 second, then turns it OFF, and waits another second.

## Wokwi Link
[Problem 8 Simulation](https://wokwi.com/projects/451214702764919809)

## Code
```c
//connect 8 leds to port F blink 4-7 leds one by one

#include <stdint.h>

#define DDRF  (*(volatile uint8_t*)0x30)
#define PORTF (*(volatile uint8_t*)0x31)

void delay1sec(void){
    TCNT1  = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;          
    while (TCNT1 < 15625);

    TCCR1B = 0x00;          
}

void setup() {
    DDRF |= (1<<4) | (1<<5) | (1<<6) | (1<<7);   
}

void loop() {
    for (uint8_t i = 4; i < 8; i++) {
        PORTF = (1 << i);   
        delay1sec();
        PORTF = 0x00;       
        delay1sec();
    }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
