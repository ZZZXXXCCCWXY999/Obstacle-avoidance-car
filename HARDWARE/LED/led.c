#include "led.h" 
#include "delay.h"
void motor_Init(void){    	 
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	 //使能PB,PE端口时钟
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_14 | GPIO_Pin_6 |GPIO_Pin_7;//车轮电机端口端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}
void D_Init(void){
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);	 //使能PB端口时钟
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;//舵机端口端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOD, &GPIO_InitStructure);		
 //GPIO_ResetBits(GPIOB, GPIO_Pin_14 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_3 | GPIO_Pin_8 | GPIO_Pin_9);						 //PB.5 输出高
}
void motorRun(void){
	motor1=1;
	motor2=0;
	motor3=1;
	motor4=0;
	motor5=1;
	motor6=0;
	motor7=1;
	motor8=0;
}
void motorStop(void){
	motor1=0;
	motor2=0;
	motor3=0;
	motor4=0;
	motor5=0;
	motor6=0;
	motor7=0;
	motor8=0;
}void LeftRun(void){
	motor1=0;
	motor2=0;
	motor3=1;
	motor4=0;
	motor5=0;
	motor6=0;
	motor7=1;
	motor8=0;
}
void RightRun(void){
	motor1=1;
	motor2=0;
	motor3=0;
	motor4=0;
	motor5=1;
	motor6=0;
	motor7=0;
	motor8=0;
}

