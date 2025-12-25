# ETALVIS_LED_Set_3_Problem_2

## Objective
Connect 8 LEDs to Port A and blink pairs (0 & 4), (1 & 5), (2 & 6), (3 & 7) sequentially.

## Bare Metal Logic
This code configures **Port A** (Registers `DDRA`, `PORTA`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRA (0x21)`: Data Direction Register for Port A. Set to `0xFF` to configure all pins as outputs.
  - `PORTA (0x22)`: Data Register for Port A.
- **Operation**:
  - The loop iterates from `i = 0` to `3`.
  - In each iteration, it sets `PORTA` to turn on LEDs at bit `i` and `i+4`.
  - It waits for 1 second.
  - It clears `PORTA` (0x00) to turn off all LEDs.
  - It waits for 1 second.
  - This blink pattern is similar to Problem 1 but ensures all other LEDs are off during the "ON" phase by direct assignment.

## Wokwi Link
[Problem 2 Simulation](https://wokwi.com/projects/451230358004944897)

## Code
```c
#include <stdint.h>

#define DDRA  (*(volatile uint8_t*)0x21)
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

void port_led(int i){
    PORTA = (1<<i) | (1<<(i+4));
    delay1sec();
    PORTA = 0x00;
    delay1sec();
}

void loop() {
    for(int i = 0; i <= 3; i++){
        port_led(i);
    }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
