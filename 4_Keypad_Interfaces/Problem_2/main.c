#include <stdint.h>
/* ---------- REGISTER DEFINITIONS ---------- */
#define DDRA (*(volatile uint8_t *)0x21)
#define PORTA (*(volatile uint8_t *)0x22)
#define DDRB (*(volatile uint8_t *)0x24)
#define PORTB (*(volatile uint8_t *)0x25)
#define DDRF (*(volatile uint8_t *)0x30)
#define PORTF (*(volatile uint8_t *)0x31)
#define DDRK (*(volatile uint8_t *)0x107)
#define PORTK (*(volatile uint8_t *)0x106)

/* ---------- GLOBALS ---------- */
uint8_t i;
uint8_t digits[4] = {0, 0, 0, 0};
uint8_t digit_index = 0;

/* ---------- FUNCTION PROTOTYPES ---------- */
void display_4digit(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4);
void delay_refresh(void);
void debounce_delay(void);
int get_column(uint8_t col_val);

/* ---------- DIGIT ENABLE (ACTIVE LOW) ---------- */
#define DIG1_ON() (PORTB = ~(1 << 0))
#define DIG2_ON() (PORTB = ~(1 << 1))
#define DIG3_ON() (PORTB = ~(1 << 2))
#define DIG4_ON() (PORTB = ~(1 << 3))
#define DIG_OFF() (PORTB = 0xFF)

/* ---------- SEGMENTS ---------- */
uint8_t seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int keymap[4][4] = {
    {1, 2, 3, -1}, {4, 5, 6, -1}, {7, 8, 9, -1}, {-1, 0, -1, -1}};

/* ---------- DISPLAY ---------- */
void display_4digit(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4) {
  PORTA = seg[d1];
  DIG1_ON();
  delay_refresh();
  DIG_OFF();
  PORTA = seg[d2];
  DIG2_ON();
  delay_refresh();
  DIG_OFF();
  PORTA = seg[d3];
  DIG3_ON();
  delay_refresh();
  DIG_OFF();
  PORTA = seg[d4];
  DIG4_ON();
  delay_refresh();
  DIG_OFF();
}

void delay_refresh(void) {
  for (volatile uint16_t i = 0; i < 800; i++)
    ;
}
void debounce_delay(void) {
  for (volatile uint16_t d = 0; d < 2000; d++)
    ;
}

int get_column(uint8_t col_val) {
  if (col_val & (1 << 0))
    return 0;
  if (col_val & (1 << 1))
    return 1;
  if (col_val & (1 << 2))
    return 2;
  if (col_val & (1 << 3))
    return 3;
  return -1;
}

void setup() {
  DDRF = 0x0F;
  DDRK = 0x00;
  DDRA = 0xFF;
  DDRB = 0x0F;
  PORTB = 0xFF;
}

void loop() {
  display_4digit(digits[0], digits[1], digits[2], digits[3]);
  for (i = 0; i < 4; i++) {
    PORTF = (1 << i);
    debounce_delay();
    uint8_t col_val = PORTK;
    if (col_val != 0) {
      debounce_delay();
      col_val = PORTK;
      if (col_val != 0) {
        int col = get_column(col_val);
        int digit = keymap[i][col];
        if (digit >= 0 && digit <= 9 && digit_index < 4) {
          digits[digit_index++] = digit;
        }
        while (PORTK != 0)
          ;
        debounce_delay();
      }
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
