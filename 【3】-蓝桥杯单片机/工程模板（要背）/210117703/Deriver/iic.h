#include <STC15F2K60S2.H>

static void I2C_Delay(unsigned char n);

void I2CStart(void);

void I2CStop(void);


//
void I2CSendByte(unsigned char byt);


//
unsigned char I2CReceiveByte(void);


//
unsigned char I2CWaitAck(void);


//
void I2CSendAck(unsigned char ackbit);


////////////////////////
void Write_EEPROM(unsigned char addr, unsigned char* EEPROM_str, unsigned char num);


void Write_DAC(unsigned char dat);



////////////

void Read_EEPROM(unsigned char addr, unsigned char* EEPROM_str_buf, unsigned char num);


unsigned char Read_ADC(unsigned char AD_Conl);