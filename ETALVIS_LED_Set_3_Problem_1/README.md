# ETALVIS_LED_Set_3_Problem_1

## Objective
connect 8 leds to port A glow the leds in this order 37,26,15,04

## Bare Metal Logic
This code configures **Port A** (Registers `DDRA`, `PORTA`) to drive 8 LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRA (0x21)`: Data Direction Register for Port A. Set to `0xFF` to configure all pins as outputs.
  - `PORTA (0x22)`: Data Register for Port A.
- **Operation**:
  - The loop iterates from `i = 0` to `3`.
  - In each iteration, it turns on two LEDs: bit `i` and bit `i+4`.
  - This results in pairs (0,4), (1,5), (2,6), (3,7) lighting up sequentially.
  - Custom `delay1sec` using Timer1 (TCNT1) is used for timing.

## Wokwi Link
[Problem 1 Simulation](https://wokwi.com/projects/451229712541347841)

## Code
```c
// connect 8 leds to port A glow the leds in this order 37,26,15,04
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
  DDRA |= 0xff;
}
int i;
void port(int i){
  
  PORTA |= (1<<i) | (1<<(i+4));
  delay1sec();
  PORTA &= ~((1<<i) | (1<<(i+4)));
  delay1sec();
}
void loop() {

for(int i=0; i<4; i++){
  port(i);
}

}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
