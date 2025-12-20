# ETALVIS_LED_Set_1_Problem_3

## Objective
Connect LEDs to Port H, bit 6 and bit 0. Blink them.
*(Note: Problem statement comment was missing in the source code; objective inferred from code logic.)*

## Bare Metal Logic
- **Register Addresses**:
  - `DDRH` (Data Direction Register for Port H) is accessed at address `0x101`.
  - `PORTH` (Data Register for Port H) is accessed at address `0x102`.
- **Volatile Pointers**:
  - Used `#define` macros with pointer casting: `#define DDRH (*(volatile uint8_t*)0x101)`.
- **Bitwise Operations**:
  - `(1 << 6) | (1 << 0)` selects both bit 6 and bit 0.
  - Used for setting direction and toggling the pins.

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450284628790415361)

## Code
```c
#include <stdint.h>

#define DDRH  (*(volatile uint8_t*)0x101)
#define PORTH (*(volatile uint8_t*)0x102)

void setup() {
  DDRH |= (1 << 6) | (1 << 0);
}

void DELAY(void) {
  volatile uint32_t i;
  for (i = 0; i < 1000000; i++);
}

void loop() {
  PORTH |= (1 << 6) | (1 << 0);    
  DELAY();
  PORTH &= ~(1 << 6) & ~(1 << 0);  // LED OFF
  DELAY();
}
```

## Visual
![Simulation Output](./output.png)
