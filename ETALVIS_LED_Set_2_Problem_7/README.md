# ETALVIS_LED_Set_2_Problem_7

## Objective
connect 8 leds to port L glow 0-3 leds one by one

## Bare Metal Logic
This code configures **Port L** (Registers `DDRL`, `PORTL`) to drive LEDs 0-3.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRL (0x10A)`: Data Direction Register for Port L. Bits 0-3 are set to 1.
  - `PORTL (0x10B)`: Data Register for Port L.
  - `TCNT1`, `TCCR1A`, `TCCR1B`: Timer1 registers used for the 1-second delay.
- **Sequence**:
  - The loop iterates from 0 to 3.
  - It turns ON one LED at a time (`PORTL = (1 << i)`), waits 1 second, then turns it OFF, and waits another second.

## Wokwi Link
[Problem 7 Simulation](https://wokwi.com/projects/450854181787164673)

## Code
```c
//connect 8 leds to port L glow 0-3 leds one by one
#include <stdint.h>

#define DDRL (*(volatile uint8_t*)0x10A)
#define PORTL (*(volatile uint8_t*)0x10B)

void delay1sec(void){
  TCNT1 = 0;
  TCCR1A = 0x00;
  TCCR1B = 0x05;

  while (TCNT1 < 15625);

  TCCR1B = 0x00;
}

void setup() {
  DDRL |= (1<<0) | (1<<1) | (1<<2) | (1<<3);
}

void loop() {
  for (uint8_t i = 0; i < 4; i++) {
    PORTL = (1 << i);
    delay1sec();
    PORTL = 0x00;
    delay1sec();
  }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
