# ETALVIS_LED_Set_1_Problem_4

## Objective
Connect two LEDs to port C bit 6 & bit 7. Glow MSB 2 LEDs only (bit 7 & bit 6)

## Bare Metal Logic
- **Register Addresses**:
  - `DDRC` (Data Direction Register for Port C) is accessed at address `0x27`.
  - `PORTC` (Data Register for Port C) is accessed at address `0x28`.
- **Volatile Pointers**:
  - Code uses preprocessor macros: `#define cddr (*(volatile uint8_t*)0x27)`.
- **Bitwise Operations**:
  - `(1<<6) | (1<<7)` targets bits 6 and 7.
  - Used to set both pins as output and to toggle them High/Low.

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450287676924481537)

## Code
```c
// Connect two LEDs to port C bit 6 & bit 7. Glow MSB 2 LEDs only (bit 7 & bit 6)
//27ddr 28 port


#include <stdint.h>

#define cport (*(volatile uint8_t*)0x28)
#define cddr  (*(volatile uint8_t*)0x27)

void setup() {
  cddr |= (1<<6) | (1<<7);
}

void delayy(void){
  volatile uint32_t i;
  for(i = 0; i < 100000; i++);
}

void loop() {
  cport |= (1<<6) | (1<<7);
  delayy();
  cport &= ~((1<<6) | (1<<7));
  delayy();
}
```

## Visual
![Simulation Output](./output.png)
