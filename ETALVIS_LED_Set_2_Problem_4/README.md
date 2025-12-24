# ETALVIS_LED_Set_2_Problem_4

## Objective
connect 8 led to port c blink one by one

## Bare Metal Logic
This code configures **Port C** (Registers `DDRC`, `PORTC`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRC (0x27)`: Data Direction Register for Port C. Set to `0xFF` to configure all 8 pins as outputs.
  - `PORTC (0x28)`: Data Register for Port C.
  - `TCNT1`, `TCCR1A`, `TCCR1B`: Timer1 registers used for the 1-second delay.
- **Sequence**:
  - The loop iterates from 0 to 7.
  - In each iteration, it turns ON the ith LED (`PORTC = (1 << i)`).
  - Waits for 1 second.
  - Turns ALL LEDs OFF (`PORTC = 0x00`).
  - Waits for 1 second.
  - This ensures that only one LED blinks at a time, followed by a dark period.

## Wokwi Link
[Problem 4 Simulation](https://wokwi.com/projects/451214774943659009)

## Code
```c
//connect 8 led to port c blink one by one

#include <stdint.h>

#define DDRC  (*(volatile uint8_t*)0x27)
#define PORTC (*(volatile uint8_t*)0x28)

void delay1sec(void){
    TCNT1  = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;          

    while (TCNT1 < 15625);

    TCCR1B = 0x00;          
}

void setup() {
    DDRC = 0xFF;            
}

void loop() {
    for (uint8_t i = 0; i < 8; i++) {
        PORTC = (1 << i);   
        delay1sec();
        PORTC = 0x00;       
        delay1sec();
    }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
