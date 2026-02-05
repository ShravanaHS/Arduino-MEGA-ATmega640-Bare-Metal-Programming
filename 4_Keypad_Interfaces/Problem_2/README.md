# Problem 2: 4-Digit Display Keypad

## Problem Statement
Use a 4-digit 7-segment display to show 4 button presses from the keypad.

## Code Analysis
The code captures up to 4 key presses and stores them in the `digits` array.
- It multiplexes the 4-digit display using `display_4digit`, activating one digit at a time via PORTB.
- The keypad scanning loop detects presses, debounces them, and maps them to digits.
- The `digits` array acts as a buffer for the display.

## Simulation
[Wokwi Simulation Link](https://wokwi.com/projects/454754911592402945)

![Simulation Screenshot](simulation_screenshot.png)
