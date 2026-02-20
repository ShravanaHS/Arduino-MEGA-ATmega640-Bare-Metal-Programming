# Set 1 Problem 3: Sequential LED Blink (PB3)

## Problem Statement
Write a program to blink LEDs 0 through 7 sequentially (one by one) when the pushbutton on **PB3** is pressed.

## Simple Explanation
When you press the button connected to Pin 3 of Port B:
1.  The system helps detection.
2.  It then runs a "chaser" light pattern: LED 0 turns ON, then LED 1, and so on up to LED 7.
3.  Each LED stays on for approx 1 second (using a precise timer delay).

## Hardware Setup
-   **LEDs**: Connected to **PORT A**.
-   **Button**: Connected to **PORT B (PB3)** (Arduino Mega digital pin 50).

## Code Analysis

```c
#include <stdint.h>
#define DDRA   (*(volatile uint8_t*)0x21)
#define PORTA  (*(volatile uint8_t*)0x22)
#define PINB   (*(volatile uint8_t*)0x23)
#define DDRB   (*(volatile uint8_t*)0x24)

// Timer Registers for precise delay
#define TCNT1  (*(volatile uint16_t*)0x84)
#define TCCR1A (*(volatile uint8_t*)0x80)
#define TCCR1B (*(volatile uint8_t*)0x81)

void delay1sec(void){
    TCNT1 = 0;              // Reset Timer Counter to 0
    TCCR1A = 0x00;          // Normal operation
    TCCR1B = 0x05;          // Set Prescaler to 1024 (slows down clock)
    while(TCNT1 < 15625);   // Wait for count to reach 15625 (approx 1s at 16MHz/1024)
    TCCR1B = 0x00;          // Stop timer
}

int main(void){
    DDRA = 0xFF;
    DDRB = 0x00;
    
    while(1){
        // Check PB3: 0x08 is 00001000 in binary (4th bit, index 3)
        if((PINB & 0x08) == 0x08){ 
            for(uint8_t j=0; j<8; j++){
                // Shift '1' to the left by 'j' positions to turn on specific LED
                PORTA = (1<<j); 
                delay1sec();
                PORTA = 0x00; // Turn off before next
                delay1sec();
            }
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
    { "type": "wokwi-pushbutton", "id": "btn1", "top": 320, "left": 220, "attrs": {} },
    { "type": "wokwi-pushbutton", "id": "btn2", "top": 350, "left": 220, "attrs": {} }
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
    ["mega:51","btn2:1.l","blue",[]], ["btn2:2.r","mega:GND.1","black",[]]
  ]
}
```

> **Pin Mapping**: PORTA (Pins 22-29) = 8 LEDs. PB0 (Pin 53) = Btn1. PB1 (Pin 52) = Btn2. PB2 (Pin 51) = Btn3.

## Visuals
![Simulation Output](./simulation_screenshot.png)
[Click here to run the simulation on Wokwi](https://wokwi.com/projects/452185839910126593)
