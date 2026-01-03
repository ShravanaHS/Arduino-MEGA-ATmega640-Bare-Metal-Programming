// to display even numbers from 0-9

#include <stdint.h>

#define DDRA (*(volatile uint8_t *)0x21)
#define PORTA (*(volatile uint8_t *)0x22)

uint8_t seg[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

void delay1sec(void) {
  TCNT1 = 0;
  TCCR1A = 0x00;
  TCCR1B = 0x05;
  while (TCNT1 < 15625)
    ;
  TCCR1B = 0x00;
}

int main(void) {
  DDRA = 0x7F;

  while (1) {
    for (uint8_t i = 0; i <= 8; i += 2) {
      PORTA = seg[i];
      delay1sec();
    }
  }
}
