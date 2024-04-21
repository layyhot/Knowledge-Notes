#ifndef __ENCODER_H
#define __ENCODER_H

void Encoder_Init(void);

int16_t Encoder_Get(void);
int16_t Encoder_Get_Div4(void);
void Encoder_Reset(void);

#endif
