#include <stdint.h>

#define DDRA (*(volatile uint8_t *)0x21)
#define PORTA (*(volatile uint8_t *)0x22)

uint8_t alpha[] = {0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x3D, 0x76, 0x30, 0x1E,
                   0x38, 0x54, 0x5C, 0x73, 0x50, 0x6D, 0x78, 0x3E, 0x6E};

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
    for (uint8_t i = 0; i < sizeof(alpha); i++) {
      PORTA = alpha[i];
      delay1sec();
    }
  }
}
