#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "key.h"
#include "exti.h"
#include "TCS3200.h"
#define D4ON D4adjust(99)
#define D4OFF D4adjust(144)
#define LeftTurn cnt0User=12
#define RightTurn cnt0User=18
#define StrightRun cnt0User=15
u8 flag=0;
u8 G=0x00,B=0x00;
void TIM3_IRQHandler(void);
void takeTree(void);
void putTree(u8 mod);
void D1adjust(u8 degress);
void D2adjust(u8 degress);
void D3adjust(u8 degress);
void D4adjust(u8 degress);
void D5adjust(u8 degress);
void SetGreen(void);
void SetBlue(void);
void motorRun(void);
void motorStop(void);
void rest(void);
u8 cnt0User=15,cnt0=1,cnt1User=15,cnt1=1,cnt2User=12,cnt2=1,cnt3User=25,cnt3=1,cnt4User=20,cnt4=1,cnt5=1,cnt5User=5;//舵机PWM波参数
u8 process=1;
int main(void){ 

	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
	key_Init();
	//D_Init();
	//EXTIX_Init();
	delay_init();  //初始化延时函数
	//TIM3_Int_Init(100-1,72-1);//10Khz的计数频率，计数到5000为500ms  	
	motor_Init();	
	//TCS3200_Init();
	//rest();
	//WhiteBalance();
	//delay_ms(500);
	LeftRun();
	while(1);
	while(1){
		if(key1==0&&key2==1) StrightRun;
		else if(key1==1&&key2==1) RightTurn;
		else LeftTurn;
		switch (process){
			case 1:
				if(tcs3200_GREEN()>=200){					
					motorStop();
					takeTree();
					delay_ms(600);
					putTree(1);
					motorRun();
					delay_ms(1000);
					motorStop();
					rest();
					SetBlue();
					process++;
					motorRun();
				}
				break;
			case 2:
				if(tcs3200_BLUE()>=200){
					takeTree();
					D5adjust(180);
					takeTree();
					rest();
					SetGreen();
					process++;
				}
				break;
				
		}
	}
	return 0;
}
/*void TIM3_IRQHandler(void){
		if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
		{
			if(cnt0>=cnt0User){
				D0=!D0;
				cnt0=1;
			}
			else{
			cnt0++;
			}
			if(cnt2>=cnt2User){
				D2=!D2;
				cnt2=1;
			}
			else{
			cnt2++;
			}
			if(cnt3>=cnt3User){
				D3=!D3;
				cnt3=1;
			}
			else{
			cnt3++;
			}
			if(cnt4>=cnt4User){
				D4=!D4;
				cnt4=1;
			}
			else{
			cnt4++;
			}
			if(cnt1>=cnt1User){
				D1=!D1;
				cnt1=1;
			}
			else{
			cnt1++;
			}
			if(cnt5>=cnt5User){
				D5=!D5;
				cnt5=1;
			}
			else{
			cnt5++;
			}
			TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
		}
}
void rest (void){
	D4ON;
	cnt2User=12;
	cnt3User=25;
}
void D1adjust(u8 degress){
	cnt1User=degress/9+5;
}
void D2adjust(u8 degress){
	cnt2User=degress/9+5;
}
void D3adjust(u8 degress){
	cnt3User=degress/9+5;
}
void D4adjust(u8 degress){
	cnt4User=degress/9+5;
}
void D5adjust (u8 degress){
	cnt5User=degress/9+5;
}
void SetGreen(void){
	S2=1;
	S3=1;
}
void SetBlue(void){
	S2=0;
	S3=1;
}
void takeTree(void){
	D4ON;//机械抓打开
	delay_ms(700);
	D2adjust(63);
	D3adjust(99);
	delay_ms(700);
	D1adjust(9);
	delay_ms(700);
	D2adjust(153);
	delay_ms(1000);
	D3adjust(180);
	delay_ms(700);
	D4OFF;
	delay_ms(700);
	D2adjust(63);
	delay_ms(700);
	D3adjust(99);
	delay_ms(700);
	D1adjust(90);
	delay_ms(700);
}
void putTree(u8 mod){
	switch(mod){
		case 1:	
			D1adjust(99);
			D2adjust(99);
			D3adjust(135);
			delay_ms(1000);
			D4ON;
			break;
	}
}
*/