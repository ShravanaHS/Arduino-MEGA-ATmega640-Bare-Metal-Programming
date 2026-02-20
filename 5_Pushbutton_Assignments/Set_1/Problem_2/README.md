# Set 1 Problem 2: Alternate Pushbutton Blink (PB1)

## Problem Statement
Write a program to blink all LEDs connected to **PORT A** when the second pushbutton (PB1) on **PORT B** is pressed.

## Simple Explanation
This is very similar to Problem 1, but we are listening to a different switch.
-   **Input**: A button connected to Port B, pin 1 (the second pin).
-   **Logic**: We need to check the second bit of the input register. If it's High, we trigger the blink sequence.

## Hardware Setup
-   **LEDs**: Connected to **PORT A (PA0-PA7)**.
-   **Button**: Connected to **PORT B (PB1)** (Arduino Mega digital pin 52).
-   **Registers Used**: same as Problem 1.

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
    DDRA = 0xFF; // Output for LEDs
    DDRB = 0x00; // Input for Buttons

    while(1){
        // 3. Check if PB1 is pressed
        // We mask with 0x02 (00000010 in binary) to check the 2nd bit.
        if((PINB & 0x02) == 0x02){ 
            PORTA = 0xFF; // All LEDs ON
            delay();
            PORTA = 0x00; // All LEDs OFF
            delay();
        } else {
            PORTA = 0x00;
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
    { "type": "wokwi-pushbutton", "id": "btn0", "top": 290, "left": 220, "attrs": {} },
    { "type": "wokwi-pushbutton", "id": "btn1", "top": 320, "left": 220, "attrs": {} }
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
    ["mega:53","btn0:1.l","blue",[]], ["btn0:2.r","mega:GND.1","black",[]],
    ["mega:52","btn1:1.l","blue",[]], ["btn1:2.r","mega:GND.1","black",[]]
  ]
}
```

> **Pin Mapping**: PORTA (Pins 22-29) = 8 LEDs. PB0 (Pin 53) = Button 1. PB1 (Pin 52) = Button 2.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452185679404594177)
