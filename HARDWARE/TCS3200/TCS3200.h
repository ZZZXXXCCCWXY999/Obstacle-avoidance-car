#ifndef __TCS3200_H
#define __TCS3200_H	 
#include "sys.h"

//extern u16 Rgena,Ggena,Bgena;//用于调节白平衡
extern u16 Ramount,Gamount,Bamount;//用于存放读取的RGB值
extern u16 amount;//中断计数

typedef struct   
{
	u16 Rgena;
	u16 Ggena;
	u16 Bgena;
}_RGB;

extern _RGB RGB;

#define S2 PAout(1)
#define S3 PAout(2)
#define OUT PEin(0)

void TCS3200_Init(void);
void WhiteBalance(void);
u16 tcs3200_GREEN(void);
u16 tcs3200_BLUE(void);

#endif
