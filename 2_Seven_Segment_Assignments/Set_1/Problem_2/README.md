# Set 1 Problem 2: Display '1' on 7-Segment

## Objective
Connect a 7-Segment Display to **Port A** and display the number '1'.

## Hardware Configuration
- **Port:** Port A
- **Device:** 7-Segment Display
- **Connections:**
  - Port A (PA0-PA7) -> Segments A-DP

## Registers Used
- `DDRA`
- `PORTA`

## Code Analysis
The code sets `DDRA` to output (`0x7F`) and `PORTA` to `0x06`.
`0x06` corresponds to binary `0000 0110`.
Assuming mapping A=Bit0, B=Bit1, C=Bit2...
- Bit 1 (B) is High
- Bit 2 (C) is High
For a **Common Cathode** display, this activates segments B and C, which forms the digit '1'.
(Note: If the display were Common Anode, `0x06` would turn ON all segments except B and C).

## Source Code
```c
//connect port A to 7 segment display and print 1
#include <stdint.h>

#define DDRA (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

void setup() {
    DDRA = 0x7F;      
    PORTA = 0x06;     
}

void loop() {
    
}
```

## Simulation
[View Simulation on Wokwi](https://wokwi.com/projects/452037010100276225)

## Visuals
![Simulation Screenshot](./simulation_screenshot.png)
