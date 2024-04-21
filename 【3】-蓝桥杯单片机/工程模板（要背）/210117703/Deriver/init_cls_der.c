#include "init_cls_der.h"

void Cls_Der(void)
{	
	P0 = 0;
	P2 = P2 & 0x1f | 0xA0;
	P2 &= 0x1f;
	
	P0 = 0xff;
	P2 = P2 & 0x1f | 0x80;
	P2 &= 0x1f;
}


