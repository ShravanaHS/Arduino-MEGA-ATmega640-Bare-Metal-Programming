# ETALVIS_LED_Set_3_Problem_3

## Objective
Connect 8 LEDs to Port A. Glow them 0-7 sequentially with delay, then reverse 7-0 with delay.

## Bare Metal Logic
This code configures **Port A** (Registers `DDRA`, `PORTA`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRA (0x21)`: Data Direction Register for Port A. Set to `0xFF` to configure all pins as outputs.
  - `PORTA (0x22)`: Data Register for Port A.
- **Operation**:
  - **Forward Loop**: Iterates `i` from 0 to 7. Turns on LED at bit `i`.
  - **Reverse Loop**: Iterates `i` from 7 down to 0. Turns on LED at bit `i`.
  - Uses `PORTA = (1 << i)` which ensures only one LED is on at a time.
  - Custom `delay1sec` is used between changes.

## Wokwi Link
[Problem 3 Simulation](https://wokwi.com/projects/451230371206518785)

## Code
```c
//connect 8 LEDs to portA glow 0-7 with delay and reverse it like 7-0 with delay
//same hardware as before ass 1 and 2
#include <stdint.h>

#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

void delay1sec(void){
    TCNT1  = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;        

    while (TCNT1 < 15625);

    TCCR1B = 0x00;        
}

void setup() {
    DDRA = 0xFF;          
}

void loop() {

    
    for (uint8_t i = 0; i < 8; i++) {
        PORTA = (1 << i);
        delay1sec();
    }

    for (int8_t i = 7; i >= 0; i--) {
        PORTA = (1 << i);
        delay1sec();
    }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
