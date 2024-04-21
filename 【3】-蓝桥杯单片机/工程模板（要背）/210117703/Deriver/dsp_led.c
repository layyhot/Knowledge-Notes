#include "dsp_led.h"

void Dsp_Led(unsigned char ucled)
{
	P0 = ~ucled;
	P2 = P2 & 0x1f | 0x80;
	P2 &= 0x1f;
}