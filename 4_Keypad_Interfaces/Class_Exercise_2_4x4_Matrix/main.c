#include <stdint.h>
#define DDRA (*(volatile uint8_t *)0x21)   // led
#define PORTA (*(volatile uint8_t *)0x22)  // output
#define DDRb (*(volatile uint8_t *)0x24)   // led
#define PORTb (*(volatile uint8_t *)0x25)  // output
#define DDRF (*(volatile uint8_t *)0x30)   // keypad
#define PORTF (*(volatile uint8_t *)0x31)  // output
#define DDRK (*(volatile uint8_t *)0x107)  // leypad
#define PORTK (*(volatile uint8_t *)0x106) // input
uint8_t i, j;

void setup() {
  DDRF = 0XFF;
  DDRK = 0X00;
  DDRA = 0XFF;
}

void loop() {
  for (i = 0; i < 4; i++) {
    PORTF = (1 << i); // Port f matrix row giving supplu port k is reading pin
    PORTA = PORTK;    // port a is led connected pin
    if (PORTK != 0) {
      PORTb = (1 << i); // for display ing row
      PORTb = 0;
    }
  }
}

int main(void) {
  setup();
  while (1) {
    loop();
  }
  return 0;
}
