# ETALVIS_LED_Set_1_Problem_2

## Objective
Connect a LED to port D bit 7. Glow MSB LED only (bit 7)

## Bare Metal Logic
- **Register Addresses**:
  - `DDRD` (Data Direction Register for Port D) is accessed at address `0x2A`.
  - `PORTD` (Data Register for Port D) is accessed at address `0x2B`.
- **Volatile Pointers**:
  - The code uses preprocessor macros to cast integer addresses to `volatile uint8_t*` pointers and dereference them directly: `#define DDDR (*(volatile uint8_t*)0x2A)`.
  - This allows reading/writing to registers like variables.
- **Bitwise Operations**:
  - `(1<<7)` is used to target the 7th bit (MSB).
  - `|=` sets the bit (direction output or High).
  - `&= ~` clears the bit (Low).

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450221318023254017)

## Code
```c
//Problem: Connect a LED to port D bit 7. Glow MSB LED only (bit 7)


#include <stdint.h>

#define DPORT (*(volatile uint8_t*)0x2B)
#define DDDR (*(volatile uint8_t*)0x2A)

void setup() {
  // put your setup code here, to run once:
  DDDR |= (1<<7); 
}

void delay(void) {
  volatile uint32_t i;
  for (i = 0; i < 1000000; i++);
}
void loop() {
  // put your main code here, to run repeatedly: 
  DPORT &= ~(1<<7);
  delay();
  DPORT |= (1<<7);
  delay();
}
```

## Visual
![Simulation Output](./output.png)
