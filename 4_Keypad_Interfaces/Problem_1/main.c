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
uint8_t seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int keymap[4][4] = {
    {1, 2, 3, -1}, {4, 5, 6, -1}, {7, 8, 9, -1}, {-1, 0, -1, -1}};

int column(void) {
  if (PORTK & (1 << 0))
    return 0;
  if (PORTK & (1 << 1))
    return 1;
  if (PORTK & (1 << 2))
    return 2;
  if (PORTK & (1 << 3))
    return 3;
  return -1; // no column pressed
}

void setup() {
  DDRF = 0XFF;
  DDRK = 0X00;
  DDRA = 0XFF;
}

void loop() {
  for (i = 0; i < 4; i++) {
    PORTF = (1 << i); // Port f matrix row giving supply port k is reading pin
    int col = column();
    if (PORTK != 0) {
      PORTb = (1 << i); // for display ing row
      int digit = keymap[i][col];
      PORTA = seg[digit];
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
