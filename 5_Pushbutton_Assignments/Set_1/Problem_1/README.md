# Set 1 Problem 1: Basic Pushbutton Blink (PB0)

## Problem Statement
Write a program to blink all LEDs connected to **PORT A** when the first pushbutton (PB0) on **PORT B** is pressed.

## Simple Explanation
We are building a simple "light switch" system.
-   **Input**: A button connected to Port B, pin 0. The microcontroller "reads" this pin to see if it's pressed (High/1) or not (Low/0).
-   **Output**: 8 LEDs connected to Port A. When the button is pressed, we send a signal to turn them all ON, wait, then turn them OFF.

## Hardware Setup
-   **LEDs**: Connected to **PORT A (PA0-PA7)** (Arduino Mega digital pins 22-29).
-   **Button**: Connected to **PORT B (PB0)** (Arduino Mega digital pin 53).
-   **Registers Used**:
    -   `DDRA`: Set to `0xFF` (Output) for LEDs.
    -   `DDRB`: Set to `0x00` (Input) for Buttons.
    -   `PORTA`: Writes data to LEDs (ON/OFF).
    -   `PINB`: Reads data from Buttons.

## Code Analysis

```c
#include <stdint.h>
#define DDRA   (*(volatile uint8_t*)0x21)
#define PORTA  (*(volatile uint8_t*)0x22)
#define PINB   (*(volatile uint8_t*)0x23)
#define DDRB   (*(volatile uint8_t*)0x24)

void delay(void){
    for(volatile uint32_t i=0;i<50000;i++);
}

int main(void){
    // 1. Configure Port A as Output (LEDs)
    // 0xFF means 11111111 -> All 8 pins are outputs
    DDRA = 0xFF; 
    
    // 2. Configure Port B as Input (Buttons)
    // 0x00 means 00000000 -> All 8 pins are inputs
    DDRB = 0x00; 

    while(1){
        // 3. Check if PB0 is pressed
        // We us logic AND (&) with 0x01 (00000001) to isolate bit 0.
        // If the result is 0x01, it means pin 0 is HIGH (pressed).
        if((PINB & 0x01) == 0x01){ 
            PORTA = 0xFF; // Turn all LEDs ON
            delay();
            PORTA = 0x00; // Turn all LEDs OFF
            delay();
        } else {
            PORTA = 0x00; // Keep LEDs OFF if button not pressed
        }
    }
}
```

## Circuit Diagram (JSON Schematic)

```json
{
  "version": 1,
  "author": "ShravanaHS",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0, "attrs": {} },
    { "type": "wokwi-resistor", "id": "r0", "top": 50, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l0", "top": 50, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r1", "top": 75, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l1", "top": 75, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r2", "top": 100, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l2", "top": 100, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r3", "top": 125, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l3", "top": 125, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r4", "top": 150, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l4", "top": 150, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r5", "top": 175, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l5", "top": 175, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r6", "top": 200, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l6", "top": 200, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r7", "top": 225, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led", "id": "l7", "top": 225, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-pushbutton", "id": "btn0", "top": 320, "left": 220, "attrs": {} }
  ],
  "connections": [
    ["mega:22","r0:1","red",[]], ["r0:2","l0:A","red",[]], ["l0:K","mega:GND.1","black",[]],
    ["mega:23","r1:1","red",[]], ["r1:2","l1:A","red",[]], ["l1:K","mega:GND.1","black",[]],
    ["mega:24","r2:1","red",[]], ["r2:2","l2:A","red",[]], ["l2:K","mega:GND.1","black",[]],
    ["mega:25","r3:1","red",[]], ["r3:2","l3:A","red",[]], ["l3:K","mega:GND.1","black",[]],
    ["mega:26","r4:1","red",[]], ["r4:2","l4:A","red",[]], ["l4:K","mega:GND.1","black",[]],
    ["mega:27","r5:1","red",[]], ["r5:2","l5:A","red",[]], ["l5:K","mega:GND.1","black",[]],
    ["mega:28","r6:1","red",[]], ["r6:2","l6:A","red",[]], ["l6:K","mega:GND.1","black",[]],
    ["mega:29","r7:1","red",[]], ["r7:2","l7:A","red",[]], ["l7:K","mega:GND.1","black",[]],
    ["mega:53","btn0:1.l","blue",[]], ["btn0:2.r","mega:GND.1","black",[]]
  ]
}
```

> **Pin Mapping**: PORTA (Pins 22-29) = 8 LEDs. PORTB Pin 53 (PB0) = Pushbutton input.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452183870812217345)
