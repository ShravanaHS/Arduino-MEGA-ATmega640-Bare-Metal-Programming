# ETALVIS_LED_Set_1_Problem_6

## Objective
Connect four LEDs to port B bit 4 to bit 7. Glow MSB 4 LEDs only (bit 7 to bit 4)

## Bare Metal Logic
- **Register Addresses**:
  - `DDRA` (Data Direction Register for Port A) is accessed at address `0x21`.
  - `PORTA` (Data Register for Port A) is accessed at address `0x22`.
  - *Note: There is a discrepancy between the comment (Port B) and the address used (0x21/0x22 which is Port A). Port B would typically be 0x24/0x25 on ATmega2560.*
- **Volatile Pointers**:
  - `#define addr (*(volatile uint8_t*) 0x21)`
  - `#define aport (*(volatile uint8_t*) 0x22)`
- **Bitwise Operations**:
  - `(1<<7) | (1<<6) | (1<<5) | (1<<4)` selects the upper nibble (MSB 4 bits).
  - Used for direction setting and toggling.

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450287714714116097)

## Code
```c
#include<stdint.h>
//Connect four LEDs to port B bit 4 to bit 7. Glow MSB 4 LEDs only (bit 7 to bit 4)
#define aport (*(volatile uint8_t*) 0x22)
#define addr  (*(volatile uint8_t*) 0x21)

void setup() {
  // put your setup code here, to run once:
  addr |= (1<<7) | (1<<6) | (1<<5) | (1<<4);
}

void delayy(void){
  volatile uint32_t i;
  for(i=0; i<1000000; i++);
}
void loop() {
  // put your main code here, to run repeatedly:
  aport |= (1<<7) | (1<<6) | (1<<5) | (1<<4);
  delayy();
  aport &= ~((1<<7) | (1<<6) | (1<<5) | (1<<4));
  delayy();
}
```

## Visual
![Simulation Output](./output.png)
