# ETALVIS_LED_Set_1_Problem_7

## Objective
Connect Eight LEDs to port F bit 0 to bit 7. Glow all 8 LEDs

## Bare Metal Logic
- **Register Addresses**:
  - `DDRF` (Data Direction Register for Port F) is accessed at address `0x30`.
  - `PORTF` (Data Register for Port F) is accessed at address `0x31`.
- **Volatile Pointers**:
  - Maps `0x30` and `0x31` to `volatile uint8_t*`.
- **Bitwise Operations**:
  - `0xFF` (binary `11111111`) is used to select all 8 bits.
  - Used for direction and output control.

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450287734852019201)

## Code
```c
//Connect Eight LEDs to port F bit 0 to bit 7. Glow all 8 LEDs
#define DDRF  (*(volatile uint8_t*)0x30)
#define PORTF (*(volatile uint8_t*)0x31)
void setup() {
  // put your setup code here, to run once:
  DDRF |= 0XFF;
}

void delayy(void){
  volatile uint32_t i;
  for(i=0; i<1000000; i++);
}
void loop() {
  // put your main code here, to run repeatedly:
  PORTF |= 0XFF;
  delayy();
  PORTF &= ~(0XFF);
  delayy();
}
```

## Visual
![Simulation Output](./output.png)
