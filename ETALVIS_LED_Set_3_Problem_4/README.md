# ETALVIS_LED_Set_3_Problem_4

## Objective
Connect LEDs to Port A and glow them in the order: 0, 2, 1, 3, 4, 6, 5, 7.

## Bare Metal Logic
This code configures **Port A** (Registers `DDRA`, `PORTA`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRA (0x21)`: Data Direction Register for Port A. Set to `0xFF` to configure all pins as outputs.
  - `PORTA (0x22)`: Data Register for Port A.
- **Operation**:
  - Uses an array `pattern[8] = {0, 2, 1, 3, 4, 6, 5, 7}` to define the sequence.
  - The loop iterates from `i = 0` to `7`.
  - In each iteration, it accesses `pattern[i]` to determine which bit to set.
  - Sets `PORTA = (1 << pattern[i])` to turn on the specific LED.
  - Waits 1 second, turns off all LEDs (`PORTA = 0x00`), and waits again.

## Wokwi Link
[Problem 4 Simulation](https://wokwi.com/projects/451230395192699905)

## Code
```c
//connect leds to port A glow in this order 0,2,1,3,4,6,5,7

#include <stdint.h>

#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t pattern[8] = {0, 2, 1, 3, 4, 6, 5, 7};

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
        PORTA = (1 << pattern[i]);
        delay1sec();
        PORTA = 0x00;
        delay1sec();
    }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
