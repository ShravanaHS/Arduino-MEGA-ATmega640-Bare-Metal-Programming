// print 0-9 on 7 segment display with the 1sec delay hardware same as
// assignment 1 set 1 problem 2

#include <stdint.h>

#define DDRA (*(volatile uint8_t *)0x21)
#define PORTA (*(volatile uint8_t *)0x22)

uint8_t seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

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
    volatile uint8_t i = 0;
    for (i = 0; i < 10; i++) {
      PORTA = seg[i];
    }
  }
}
