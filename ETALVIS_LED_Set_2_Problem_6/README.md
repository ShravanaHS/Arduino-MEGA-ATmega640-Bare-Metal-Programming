# ETALVIS_LED_Set_2_Problem_6

## Objective
blink even leds in port k

## Bare Metal Logic
This code configures **Port K** (Registers `DDRK`, `PORTK`) to drive LEDs.
- **Header**: `#include <stdint.h>`
- **Registers**:
  - `DDRK (0x30)`: Data Direction Register for Port K. Set to `0xFF` to configure pins as outputs.
  - `PORTK (0x31)`: Data Register for Port K.
  - `TCNT1`, `TCCR1A`, `TCCR1B`: Timer1 registers used for the 1-second delay.
- **Sequence**:
  - The loop iterates from 0 to 7, incrementing by 1 in the loop statement AND by 1 inside the loop body (`i += 1`), resulting in a step of 2.
  - This effectively targets even indices (0, 2, 4, 6).
  - Turns ON the ith LED, waits 1 second, turns it OFF, waits 1 second.

## Wokwi Link
[Problem 6 Simulation](https://wokwi.com/projects/450851741143461889)

## Code
```c
//blink even leds in port k

#include <stdint.h>

#define DDRK  (*(volatile uint8_t*)0x30)
#define PORTK (*(volatile uint8_t*)0x31)

void delay1sec(void){
    TCNT1  = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;      

    while (TCNT1 < 15625);

    TCCR1B = 0x00;      
}

void setup() {
    DDRK = 0xFF;        
}

void loop() {
  for(int i =0; i<8 ; i++){
    PORTK |= (1<<i);
    delay1sec();
    PORTK &= ~(1<<i);
    delay1sec();
    i += 1; 
  }
}
```

## Visuals
![Wiring Diagram](placeholder_image_link_or_description)
