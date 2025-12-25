# ETALVIS_LED_Set_3_Problem_7

## Objective
Glow LEDs in the following groups: (0,1,2), then (5,6,7), then (3,4).

## Bare Metal Logic
This code configures **Port A** (Registers `DDRA`, `PORTA`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRA (0x21)`: Data Direction Register for Port A. Set to `0xFF` to configure all pins as outputs.
  - `PORTA (0x22)`: Data Register for Port A.
- **Operation**:
  - Uses `pattern[3] = {0x07, 0xE0, 0x18}`.
    - `0x07`: bits 0, 1, 2.
    - `0xE0`: bits 5, 6, 7.
    - `0x18`: bits 3, 4.
  - The loop iterates from `i = 0` to `2`.
  - Turns on LEDs based on the pattern, waits, turns them off, and waits again.

## Wokwi Link
[Problem 7 Simulation](https://wokwi.com/projects/451233275591356417)

## Code
```c
//glow the led in the following pattern 0,1,2  5,6,7  3,4
#include <stdint.h>

#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t pattern[3] = {
    0x07,   // 0,1,2
    0xE0,   // 5,6,7
    0x18    // 3,4
};

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
    for (uint8_t i = 0; i < 3; i++) {
        PORTA = pattern[i];
        delay1sec();
        PORTA = 0x00;
        delay1sec();
    }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
