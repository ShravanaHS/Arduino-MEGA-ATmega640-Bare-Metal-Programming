# Set 2 Problem 4: PB5 Sequence (3, 5, 7, 6)

## Problem Statement
Write a program to blink LEDs in the sequence **3 -> 5 -> 7 -> 6** when **PB5** is pressed.

## Simple Explanation
-   **Trigger**: Press PB5 (Port B Bit 5).
-   **Sequence**: LED 3 -> LED 5 -> LED 7 -> LED 6.

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.
-   **Button**: Connected to **PORT B (PB5)**.

## Code Analysis

```c
#include <stdint.h>
#define DDRA   (*(volatile uint8_t*)0x21)
#define PORTA  (*(volatile uint8_t*)0x22)
#define PINB   (*(volatile uint8_t*)0x23)
#define DDRB   (*(volatile uint8_t*)0x24)

#define TCNT1  (*(volatile uint16_t*)0x84)
#define TCCR1A (*(volatile uint8_t*)0x80)
#define TCCR1B (*(volatile uint8_t*)0x81)

void delay1sec(void){
    TCNT1 = 0; TCCR1A = 0x00; TCCR1B = 0x05; 
    while(TCNT1 < 15625); TCCR1B = 0x00;
}

int main(void){
    DDRA = 0xFF; // Output
    DDRB = 0x00; // Input
    while(1){
        if (PINB & (1 << 5)) { // PB5 Pressed
            // Sequence: 3, 5, 7, 6
            PORTA = (1 << 3); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 5); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 7); delay1sec(); PORTA = 0; delay1sec();
            PORTA = (1 << 6); delay1sec(); PORTA = 0; delay1sec();
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
    { "type": "wokwi-resistor", "id": "r0", "top": 50,  "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "l0", "top": 50,  "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r1", "top": 75,  "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "l1", "top": 75,  "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r2", "top": 100, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "l2", "top": 100, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r3", "top": 125, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "l3", "top": 125, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r4", "top": 150, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "l4", "top": 150, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r5", "top": 175, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "l5", "top": 175, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r6", "top": 200, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "l6", "top": 200, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-resistor", "id": "r7", "top": 225, "left": 220, "attrs": { "value": "220" } },
    { "type": "wokwi-led",      "id": "l7", "top": 225, "left": 290, "attrs": { "color": "red" } },
    { "type": "wokwi-pushbutton", "id": "btn0", "top": 290, "left": 220, "attrs": {} },
    { "type": "wokwi-pushbutton", "id": "btn1", "top": 320, "left": 220, "attrs": {} },
    { "type": "wokwi-pushbutton", "id": "btn2", "top": 350, "left": 220, "attrs": {} },
    { "type": "wokwi-pushbutton", "id": "btn3", "top": 380, "left": 220, "attrs": {} }
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
    ["mega:52","btn1:1.l","blue",[]], ["btn1:2.r","mega:GND.1","black",[]],
    ["mega:51","btn2:1.l","blue",[]], ["btn2:2.r","mega:GND.1","black",[]],
    ["mega:50","btn3:1.l","blue",[]], ["btn3:2.r","mega:GND.1","black",[]]
  ]
}
```

> **Pin Mapping**: PORTA (Pins 22-29) = 8 LEDs. PB0-PB3 (Pins 53,52,51,50) = 4 Pushbuttons.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452196801538531329)
