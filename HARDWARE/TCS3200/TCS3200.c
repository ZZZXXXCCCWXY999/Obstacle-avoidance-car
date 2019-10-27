#include "led.h"
#include "tcs3200.h"
#include "exti.h"
#include "delay.h"

//u16 Rgena=1,Ggena=1,Bgena=1;//���ڵ��ڰ�ƽ��
u16 Ramount=0,Gamount=0,Bamount=0;//���ڴ�Ŷ�ȡ��RGBֵ
u16 amount=0;//�жϼ���

_RGB RGB;

/*****************************************************************************
   Hָhue��ɫ�ࣩ��Sָsaturation�����Ͷȣ���Lָlightness�����ȣ���Vָvalue(ɫ��)��Bָbrightness�����ȣ���

  ɫ�ࣨH����ɫ�ʵĻ������ԣ�����ƽ����˵����ɫ���ƣ����ɫ����ɫ�ȡ� 
  ���Ͷȣ�S����ָɫ�ʵĴ��ȣ�Խ��ɫ��Խ���������𽥱�ң�ȡ0-100%����ֵ��
  ���ȣ�V�������ȣ�B����ȡ0-100%�� 	
  
   0��:   ��ɫ��RGB:(255, 0,  0 ), 255:R, 0:B��G+���� 
   60��:  ��ɫ��RGB:(255,255, 0 )��255:G, 0:B, R-����
   120��: ��ɫ��RGB:( 0, 255, 0 )��255:G, 0:R��B+����
   180��: ��ɫ��RGB:( 0, 255,255)��255:B, 0:R��G-����
   240��: ��ɫ��RGB:( 0,  0, 255)��255:B, 0:G��R+����
   300��: ��ɫ��RGB:(255, 0, 255)��255:R, 0:G��B-����
   360��: ��ɫ��RGB:(255, 0,  0 )��255:R, 0:B��G+	

  RGBת����HSV���㷨					        
������ max=max(R,G,B)
������ min=min(R,G,B)
����   if R = max, H = (G-B)/(max-min)
������ if G = max, H = 2 + (B-R)/(max-min)
������ if B = max, H = 4 + (R-G)/(max-min)
������ H = H * 60
������ if H < 0, H = H + 360
������ V=max(R,G,B)
������ S=(max-min)/max
******************************************************************************/

void TCS3200_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOA, &GPIO_InitStructure);			

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*******************************************
*
*		  ��ƽ��
*
*******************************************/
void WhiteBalance(void)
{
	S2=0;S3=0;//��ɫͨ��
	amount=0;			 //��ʼ����
	delay_ms(10);
	RGB.Rgena = amount;   //�����ɫ����      
	amount=0;

	S2=1;S3=1;//��ɫͨ��
	amount=0;
	delay_ms(10);
	RGB.Ggena = amount;	 //�����ɫ����
	amount=0;

	S2=0;S3=1;//��ɫͨ��
	amount=0;
	delay_ms(10);
	RGB.Bgena = amount;	  //�����ɫ����
	amount=0;
	S2=1;S3=0;//�ر�ͨ��  	  
} 

/*******************************************
*
*		  RGB��ȡ
*
*******************************************/
u16 tcs3200_GREEN(void)
{
	S2=1;S3=1;
	amount=0;
	delay_ms(10);
	S2=1;S3=0;//�ر�ͨ�� 
	Gamount=(u32) amount*255/RGB.Ggena;	//ȡGֵ
	if(Gamount>255) Gamount = 255;
	return Gamount;
}

u16 tcs3200_BLUE(void)
{
	S2=0;S3=1;
	amount=0;
	delay_ms(10);
	S2=1;S3=0;//�ر�ͨ�� 
	Bamount=(u32) amount*255/RGB.Bgena;//ȡBֵ	
	if(Bamount>255) Bamount = 255;
	return Bamount;
} 

 
