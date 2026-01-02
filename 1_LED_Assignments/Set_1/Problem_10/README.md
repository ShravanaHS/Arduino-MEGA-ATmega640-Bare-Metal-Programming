# Set 1 Problem 10: Specific Pattern Blink (Port E)

## Problem Statement
Connect LEDs to **Port E**.
Blink specifically the LEDs at **Bits 5, 4, 3, and 1**.

## Simple Explanation
We are picking a specific group of lights to control.
-   We want 5, 4, 3, 1 ON.
-   We want 7, 6, 2, 0 OFF.
-   Binary Map: `0` (7) `0` (6) `1` (5) `1` (4) `1` (3) `0` (2) `1` (1) `0` (0) -> `00111010` (Hex `0x3A`).

## Hardware Setup
-   **Port Used**: Port E
-   **Pins**: Bits 1, 3, 4, 5.
-   **Registers**:
    -   `DDRE` (Data Direction Register E): Address `0x2D`.
    -   `PORTE` (Port E Data Register): Address `0x2E`.

## Code Analysis

```c
#include <stdint.h>

// --- Register Definitions ---
#define PORTE (*(volatile uint8_t*)0x2E)
#define DDRE  (*(volatile uint8_t*)0x2D)

void setup() {
  // Set all pins to Output
  DDRE = 0xFF;
}

void delay_ms(void){
  volatile uint32_t i;
  for(i = 0; i < 400000; i++);
}

void loop() {
  // 1. Apply our specific pattern
  // 0x3A is Hex for 00111010.
  // Breaks down as: 
  // 3 (0011) -> Bits 5 and 4 ON
  // A (1010) -> Bits 3 and 1 ON
  PORTE = 0x3A;
  delay_ms();

  // 2. Turn everything OFF
  PORTE = 0x00;
  delay_ms();
}
```

## What I Learnt
-   **Custom Patterns**: How to convert any requested LED combination into a single Hex number.
-   **Hex Conversion**:
    -   `0011` (Upper 4 bits) -> `3`
    -   `1010` (Lower 4 bits) -> `A` (Ten)
    -   Combined -> `0x3A`.
-   **Register Mapping**: Standardizing on names like `PORTE` helps anyone reading the code understand exactly which hardware block is being used.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/450288106353088513)
