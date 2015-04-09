/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  RL78G13_LED_SAMPLE                     */
/*      FILE         :  RL78G13_LED_SAMPLE.c                   */
/*      DESCRIPTION  :  Main Program                           */
/*      CPU SERIES   :  RL78 - G13                             */
/*      CPU TYPE     :  R5F100LE                               */
/*                                                             */
/***************************************************************/                                   

#include "iodefine.h"

#define LED01_PIN   P6_bit.no2
#define LED01       PM6_bit.no2

#ifdef CPPAPP
//Initialize global constructors
extern "C" void __main()
{
  static int initialized;
  if (! initialized)
    {
      typedef void (*pfunc) ();
      extern pfunc __ctors[];
      extern pfunc __ctors_end[];
      pfunc *p;

      initialized = 1;
      for (p = __ctors_end; p > __ctors; )
          (*--p) ();

    }
}
#endif 
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
void dummy(void) {
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
