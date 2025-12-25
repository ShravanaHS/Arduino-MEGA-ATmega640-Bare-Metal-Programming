# ETALVIS_LED_Set_3_Problem_10

## Objective
Sequentially turn on LEDs from 7 down to 0, keeping previous LEDs on (Accumulate Reverse).

## Bare Metal Logic
This code configures **Port A** (Registers `DDRA`, `PORTA`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRA (0x21)`: Data Direction Register for Port A. Set to `0xFF` to configure all pins as outputs.
  - `PORTA (0x22)`: Data Register for Port A.
- **Operation**:
  - The loop initializes `i` to 7.
  - Uses `PORTA |= (1<<i)` to turn on the i-th bit without modifying others.
  - It decrements `i`.
  - Effect: 7 on -> 7,6 on -> 7,6,5 on -> ... -> all 8 on.

## Wokwi Link
[Problem 10 Simulation](https://wokwi.com/projects/451233531907399681)

## Code
```c
// pattern 7,76,765,7654,76543,765432,7654321,76543210
//0,01,012,0123,01234,.....01234567
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
    for (uint8_t i = 7; i >=0; i--) {
      PORTA |= (1<<i);
      delay1sec();
    }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
