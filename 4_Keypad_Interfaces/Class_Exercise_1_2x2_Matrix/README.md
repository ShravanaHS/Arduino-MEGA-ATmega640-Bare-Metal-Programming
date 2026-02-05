# Class Exercise 1: 2x2 Switch Matrix Implementation

## Problem Statement
Implement a 2x2 switch matrix using the Keypad interface.

## Code Analysis
The code configures PORTA and PORTB for scanning the matrix rows and columns.
- `PORTA` is used for Keypad rows (Output).
- `PINB` is used for Keypad columns (Input).
- `PORTF` drives the LEDs to indicate key presses.

The `main` function continuously scans the 2 rows (`i=0` to `1`).
For each row, it activates the corresponding bit in `PORTA` and reads the input from `PINB` onto `PORTF`.

## Simulation
[Wokwi Simulation Link](https://wokwi.com/projects/454448194463354881)

![Simulation Screenshot](simulation_screenshot.png)
