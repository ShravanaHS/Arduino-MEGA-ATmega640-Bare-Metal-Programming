# ETALVIS_LED_Set_3_Problem_5

## Objective
Glow the LEDs in the following order of pairs: (0,1), (6,7), (2,3), (4,5).

## Bare Metal Logic
This code configures **Port A** (Registers `DDRA`, `PORTA`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRA (0x21)`: Data Direction Register for Port A. Set to `0xFF` to configure all pins as outputs.
  - `PORTA (0x22)`: Data Register for Port A.
- **Operation**:
  - Uses an array `pattern[4] = {0x03, 0xC0, 0x0C, 0x30}`.
    - `0x03`: bits 0 & 1.
    - `0xC0`: bits 6 & 7.
    - `0x0C`: bits 2 & 3.
    - `0x30`: bits 4 & 5.
  - The loop iterates from `i = 0` to `3`.
  - Sets `PORTA` to the pattern value, waits 1 second, then turns off all LEDs (`0x00`) and waits again.

## Wokwi Link
[Problem 5 Simulation](https://wokwi.com/projects/451230414750740481)

## Code
```c
//glow the leds in following order 01,67,23,45
#include <stdint.h>

#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t pattern[4] = {
    0x03, // 01
    0xC0, // 67
    0x0C, // 23
    0x30  // 45
};

void delay1sec(void){
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    while (TCNT1 < 15625) ;
    TCCR1B = 0x00;
}

void setup() {
    DDRA = 0xFF;
}

void loop() {
    for (uint8_t i = 0; i < 4; i++) {
        PORTA = pattern[i];
        delay1sec();
        PORTA = 0x00;
        delay1sec();
    }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
