//set 1 assignments from 1-10 all can be executed using this one single code 
//the main tasks of set 1 assignemnts are displaying different single digit number 0-9
#include <stdint.h>

#define DDRA  (*(volatile uint8_t*)0x21)
#define PORTA (*(volatile uint8_t*)0x22)

uint8_t seg[10] = {
    0x3F,
    0x06,
    0x5B,
    0x4F,
    0x66,
    0x6D,
    0x7D,
    0x07,
    0x7F,
    0x6F
};

void delay1sec(void){
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    while (TCNT1 < 15625);
    TCCR1B = 0x00;
}

int main(void){
    DDRA = 0x7F;

    while (1){
        PORTA = seg[0]; //put the number you want to print inside seg[] for common anode invert it 
        delay1sec();
        PORTA = 0x00;
        delay1sec();
    }
}
