# Problem 1: Show Button Pressed on 7 Segment Display

## Problem Statement
Show the pressed button value on a 7-segment display using a 4x4 keypad.

## Code Analysis
The code scans the 4x4 keypad connected to PORTF (Rows) and PORTK (Columns).
- When a key press is detected, it determines the column using `column()`.
- It maps the `(row, col)` pair to a digit using `keymap`.
- It displays the corresponding 7-segment code `seg[digit]` on PORTA.

## Simulation
[Wokwi Simulation Link](https://wokwi.com/projects/454360648269822977)

![Simulation Screenshot](simulation_screenshot.png)
