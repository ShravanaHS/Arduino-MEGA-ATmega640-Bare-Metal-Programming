# Class Exercise 2: 4x4 Switch Matrix Implementation

## Problem Statement
Implement a 4x4 switch matrix with keypad and LED.

## Code Analysis
The code scans a 4x4 matrix using PORTF (Rows) and PORTK (Columns).
- `PORTF` outputs the row scan signals.
- `PORTK` reads the column inputs.
- `PORTA` displays the column value (key press) on LEDs.
- `PORTb` (sic) is used to display the active row momentarily.

The `loop` function iterates through 4 rows, sets the row bit in `PORTF`, and reads `PORTK`.

## Simulation
[Wokwi Simulation Link](https://wokwi.com/projects/454720769713231873)

![Simulation Screenshot](simulation_screenshot.png)
