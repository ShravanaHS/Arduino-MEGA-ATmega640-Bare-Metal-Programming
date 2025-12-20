# ETALVIS_LED_Set_1_Problem_8

## Objective
Connect Eight LEDs to PORT K bit 0 to bit 7. Glow ODD and EVEN LEDs alternately

## Bare Metal Logic
- **Register Addresses**:
  - `DDRK` (Data Direction Register for Port K) is accessed at address `0x107`.
  - `PORTK` (Data Register for Port K) is accessed at address `0x108`.
- **Volatile Pointers**:
  - Maps to `volatile uint8_t*`.
- **Bitwise/Hex Operations**:
  - `0xAA` (Binary `10101010`) turns on even-indexed LEDs (assuming 0-indexed, or odd positions 2,4,6,8 depending on counting).
  - `0x55` (Binary `01010101`) turns on odd-indexed LEDs.
  - Used to toggle between odd and even sets.

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450288060923527169)

## Code
```c
// Connect Eight LEDs to PORT K bit 0 to bit 7
// Glow ODD and EVEN LEDs alternately

#include <stdint.h>

#define kport (*(volatile uint8_t*)0x108)
#define kddr  (*(volatile uint8_t*)0x107)

void setup() {
  kddr = 0xFF;   }

void delayy(void){
  volatile uint32_t i;
  for(i = 0; i < 100000; i++);
}

void loop() {
  kport = 0xAA;  
  delayy();

  kport = 0x00;  
  delayy();

  kport = 0x55;  
  delayy();

  kport = 0x00;  
  delayy();
}
```

## Visual
![Simulation Output](./output.png)
