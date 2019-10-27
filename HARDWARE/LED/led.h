#ifndef __LED_H
#define __LED_H
#include "sys.h"
#define D0 PDout(0)
#define D1 PDout(1)
#define D2 PDout(2)
#define D3 PDout(3)
#define D4 PDout(4)
#define D5 PDout(5)
#define motor1 PAout(0)
#define motor2 PAout(1)
#define motor3 PAout(2)
#define motor4 PAout(3)
#define motor5 PBout(0)
#define motor6 PAout(5)
#define motor7 PAout(6)
#define motor8 PAout(7)
void D_Init(void);
void motor_Init(void);
void motorRun(void);
void LeftRun(void);
void RightRun(void);
void motorStop(void);
#endif
