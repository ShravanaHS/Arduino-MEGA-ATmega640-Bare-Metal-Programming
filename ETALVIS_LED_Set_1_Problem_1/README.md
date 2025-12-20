# ETALVIS_LED_Set_1_Problem_1

## Objective
Connect a LED to port J bit 0. Glow LSB LED only (bit 0)

## Bare Metal Logic
- **Register Addresses**:
  - `DDRJ` (Data Direction Register for Port J) is accessed at address `0x104`.
  - `PORTJ` (Data Register for Port J) is accessed at address `0x105`.
- **Volatile Pointers**:
  - `volatile char *dirj` and `volatile char *portj` are used to create pointers to these specific hardware addresses.
  - The `volatile` keyword tells the compiler not to optimize access to these variables, ensuring every read/write goes directly to the memory-mapped IO register.

## Circuit Simulation
[Link to Wokwi Simulation](https://wokwi.com/projects/450218684197143553)

## Code
```c
//Problem: Connect a LED to port J bit 0. Glow LSB LED only (bit 0)


/* here port j is pin 14 -- pin 21 
so port j bit 0 is pin 14 in hardware
in order to access those here direction register address is 104
port address is 105*/

void setup() {
  // put your setup code here, to run once:
  volatile char *dirj;
  dirj = 0X104;  //accessing DDR of J port
  *dirj = 0XFF;   // setting it as output
}

void loop() {
  // put your main code here, to run repeatedly:
volatile char *portj;
portj = 0X105;
*portj = 0x01;

}
```

## Visual
![Simulation Output](./output.png)
