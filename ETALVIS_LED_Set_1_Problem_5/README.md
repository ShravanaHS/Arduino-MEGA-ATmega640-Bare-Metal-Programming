# ETALVIS_LED_Set_1_Problem_5

## Objective
Connect four LEDs to port A bit 0 to bit 3. Glow LSB 4 LEDs only (bit 0 to bit 3)

## Bare Metal Logic
- **Register Addresses**:
  - `DDRA` (Data Direction Register for Port A) is accessed at address `0x21`.
  - `PORTA` (Data Register for Port A) is accessed at address `0x22`.
- **Volatile Pointers**:
  - Code uses preprocessor macros: `#define addr (*(volatile uint8_t*)0x21)`.
- **Bitwise Operations**:
  - `(1<<0) | (1<<1) | (1<<2) | (1<<3)` targets the lower 4 bits (nibble).
  - Used to set direction and toggle states.

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450287693884152833)

## Code
```c
// Connect four LEDs to port A bit 0 to bit 3. Glow LSB 4 LEDs only (bit 0 to bit 3)
#include <stdint.h>
#define aport (*(volatile uint8_t*)0x22)
#define addr (*(volatile uint8_t*)0x21)
void setup() {
  // put your setup code here, to run once:
  addr |= (1<<0) |(1<<1) | (1<<2) | (1<<3);

}

void delayy(void){
  volatile uint32_t i;
  for(i = 0; i < 100000; i++);
}

void loop() {
  // put your main code here, to run repeatedly:
  aport |= (1<<0) |(1<<1) | (1<<2) | (1<<3);
  delayy();

  aport &= ~((1<<0) | (1<<1) | (1<<2) | (1<<3));
  delayy();
}
```

## Visual
![Simulation Output](./output.png)
