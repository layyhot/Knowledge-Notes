#include "key.h"

unsigned char Scan_Key_BTN(void)
{
	if(P30 == 0)	return 7;
	else if(P31 == 0)	return 6;
	else if(P32 == 0)	return 5;
	else if(P33 == 0)	return 4;
	else return 0;
}



//unsigned char Scan_Key(void)
//{
//	unsigned int key_new;
//	unsigned char key_value;
//	
//	P42 = P35 = P34 = 1;
//	P44 =0;
//	key_new = P3 & 0x0f;
//	
//	P44 = P35 = P34 = 1;
//	P42 =0;
//	key_new = (key_new << 4 ) | (P3 & 0x0f);
//	
//	P42 = P44 = P34 = 1;
//	P35 =0;
//	key_new = (key_new << 4 ) | (P3 & 0x0f);
//	
//	P42 = P35 = P44 = 1;
//	P34 =0;
//	key_new = (key_new << 4 ) | (P3 & 0x0f);
//	
//	switch(~key_new)
//	{
//		case 0x8000 : key_value = 7; break;
//		case 0x4000 : key_value = 6; break;
//		case 0x2000 : key_value = 5; break;
//		case 0x1000 : key_value = 4; break;
//		
//		case 0x0800 : key_value = 11; break;
//		case 0x0400 : key_value = 10; break;
//		case 0x0200 : key_value = 9; break;
//		case 0x0100 : key_value = 8; break;
//		
//		case 0x0080 : key_value = 15; break;
//		case 0x0040 : key_value = 14; break;
//		case 0x0020 : key_value = 13; break;
//		case 0x0010 : key_value = 12; break;
//		
//		case 0x0008 : key_value = 19; break;
//		case 0x0004 : key_value = 18; break;
//		case 0x0002 : key_value = 17; break;
//		case 0x0001 : key_value = 16; break;
//		default : key_value = 0; break;
//	}
//	
//	return key_value;	
//}

////--¾ØÕó¼üÅÌ
//unsigned char Scan_Key(void)
//{
//	unsigned int Key_New;
//	unsigned char Key_Value;
//	
//	P44 = 0;P42 = 1;P35 = 1;P34 = 1;
//	Key_New = P3 & 0X0F;
//	
//	P44 = 1;P42 = 0;P35 = 1;P34 = 1;
//	Key_New = (Key_New<<4)|(P3 & 0X0F);
//	
//	P44 = 1;P42 = 1;P35 = 0;P34 = 1;
//	Key_New = (Key_New<<4)|(P3 & 0X0F);
//	
//	P44 = 1;P42 = 1;P35 = 1;P34 = 0;
//	Key_New = (Key_New<<4)|(P3 & 0X0F);
//	
//	switch(~Key_New)
//	{
//		case 0x8000: Key_Value = 4; break;
//		case 0x4000: Key_Value = 5; break;	
//		case 0x2000: Key_Value = 6; break;	
//		case 0x1000: Key_Value = 7; break;	
//	
//		case 0x0800: Key_Value = 8; break;
//		case 0x0400: Key_Value = 9; break;	
//		case 0x0200: Key_Value = 10; break;	
//		case 0x0100: Key_Value = 11; break;	

//		case 0x0080: Key_Value = 12; break;
//		case 0x0040: Key_Value = 13; break;	
//		case 0x0020: Key_Value = 14; break;	
//		case 0x0010: Key_Value = 15; break;			
//	
//		case 0x0008: Key_Value = 16; break;
//		case 0x0004: Key_Value = 17; break;	
//		case 0x0002: Key_Value = 18; break;	
//		case 0x0001: Key_Value = 19; break;			
//		default :  Key_Value = 0;
//	}
//	
//	return Key_Value;
//	
//}



unsigned char Scan_Key(void)
{
	unsigned char key_value;
	unsigned int key_now;
	
	P42 = P35 = P34 = 1;
	P44 = 0;
	key_now = (P3 & 0x0f);
	
	P44 = P35 = P34 = 1;
	P42 = 0;
	key_now = (P3 & 0x0f) | (key_now << 4);
	
	P44 = P42 = P34 = 1;
	P35 = 0;
	key_now = (P3 & 0x0f) | (key_now << 4);
	
	P44 = P42 = P35 = 1;
	P34 = 0;
	key_now = (P3 & 0x0f) | (key_now << 4);
	
	switch(~key_now)
	{
		case 0x8000: key_value = 4; break;
		case 0x4000: key_value = 5; break;	
		case 0x2000: key_value = 6; break;	
		case 0x1000: key_value = 7; break;	
	
		case 0x0800: key_value = 8; break;
		case 0x0400: key_value = 9; break;	
		case 0x0200: key_value = 10; break;	
		case 0x0100: key_value = 11; break;	

		case 0x0080: key_value = 12; break;
		case 0x0040: key_value = 13; break;	
		case 0x0020: key_value = 14; break;	
		case 0x0010: key_value = 15; break;			
	
		case 0x0008: key_value = 16; break;
		case 0x0004: key_value = 17; break;	
		case 0x0002: key_value = 18; break;	
		case 0x0001: key_value = 19; break;			
		default :  key_value = 0;
	}
	
	return key_value;
		
	
}