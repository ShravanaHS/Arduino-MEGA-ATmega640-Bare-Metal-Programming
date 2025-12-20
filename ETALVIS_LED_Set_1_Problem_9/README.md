# ETALVIS_LED_Set_1_Problem_9

## Objective
Connect Eight LEDs to port L bit 0 to bit 7. Glow all EVEN position LEDs

## Bare Metal Logic
- **Register Addresses**:
  - `DDRL` (Data Direction Register for Port L) is accessed at address `0x10A`.
  - `PORTL` (Data Register for Port L) is accessed at address `0x10B`.
- **Volatile Pointers**:
  - Used `volatile uint8_t*` pointers mapped to these addresses.
- **Bitwise/Hex Operations**:
  - `0x55` (Binary `01010101`) corresponds to LEDs at bit positions 0, 2, 4, 6 (Even positions).

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450288081398026241)

## Code
```c
//Connect Eight LEDs to port L bit 0 to bit 7. Glow all EVEN position LEDs

#include <stdint.h>

#define lport (*(volatile uint8_t*)0x10B)
#define lddr  (*(volatile uint8_t*)0x10A)

void delayy(void){
  volatile uint32_t i;
  for(i = 0; i < 100000; i++);
}

void setup() {
  lddr = 0xFF;
}

void loop() {
  lport = 0x55;
  delayy();
  lport = 0x00;
  delayy();
}
```

## Visual
![Simulation Output](./output.png)
