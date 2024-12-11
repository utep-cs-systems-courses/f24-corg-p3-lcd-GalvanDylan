#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void buzzer_init()
{
  /*
     Direct timer A output "TA0.1" to P2.6.

      According to table 21 from data sheet:

        P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero

        P2SEL.6 must be 1

      Also: P2.6 direction must be output
  */
  timerAUpmode(); /* used to drive speaker */

  P2SEL2 &= ~(BIT6 | BIT7);

  P2SEL &= ~BIT7;

  P2SEL |= BIT6;

  P2DIR = BIT6; /* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> 1; /* one half cycle */
}

void musica()

{

  int notes[] = {C6, C6, D6, C6, D6, E6, C6, C6, D6, C6, G6, D6, C6, C6, C7, A6, D6, E6, D6};
  int durations[] = {500, 500, 1000, 1000, 1000, 2000, 500, 500, 1000, 1000, 1000, 2000, 500, 500, 1000, 1000, 1000, 1000, 2000}; 

  int total_notes = sizeof(notes) / sizeof(notes[0]);
  for (int i = 0; i < total_notes; i++)

    {

      buzzer_set_period(notes[i]);

      __delay_cycles(2500000);

      buzzer_set_period(0);

      __delay_cycles(250000);
    }
}

void musica_update()

{

  static int count = 0;

  count++;

  if (count == 5)
    {
      musica();

      count = 0;
    }
}
