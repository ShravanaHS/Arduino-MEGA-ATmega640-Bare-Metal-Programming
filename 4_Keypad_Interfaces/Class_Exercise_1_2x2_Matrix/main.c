#include <stdint.h>
/* ---------------- PORTA (Keypad) ---------------- */
#define PINA (*(volatile uint8_t *)0x23)
#define DDRA (*(volatile uint8_t *)0x24)
#define PORTA (*(volatile uint8_t *)0x25)
#define PINB (*(volatile uint8_t *)0x20)
#define DDRB (*(volatile uint8_t *)0x21)
#define PORTB (*(volatile uint8_t *)0x22)
/* ---------------- PORTH (LED) ---------------- */
#define DDRH (*(volatile uint8_t *)0x101)
#define PORTH (*(volatile uint8_t *)0x102)
#define DDRF (*(volatile uint8_t *)0x30)
#define PORTF (*(volatile uint8_t *)0x31)
volatile long i, j;
int main() {
  DDRF |= 0X0F;
  DDRB = 0X00;
  DDRA |= 0X02;
  while (1) {
    PORTF = 0x00;
    for (i = 0; i < 2; i++) {
      PORTA |= (1 << i);
      PORTF = PINB;
    }
  }
}
