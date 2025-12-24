# ETALVIS_LED_Set_2_Problem_1

## Objective
connect 8 leds to port A blink them all

## Bare Metal Logic
This code configures **Port A** (Registers `DDRA`, `PORTA`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRA (0x21)`: Data Direction Register for Port A. Set to `0xFF` (all bits 1) to configure pins 22-29 as outputs.
  - `PORTA (0x22)`: Data Register for Port A. Toggled to turn LEDs on/off.
  - `TCNT1`, `TCCR1A`, `TCCR1B`: Timer1 registers used for creating a precise 1-second delay without blocking (bare metal implementation of delay).

## Wokwi Link
[Problem 1 Simulation](https://wokwi.com/projects/450837212305922049)

## Code
```c
//connect 8 leds to port A blink them all

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
  // put your setup code here, to run once:
  DDRA |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTA |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
  delay1sec();
  PORTA &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
  delay1sec();
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
