# ETALVIS_LED_Set_2_Problem_2

## Objective
connect 8 leds to port b blink one by one

## Bare Metal Logic
This code configures **Port B** (Registers `DDRB`, `PORTB`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRB (0x24)`: Data Direction Register for Port B. Set to `0xFF` (all bits 1) to configure pins 50-53 and others as outputs.
  - `PORTB (0x25)`: Data Register for Port B.
  - `TCNT1`, `TCCR1A`, `TCCR1B`: Timer1 registers used for the 1-second delay.
- **Sequence**:
  - The `loop` function sequentially turns on LEDs starting from bit 0 up to bit 7, adding one LED at a time (e.g., bit 0, then bits 0+1, then 0+1+2...), pausing for 1 second, then turning all off for 1 second.

## Wokwi Link
[Problem 2 Simulation](https://wokwi.com/projects/450839093411595265)

## Code
```c
//connect 8 leds to port b blink one by one

#include <stdint.h>

#define DDRB (*(volatile uint8_t*)0x24)
#define PORTB (*(volatile uint8_t*)0x25)

void delay1sec(void){
    TCNT1 = 0;        
    TCCR1A = 0x00;    
    TCCR1B = 0x05;   

    while (TCNT1 < 15625); 

    TCCR1B = 0x00;   
}

void setup() {
  // put your setup code here, to run once:
  DDRB |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB |= (1<<0);
  delay1sec();
  PORTB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
  delay1sec();
  
  PORTB |= (1<<0)|(1<<1);
  delay1sec();
  PORTB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
  delay1sec();

  PORTB |= (1<<0)|(1<<1)|(1<<2);
  delay1sec();
  PORTB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
  delay1sec();

  PORTB |= (1<<0)|(1<<1)|(1<<2)|(1<<3);
  delay1sec();
  PORTB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
  delay1sec();

  PORTB |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4);
  delay1sec();
  PORTB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
  delay1sec();

  PORTB |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
  delay1sec();
  PORTB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
  delay1sec();

  PORTB |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6);
  delay1sec();
  PORTB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
  delay1sec();

  PORTB |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
  delay1sec();
  PORTB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
  delay1sec();
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
