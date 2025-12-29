# 🚀 Arduino MEGA (ATmega640/2560) Bare Metal Programming

Welcome to the **Bare Metal Programming** repository! This project focuses on direct register manipulation using the **ATmega640/2560** microcontroller, simulated via [Wokwi](https://wokwi.com).

The repository is organized by topic (LEDs, Seven Segment, etc.) and further divided into problem sets.

---

## 📌 Table of Contents

- [1. LED Assignments](#1-led-assignments)
  - [Set 1](#set-1)
  - [Set 2](#set-2)
  - [Set 3](#set-3)
  - [Set 4](#set-4)
- [2. Seven Segment Display](#2-seven-segment-display)
- [3. Dot Matrix Display](#3-dot-matrix-display)
- [4. Keypad Interfaces](#4-keypad-interfaces)
- [My Projects](#my-projects)

---

## 1. LED Assignments

### Set 1

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| 1 | [**Problem 1**](./1_LED_Assignments/Set_1/Problem_1/) | Connect LED to **Port J bit 0** | `DDRJ`, `PORTJ` | [**View**](https://wokwi.com/projects/450218684197143553) |
| 2 | [**Problem 2**](./1_LED_Assignments/Set_1/Problem_2/) | Connect LED to **Port D bit 7** | `DDRD`, `PORTD` | [**View**](https://wokwi.com/projects/450221318023254017) |
| 3 | [**Problem 3**](./1_LED_Assignments/Set_1/Problem_3/) | Connect LEDs to **Port H bit 6 & 0** | `DDRH`, `PORTH` | [**View**](https://wokwi.com/projects/450284628790415361) |
| 4 | [**Problem 4**](./1_LED_Assignments/Set_1/Problem_4/) | Connect LEDs to **Port C bit 6 & 7** | `DDRC`, `PORTC` | [**View**](https://wokwi.com/projects/450287676924481537) |
| 5 | [**Problem 5**](./1_LED_Assignments/Set_1/Problem_5/) | Connect LEDs to **Port A bit 0-3** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/450287693884152833) |
| 6 | [**Problem 6**](./1_LED_Assignments/Set_1/Problem_6/) | Connect LEDs to **Port B bit 4-7** | `DDRB`, `PORTB` | [**View**](https://wokwi.com/projects/450287714714116097) |
| 7 | [**Problem 7**](./1_LED_Assignments/Set_1/Problem_7/) | Connect 8 LEDs to **Port F** | `DDRF`, `PORTF` | [**View**](https://wokwi.com/projects/450287734852019201) |
| 8 | [**Problem 8**](./1_LED_Assignments/Set_1/Problem_8/) | Connect 8 LEDs to **Port K (Odd/Even)** | `DDRK`, `PORTK` | [**View**](https://wokwi.com/projects/450288060923527169) |
| 9 | [**Problem 9**](./1_LED_Assignments/Set_1/Problem_9/) | Connect 8 LEDs to **Port L (Even)** | `DDRL`, `PORTL` | [**View**](https://wokwi.com/projects/450288081398026241) |
| 10 | [**Problem 10**](./1_LED_Assignments/Set_1/Problem_10/) | Connect 8 LEDs to **Port E (Specific)** | `DDRE`, `PORTE` | [**View**](https://wokwi.com/projects/450288106353088513) |

### Set 2

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| 1 | [**Problem 1**](./1_LED_Assignments/Set_2/Problem_1/) | Connect 8 LEDs to **Port A (Blink All)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/450837212305922049) |
| 2 | [**Problem 2**](./1_LED_Assignments/Set_2/Problem_2/) | Connect 8 LEDs to **Port B (Seq Accumulate)** | `DDRB`, `PORTB` | [**View**](https://wokwi.com/projects/450839093411595265) |
| 3 | [**Problem 3**](./1_LED_Assignments/Set_2/Problem_3/) | Connect 8 LEDs to **Port C (Seq Blink)** | `DDRC`, `PORTC` | [**View**](https://wokwi.com/projects/450840620058693633) |
| 4 | [**Problem 4**](./1_LED_Assignments/Set_2/Problem_4/) | Connect 8 LEDs to **Port C (Seq Blink Single)** | `DDRC`, `PORTC` | [**View**](https://wokwi.com/projects/451214774943659009) |
| 5 | [**Problem 5**](./1_LED_Assignments/Set_2/Problem_5/) | Connect LED to **Port J Bit 0 (Blink)** | `DDRJ`, `PORTJ` | [**View**](https://wokwi.com/projects/451214789547181057) |
| 6 | [**Problem 6**](./1_LED_Assignments/Set_2/Problem_6/) | Connect 8 LEDs to **Port K (Even Blink)** | `DDRK`, `PORTK` | [**View**](https://wokwi.com/projects/450851741143461889) |
| 7 | [**Problem 7**](./1_LED_Assignments/Set_2/Problem_7/) | Connect 8 LEDs to **Port L (0-3 Seq)** | `DDRL`, `PORTL` | [**View**](https://wokwi.com/projects/450854181787164673) |
| 8 | [**Problem 8**](./1_LED_Assignments/Set_2/Problem_8/) | Connect 8 LEDs to **Port F (4-7 Seq)** | `DDRF`, `PORTF` | [**View**](https://wokwi.com/projects/451214702764919809) |
| 9 | [**Problem 9**](./1_LED_Assignments/Set_2/Problem_9/) | Connect 8 LEDs to **Port F (7-4 Reverse)** | `DDRF`, `PORTF` | [**View**](https://wokwi.com/projects/451214725256879105) |
| 10 | [**Problem 10**](./1_LED_Assignments/Set_2/Problem_10/) | Connect 8 LEDs to **Port F (Code 7-4 / Obj 3-0)** | `DDRF`, `PORTF` | [**View**](https://wokwi.com/projects/451214741914558465) |

### Set 3

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| 1 | [**Problem 1**](./1_LED_Assignments/Set_3/Problem_1/) | Connect 8 LEDs to **Port A (Pairs 0,4...3,7)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451229712541347841) |
| 2 | [**Problem 2**](./1_LED_Assignments/Set_3/Problem_2/) | Connect 8 LEDs to **Port A (Seq Pairs 0-4 w/ Clear)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451230358004944897) |
| 3 | [**Problem 3**](./1_LED_Assignments/Set_3/Problem_3/) | Connect 8 LEDs to **Port A (Seq 0-7, 7-0)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451230371206518785) |
| 4 | [**Problem 4**](./1_LED_Assignments/Set_3/Problem_4/) | Connect 8 LEDs to **Port A (Pattern 0,2,1,3...)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451230395192699905) |
| 5 | [**Problem 5**](./1_LED_Assignments/Set_3/Problem_5/) | Connect 8 LEDs to **Port A (Pairs 01, 67, 23, 45)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451230414750740481) |
| 6 | [**Problem 6**](./1_LED_Assignments/Set_3/Problem_6/) | Connect 8 LEDs to **Port A (Pairs 45, 23, 67, 01)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451230437858215937) |
| 7 | [**Problem 7**](./1_LED_Assignments/Set_3/Problem_7/) | Connect 8 LEDs to **Port A (Groups 012, 567, 34)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451233275591356417) |
| 8 | [**Problem 8**](./1_LED_Assignments/Set_3/Problem_8/) | Connect 8 LEDs to **Port A (Groups 34, 567, 012)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451233349303119873) |
| 9 | [**Problem 9**](./1_LED_Assignments/Set_3/Problem_9/) | Connect 8 LEDs to **Port A (Accumulate 0-7)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451233426803376129) |
| 10 | [**Problem 10**](./1_LED_Assignments/Set_3/Problem_10/) | Connect 8 LEDs to **Port A (Accumulate 7-0)** | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/451233531907399681) |

### Set 4

_(Coming Soon)_

---

## 2. Seven Segment Display

_(Assignments coming soon)_

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| - | - | - | - | - |

---

## 3. Dot Matrix Display

_(Assignments coming soon)_

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| - | - | - | - | - |

---

## 4. Keypad Interfaces

_(Assignments coming soon)_

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| - | - | - | - | - |

---

## My Projects

| Project Name | Description | Link |
| :--- | :--- | :---: |
| - | - | - |

---

