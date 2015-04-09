#include "iodefine.h"

#define LED01_PIN   P6_bit.no2
#define LED01       PM6_bit.no2

void delay()
{
    unsigned long long uLcounter = 0;
    for(uLcounter=0;uLcounter<100000;uLcounter++)
    {
        asm("nop"); // do nothing
        asm("nop"); // do nothing
        asm("nop"); // do nothing
        asm("nop"); // do nothing
    }
}

int main(void)
{
    LED01_PIN = 0; // Make Pin as O/P
    LED01 = 0; // Turn LED ON
    while(1)
    {
        LED01 = ~LED01; // toggle LED
        delay();
    }
    return 0;
}
