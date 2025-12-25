# ETALVIS_LED_Set_3_Problem_9

## Objective
Sequentially turn on LEDs from 0 to 7, keeping previous LEDs on (Accumulate).

## Bare Metal Logic
This code configures **Port A** (Registers `DDRA`, `PORTA`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRA (0x21)`: Data Direction Register for Port A. Set to `0xFF` to configure all pins as outputs.
  - `PORTA (0x22)`: Data Register for Port A.
- **Operation**:
  - The loop iterates from `i = 0` to `7`.
  - Uses bitwise OR assignment `PORTA |= (1<<i)` to turn on the i-th bit without modifying other bits.
  - Since bits are never cleared in the loop, LEDs accumulate: 0 -> 0,1 -> 0,1,2 -> ... -> all 8.

## Wokwi Link
[Problem 9 Simulation](https://wokwi.com/projects/451233426803376129)

## Code
```c
//0,01,012,0123,01234,.....01234567

#include <stdint.h>

#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)


void delay1sec(void){
    TCNT1 = 0;
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
        PORTA |= (1<<i);
        delay1sec();
    }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
