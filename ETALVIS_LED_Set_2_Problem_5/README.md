# ETALVIS_LED_Set_2_Problem_5

## Objective
connnect led to port j bit 0 blink it with 1 sec delay

## Bare Metal Logic
This code configures **Port J** (Registers `DDRJ`, `PORTJ`) to drive an LED connected to bit 0.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRJ (0x104)`: Data Direction Register for Port J. Bit 0 is set to 1 to configure it as an output.
  - `PORTJ (0x105)`: Data Register for Port J.
  - `TCNT1`, `TCCR1A`, `TCCR1B`: Timer1 registers used for the 1-second delay.
- **Sequence**:
  - The `setup` function sets Pin 0 of Port J as output.
  - The `loop` continually turns the LED on, waits 1 second, turns it off, and waits 1 second.

## Wokwi Link
[Problem 5 Simulation](https://wokwi.com/projects/451214789547181057)

## Code
```c
//connnect led to port j bit 0 blink it with 1 sec delay
#include <stdint.h>

#define DDRJ  (*(volatile uint8_t*)0x104)
#define PORTJ (*(volatile uint8_t*)0x105)

void delay1sec(void){
    TCNT1  = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;      

    while (TCNT1 < 15625);

    TCCR1B = 0x00;      
}

void setup() {
    DDRJ |= (1 << 0);   
}

void loop() {
    PORTJ |= (1 << 0);  
    delay1sec();

    PORTJ &= ~(1 << 0); 
    delay1sec();
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
