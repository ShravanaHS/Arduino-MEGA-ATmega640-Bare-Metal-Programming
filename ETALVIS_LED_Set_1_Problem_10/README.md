# ETALVIS_LED_Set_1_Problem_10

## Objective
Connect Eight LEDs to port E bit 0 to bit 7. Glow LEDs of bit5, bit4, bit3, bit1

## Bare Metal Logic
- **Register Addresses**:
  - `DDRE` (Data Direction Register for Port E) is accessed at address `0x2D`.
  - `PORTE` (Data Register for Port E) is accessed at address `0x2E`.
- **Volatile Pointers**:
  - `volatile uint8_t*` casting for direct memory access.
- **Bitwise/Hex Operations**:
  - `0x3A` (Binary `00111010`) turns on bits 1, 3, 4, and 5.

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450288106353088513)

## Code
```c
//Connect Eight LEDs to port E bit 0 to bit 7. Glow LEDs of bit5, bit4, bit3, bit1

#include <stdint.h>

#define eport (*(volatile uint8_t*)0x2E)
#define eddr  (*(volatile uint8_t*)0x2D)

void delayy(void){
  volatile uint32_t i;
  for(i = 0; i < 100000; i++);
}

void setup() {
  eddr = 0xFF;
}

void loop() {
  eport = 0x3A;
  delayy();
  eport = 0x00;
  delayy();
}
```

## Visual
![Simulation Output](./output.png)
