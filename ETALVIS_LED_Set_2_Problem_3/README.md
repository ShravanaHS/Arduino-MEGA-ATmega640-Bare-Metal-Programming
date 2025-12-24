# ETALVIS_LED_Set_2_Problem_3

## Objective
connect 8 leds to port A blink them all (Note: Code uses Port C)

## Bare Metal Logic
This code configures **Port C** (Registers `DDRC`, `PORTC`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRC (0x27)`: Data Direction Register for Port C. Set to `0xFF` via bitwise ORing all 8 bits.
  - `PORTC (0x28)`: Data Register for Port C.
  - `TCNT1`, `TCCR1A`, `TCCR1B`: Timer1 registers used for delay.
- **Sequence**:
  - The loop iterates from 0 to 7.
  - Inside the loop, it turns ON the ith LED on Port C.
  - Waits for 1 second.
  - Turns OFF that specific LED.
  - Waits for 1 second.
  - Repeats for the next LED.

## Wokwi Link
[Problem 3 Simulation](https://wokwi.com/projects/450840620058693633)

## Code
```c
//connect 8 leds to port A blink them all

#include <stdint.h>

#define DDRC (*(volatile uint8_t*)0x27)
#define PORTC (*(volatile uint8_t*)0x28)

void delay1sec(void){
    TCNT1 = 0;        
    TCCR1A = 0x00;    
    TCCR1B = 0x05;   

    while (TCNT1 < 15625); 

    TCCR1B = 0x00;   
}

void setup() {
  // put your setup code here, to run once:
  DDRC |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0 ; i < 8 ; i++){
    PORTC |= (1<<i);
    delay1sec();
    PORTC &= ~((1<<i));
    delay1sec();
  }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
