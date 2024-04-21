#include "iic.h"
#include <intrins.h>


#define DELAY_TIME	5

sbit sda = P2^1;
sbit scl = P2^0;

//
static void I2C_Delay(unsigned char n)
{
    do
    {
        _nop_();		
    }
    while(n--);      	
}

//
void I2CStart(void)
{
    sda = 1;
    scl = 1;
	I2C_Delay(DELAY_TIME);
    sda = 0;
	I2C_Delay(DELAY_TIME);
    scl = 0;    
}

//
void I2CStop(void)
{
    sda = 0;
    scl = 1;
	I2C_Delay(DELAY_TIME);
    sda = 1;
	I2C_Delay(DELAY_TIME);
}

//
void I2CSendByte(unsigned char byt)
{
    unsigned char i;
	
    for(i=0; i<8; i++){
        scl = 0;
		I2C_Delay(DELAY_TIME);
        if(byt & 0x80){
            sda = 1;
        }
        else{
            sda = 0;
        }
		I2C_Delay(DELAY_TIME);
        scl = 1;
        byt <<= 1;
		I2C_Delay(DELAY_TIME);
    }
	
    scl = 0;  
}

//
unsigned char I2CReceiveByte(void)
{
	unsigned char da;
	unsigned char i;
	for(i=0;i<8;i++){   
		scl = 1;
		I2C_Delay(DELAY_TIME);
		da <<= 1;
		if(sda) 
			da |= 0x01;
		scl = 0;
		I2C_Delay(DELAY_TIME);
	}
	return da;    
}

//
unsigned char I2CWaitAck(void)
{
	unsigned char ackbit;
	
    scl = 1;
	I2C_Delay(DELAY_TIME);
    ackbit = sda; 
    scl = 0;
	I2C_Delay(DELAY_TIME);
	
	return ackbit;
}

//
void I2CSendAck(unsigned char ackbit)
{
    scl = 0;
    sda = ackbit; 
	I2C_Delay(DELAY_TIME);
    scl = 1;
	I2C_Delay(DELAY_TIME);
    scl = 0; 
	sda = 1;
	I2C_Delay(DELAY_TIME);
}

////////////////////////

void Write_EEPROM(unsigned char addr, unsigned char* EEPROM_str, unsigned char num)
{
	I2CStart();
	I2CSendByte(0xA0);
	I2CWaitAck();

	I2CSendByte(addr);
	I2CWaitAck();
	
	while(num --)
	{
		I2CSendByte(* EEPROM_str++);
		I2CWaitAck();
		I2C_Delay(200);
	}
	I2CStop();
}





void Write_DAC(unsigned char dat)
{
	I2CStart();
	
	I2CSendByte(0x90);
	I2CWaitAck();
	
	I2CSendByte(0x41);
	I2CWaitAck();
	
	
	I2CSendByte(dat);
	I2CWaitAck();
	I2CStop();
}



////////////


void Read_EEPROM(unsigned char addr, unsigned char* EEPROM_str, unsigned char num)
{
	I2CStart();
	I2CSendByte(0xA0);
	I2CWaitAck();
	
	I2CSendByte(addr);
	I2CWaitAck();
	
	I2CStart();
	I2CSendByte(0xA1);
	I2CWaitAck();
	
	while(num --)
	{
		*EEPROM_str++ = I2CReceiveByte();
		if(num) I2CSendAck(0);
		else I2CSendAck(1);
	}
	I2CStop();
	
}

unsigned char Read_ADC(unsigned char AD_Conl)
{
	unsigned char temp;
	
	I2CStart();
	I2CSendByte(0x90);
	I2CWaitAck();
	
	I2CSendByte(AD_Conl);
	I2CWaitAck();
	
	//����
	I2CStart();
	I2CSendByte(0x91);
	I2CWaitAck();
	
	temp = I2CReceiveByte();
	I2CSendAck(1);	
	I2CStop();
	
	return temp;
}

