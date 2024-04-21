#include "dsp_seg.h"


//void Seg_Str_To_Buf(unsigned char* seg_str, unsigned char* seg_buf)
//{
//	unsigned char temp;
//	unsigned char i, j;
//	for(i = 0, j = 0; i < 10;i ++, j ++)
//	{
//		switch(seg_str[i])
//		{
//			case '0': temp = 0xc0; break;
//			case '1': temp = 0xf9; break;			
//			case '2': temp = 0xa4; break;
//			case '3': temp = 0xb0; break;			
//			case '4': temp = 0x99; break;
//			case '5': temp = 0x92; break;			
//			case '6': temp = 0x82; break;
//			case '7': temp = 0xf8; break;	
//			case '8': temp = 0x80; break;
//			case '9': temp = 0x90; break;			
//			case 'A': temp = 0x88; break;
//			case 'B': temp = 0x83; break;			
//			case 'C': temp = 0xc6; break;
//			case 'D': temp = 0xa1; break;			
//			case 'E': temp = 0x86; break;
//			case 'F': temp = 0x8e; break;	//所有十六进制数据
//			
//			case 'H': temp = 0x89; break;			
//			case 'L': temp = 0xc7; break;
//			case 'N': temp = 0xc8; break;			
//			case 'P': temp = 0x8c; break;
//			case 'U': temp = 0xc1; break;	//回来女仆呦	

//			case '-': temp = 0xbf; break;			
//			case ' ': temp = 0xff; break;	//两种特殊情况
//			
//			default: temp = 0xff; break;		//默认
//		}
//		
//		if(seg_str[i + 1] == '.')  {temp &= 0x7f; i++;}
//		seg_buf[j] = temp;
//	}
//}

void Dsp_Seg(unsigned char* seg_buf, unsigned char pos)
{
	P0 = (0x01 << pos);
	P2 = P2 & 0x1f | 0xc0;
	P2 &= 0x1f;
	
	P0 = 0;
	P2 = P2 & 0x1f | 0xe0;
	P2 &= 0x1f;
	
	P0 = seg_buf[pos];
	P2 = P2 & 0x1f | 0xe0;
	P2 &= 0x1f;
}

void Seg_Str_To_Buf(unsigned char* seg_str, unsigned char* seg_buf)
{
	unsigned char temp;
	unsigned char i, j;
	
	for(i = 0, j = 0; i <= 7; i ++, j ++)
	{
		switch(seg_str[j])
		{
			case '0': temp = 0xc0; break;
			case '1': temp = 0xf9; break;			
			case '2': temp = 0xa4; break;
			case '3': temp = 0xb0; break;			
			case '4': temp = 0x99; break;
			case '5': temp = 0x92; break;			
			case '6': temp = 0x82; break;
			case '7': temp = 0xf8; break;	
			case '8': temp = 0x80; break;
			case '9': temp = 0x90; break;			
			case 'A': temp = 0x88; break;
			case 'B': temp = 0x83; break;			
			case 'C': temp = 0xc6; break;
			case 'D': temp = 0xa1; break;			
			case 'E': temp = 0x86; break;
			case 'F': temp = 0x8e; break;	//所有十六进制数据
			
			case 'H': temp = 0x89; break;			
			case 'L': temp = 0xc7; break;
			case 'N': temp = 0xc8; break;			
			case 'P': temp = 0x8c; break;
			case 'U': temp = 0xc1; break;	//回来女仆呦	

			case '-': temp = 0xbf; break;			
			case ' ': temp = 0xff; break;	//两种特殊情况
			
			default: temp = 0xff; break;		//默认
		}
		
		if(seg_str[j + 1] == '.')	{temp &= 0x7f; j ++;}
		
		seg_buf[i] = temp;
	}
	
}
	
