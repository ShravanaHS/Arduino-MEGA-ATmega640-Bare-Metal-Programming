// connect port A to 7 segment display and print 1
#include <stdint.h>

#define DDRA (*(volatile uint8_t *)0x21)
#define PORTA (*(volatile uint8_t *)0x22)

void setup() {
  DDRA = 0x7F;
  PORTA = 0x06;
}

void loop() {}
