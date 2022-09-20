#include <msp430.h>				


/**
 * main.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= BIT0;					// configure P1.0 as output

	UCSCTL3 &= ~(BIT4+BIT5+BIT6);
	UCSCTL3 |= BIT5;

	UCSCTL4 &= ~(BIT10+BIT9+BIT8);
	UCSCTL4 |= BIT9;

	UCSCTL0 = 0;



	/*do
	{
	    UCSCTL7 &= ~0b0000000000001011;
        SFRIFG1 &= ~BIT1;
	}while(SFRIFG1&OFIFG);*/


	while(1)
	{
	    P1OUT ^= 0x01;
	}
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
    P1OUT ^= 0x01;              // toggle P1.0
}
