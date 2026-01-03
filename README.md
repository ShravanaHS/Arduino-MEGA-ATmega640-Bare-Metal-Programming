# 🚀 Arduino MEGA (ATmega640/2560) Bare Metal Programming

Welcome to the **Bare Metal Programming** repository! This project serves as a comprehensive guide to direct register manipulation using the **ATmega640/2560** microcontroller. All simulations are designed to run on [Wokwi](https://wokwi.com).

## 📂 Repository Structure

The assignments and projects are categorized by interface type:

- **1. LED Assignments**: Fundamental GPIO operations using LEDs.
- **2. Seven Segment Display**: Interfacing with 7-segment displays.
- **3. Dot Matrix Display**: Controlling LED matrices.
- **4. Keypad Interfaces**: Reading input from keypads.
- **My Projects**: Custom personal projects.

---

## 1. 💡 LED Assignments

<details>
<summary><strong>Set 1: Basic LED Control</strong></summary>

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

</details>

<details>
<summary><strong>Set 2: Sequence & Control</strong></summary>

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

</details>

<details>
<summary><strong>Set 3: Pattern Logic</strong></summary>

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

</details>

<details>
<summary><strong>Set 4: Advanced LED Operations</strong></summary>

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| 1 | [**Problem 1**](./1_LED_Assignments/Set_4/Problem_1/) | Dual Port ON | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451305981969614849) |
| 2 | [**Problem 2**](./1_LED_Assignments/Set_4/Problem_2/) | Alternating Rows | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451306004842207233) |
| 3 | [**Problem 3**](./1_LED_Assignments/Set_4/Problem_3/) | Sequential Row Blink | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451306020763787265) |
| 4 | [**Problem 4**](./1_LED_Assignments/Set_4/Problem_4/) | Parallel Sequential Mirror | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451306062951152641) |
| 5 | [**Problem 5**](./1_LED_Assignments/Set_4/Problem_5/) | Row-by-Row Sequence | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451306040146719745) |
| 6 | [**Problem 6**](./1_LED_Assignments/Set_4/Problem_6/) | Parallel Sequential Mirror | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451306091675844609) |
| 7 | [**Problem 7**](./1_LED_Assignments/Set_4/Problem_7/) | 4 by 4 Blink (See README) | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451306146569847809) |
| 8 | [**Problem 8**](./1_LED_Assignments/Set_4/Problem_8/) | Alternate Pattern Blink | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451306164679805953) |
| 9 | [**Problem 9**](./1_LED_Assignments/Set_4/Problem_9/) | Pair Blink | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451306186028815361) |
| 10 | [**Problem 10**](./1_LED_Assignments/Set_4/Problem_10/) | Reverse Pair Blink | `DDRA`, `DDRB` | [**View**](https://wokwi.com/projects/451306204462786561) |

</details>

---

## 2. 🔢 Seven Segment Display

<details>

<details>
<summary><strong>Set 1: Basic Display</strong></summary>

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| 1 | [**Problem 1**](./2_Seven_Segment_Assignments/Set_1/Problem_1/) | Interface 7-Segment (Display 0-9) | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/452036987984757761) |
| 2 | [**Problem 2**](./2_Seven_Segment_Assignments/Set_1/Problem_2/) | Display '1' (Single Digit) | `DDRA`, `PORTA` | [**View**](https://wokwi.com/projects/452037010100276225) |

</details>

<details>
<summary><strong>Set 2: Sequence & Patterns</strong></summary>

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| 1 | [**Problem 1**](./2_Seven_Segment_Assignments/Set_2/Problem_1/) | Sequence 0-9 (Common Cathode) | `DDRA`, `PORTA`, `TCNT1` | [**View**](https://wokwi.com/projects/452037027766689793) |
| 2 | [**Problem 2**](./2_Seven_Segment_Assignments/Set_2/Problem_2/) | Sequence 0-9 (Common Anode) | `DDRA`, `PORTA`, `TCNT1` | [**View**](https://wokwi.com/projects/452037095608515585) |
| 3 | [**Problem 3**](./2_Seven_Segment_Assignments/Set_2/Problem_3/) | (Duplicate of Problem 1) | `DDRA`, `PORTA`, `TCNT1` | [**View**](https://wokwi.com/projects/452037027766689793) |
| 6 | [**Problem 6**](./2_Seven_Segment_Assignments/Set_2/Problem_6/) | Countdown 9-0 | `DDRA`, `PORTA`, `TCNT1` | [**View**](https://wokwi.com/projects/452037077877093377) |
| 7 | [**Problem 7**](./2_Seven_Segment_Assignments/Set_2/Problem_7/) | Even Numbers (0-8) | `DDRA`, `PORTA`, `TCNT1` | [**View**](https://wokwi.com/projects/452037062276377601) |
| 8 | [**Problem 8**](./2_Seven_Segment_Assignments/Set_2/Problem_8/) | Even then Odd Sequence | `DDRA`, `PORTA`, `TCNT1` | [**View**](https://wokwi.com/projects/452037043151397889) |
| 9 | [**Problem 9**](./2_Seven_Segment_Assignments/Set_2/Problem_9/) | Alphanumeric Sequence | `DDRA`, `PORTA`, `TCNT1` | [**View**](https://wokwi.com/projects/452098175729115137) |
| 10 | [**Problem 10**](./2_Seven_Segment_Assignments/Set_2/Problem_10/) | Prime Numbers (2,3,5,7) | `DDRA`, `PORTA`, `TCNT1` | [**View**](https://wokwi.com/projects/452098264037041153) |

</details>

</details>

---

## 3. 📉 Dot Matrix Display

<details>
<summary><strong>Assignments</strong></summary>

_(Coming Soon)_

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| - | - | - | - | - |

</details>

---

## 4. 🎹 Keypad Interfaces

<details>
<summary><strong>Assignments</strong></summary>

_(Coming Soon)_

| # | Problem | Objective | Registers Used | Simulation |
|:-:| :--- | :--- | :--- | :---: |
| - | - | - | - | - |

</details>

---

## 🛠️ My Projects

| Project Name | Description | Link |
| :--- | :--- | :---: |
| - | - | - |

---
