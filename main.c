#include "include.h"

#include "oled.h"
#include "bmp.h"

#define max(a,b)  (a)>(b) ? (a):(b)
#define max2(a,b,c)   (a)>(max(a,b))?(a):(max(a,b))
int yanse();
u16 backdistance=500;
//**��������
void init(void);//��ʼ������
void path_1();
void path_2();
void path_3();
void path_4();
void path_5();
void path_6();
void path_7();
void path_8();
void path_9();
void path_10();
void path_11();
void path_12();
void path_13();
void path_14();
void path_15();
void path_16();
void path_17();
void path_18();
void path_19();
void path_20();
void path_21();
void passoneline();//Ѱ����
void passtowline();//Ѱ˫��
void blindtowpath(u32 distance);//˫��ä��
void blindonepath(u32 distance);//����ä��
void blindpath(u32 distance);//ä��
void blindtowpathbackwards(u32 distance);//����
//870����ſ���1570�������

     extern  u16 data2;
     u8 buf[10]="0000000000";
     u8 buf2[10];
	 u8 buf3[3]="000";
	 u8 buf4[3]={0,0,0};
	 u8 buf5[3]="000";
	 u8 flag2=0;
int main(void)
{
	u32 i;
	u8 cloer;
	u8 t;
	init();	
	
//**����һ������**/	
	for(;;)
		{
			if( !line2 &line3& !line4 )forward(200); 				//*016*	
			else if( line1&line2&line3&line4&line5 ){break;}//11111	
			else if( line5& !line2 )turn_right(250); //
			else if(line1&!line4 )turn_left(250);//
			else forward(200);
		}
		for(i=0;i<480;i++)forward(200); 
		delay_ms(250);	
		turn_right_90(250);
/**����һ������**/	
passtowline();
/**���ڶ�������**/
passtowline();
/**������������**/
passtowline();
/**������������**/
passtowline();
/**������������**/
passtowline();	

/****������������**/
passtowline();
delay_ms(250);	
//**��תʶ���ά��**/		
 turn_left_90(250);
 delay_ms(250);
//**�����߶�**/		
passoneline();
//**������3**/			
passoneline();
delay_ms(250);
turn_left_180(250);
delay_ms(250);
//**�����߶�**/		
passoneline();
//**������1**/		
passoneline();
delay_ms(250);
buf3[0]=buf[1];
buf3[1]=buf[2];
buf3[2]=buf[3];
//OLED_ShowString(0,0,buf3,16);
/////////************************************����ת������˴�********************************************/	
turn_right_90(250);
delay_ms(250);
///***********************************���ع�����������*********************************************/		
passtowline();
//***********************************ä��һ�ξ���*********************************************/			
blindtowpath(950);
//***********************************��������ʶ����ɫ*********************************************/	
	turn_left_90(250);
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
    for(i=0;i<580;i++)forward(200);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	buf5[0]=yanse()+'0';
	if(buf5[0]==buf3[0])	
	{

		switch(buf5[0])	
		{
		case '1':path_1();path_11();break;
		case '2':path_2();path_14();break;
		case '3':path_3();path_17();break;
        default:break;			
		}

///***********************************��������ʶ����ɫ*********************************************/		
	  buf5[1]=yanse()+'0';
//  OLED_ShowString(4,4,buf5,16);
     /*�ж��ǵڶ���*/
     if(buf5[1]==buf3[1])		
	 {	switch(buf5[1])
		{
        case '1':path_4();path_12();break;
		case '2':path_5();path_15();break;
		case '3':path_6();path_18();break;
        default:break;
		}
        switch(buf3[2])
		{
	    case '1':path_7();path_19();break;
		case '2':path_8();path_20();break;
		case '3':path_9();path_21();break;
        default:break;
			
		}			
	}
	 else
	 {
		 //�жϲ��ǵڶ�����ֱ��ץȡ����������������ɫҲ��֪���� 
     Servo_Mode_Config(870,1500,1499,1499); 
	  delay_ms(250); 
	  blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
	  passtowline();
	  delay_ms(250);
//***********************************��������ʶ����ɫ*********************************************/	
	turn_left_90(250);
	delay_ms(250);
     blindonepath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	switch(buf3[1])
	{
		case '1':path_7();path_11();break;
		case '2':path_8();path_14();break;
		case '3':path_9();path_17();break;
        default:break;	
	}	
		switch(buf3[2])
	{
		case '1':path_4();path_19();break;
		case '2':path_5();path_20();break;
		case '3':path_6();path_21();break;
        default:break;	
	}	
	
	 }
		
	}
		

	
	else
{
	  Servo_Mode_Config(870,1500,1499,1499);
      delay_ms(250);
	
	  blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
//////***********************************ֱ�߹�����4*********************************************/
    passtowline();
//***********************************��������ʶ����ɫ*********************************************/	
	turn_left_90(250);
	delay_ms(250);
    for(i=0;i<550;i++)forward(200);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	buf5[1]=yanse()+'0';
    //OLED_ShowString(4,4,buf5,16);
	if(buf5[1]==buf3[0])	
	{	
		
		switch(buf5[1])
		{
		case '1':path_4();break;
		case '2':path_5();break;
		case '3':path_6();break;
        default:break;
		}
		if(buf5[0]==buf3[1])
		{
		switch(buf3[0])
			{
		case '1':path_10();break;
		case '2':path_13();break;
		case '3':path_16();break;
        default:break;
			}
		switch(buf3[1])
			{
		case '1':path_4();break;
		case '2':path_5();break;
		case '3':path_6();break;
        default:break;
			}
		switch(buf3[1])
			{
		case '1':path_12();break;
		case '2':path_15();break;
		case '3':path_18();break;
        default:break;
			}
		switch(buf3[2])
		{
		case '1':path_7();path_19();break;
		case '2':path_8();path_20();break;
		case '3':path_9();path_21();break;
        default:break;
		}
		}
		else
     
	 {
		switch(buf3[0])
			{
		case '1':path_12();break;
		case '2':path_15();break;
		case '3':path_18();break;
        default:break;
			}
		switch(buf3[1])
			{
		case '1':path_7();path_10();break;
		case '2':path_8();path_13();break;
		case '3':path_9();path_16();break;
        default:break;
			}
		switch(buf3[2])
		{
		case '1':path_1();path_19();break;
		case '2':path_2();path_20();break;
		case '3':path_3();path_21();break;
        default:break;
		}
	 }
	}
   else
	 {
		//ǰ���������ǵ�һ����ֱ��ץȡ����������ʱ�Ѿ�ʶ����������ɫ
		 
	  Servo_Mode_Config(870,1500,1499,1499);
	  delay_ms(250); 
	  blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
      blindtowpath(1600);
//***********************************��������ʶ����ɫ*********************************************/	
	  delay_ms(250);
	  turn_left_90(250);
	 delay_ms(250);
     for(i=0;i<580;i++)forward(200);
     delay_ms(250);
	 Servo_Mode_Config(1570,1500,1499,1499);
    delay_ms(500); 
		switch(buf3[0])
		{
		case '1':path_7();break;
		case '2':path_8();break;
		case '3':path_9();break;
        default:break;
		}
		if(buf5[0]==buf3[1])
	  {
		switch(buf3[0])
		{
		case '1':path_10();break;
		case '2':path_13();break;
		case '3':path_16();break;
        default:break;
		}
		switch(buf3[1])
		{
		case '1':path_1();path_11();break;
		case '2':path_2();path_14();break;
		case '3':path_3();path_17();break;
        default:break;
		}
        switch(buf3[2])
		{
		case '1':path_4();path_19();break;
		case '2':path_5();path_20();break;
		case '3':path_6();path_21();break;
        default:break;
		}		
		
		}
       
  else
       {
		   switch(buf3[0])
		{
		case '1':path_11();break;
		case '2':path_14();break;
		case '3':path_17();break;
        default:break;
		}
		switch(buf3[1])
		{
		case '1':path_4();path_10();break;
		case '2':path_5();path_13();break;
		case '3':path_6();path_16();break;
        default:break;
		}
	     switch(buf3[2])
		{
		case '1':path_1();path_19();break;
		case '2':path_2();path_20();break;
		case '3':path_3();path_21();break;
        default:break;
		}	
		}	
	   }
		 
	 }
	
	
	
	}


void init(void)//��ʼ������
{
	
	SysTick_Init();			//ϵͳ�δ�ʱ����ʼ��
//	USART1_Config();		//���ڳ�ʼ�� 	A-9-16
	Line_GPIO_Config();//ѭ���˿ڳ�ʼ����D-1-2-3-4-5-6-7
	Motor_GPIO_Config();	//����˿ڳ�ʼ����E8-9-16-11,F-0-1-2-3
	Servo_GPIO_Config();	//���PWM���˿ڳ�ʼ����B-6-7-9-10
	color_Init();			//��ɫ��������ʼ��	
	uart_init(115200);	 //����1��ʼ��Ϊ9600
	USART3_Initialise(115200);//����3��ʼ��Ϊ115200
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	OLED_Init();			//��ʼ��OLED  
	OLED_Clear(); 
//	Servo_Mode_Config(1600,1800,1800,2250);//��ʼ��
//	USART3_Initialise(115200);//����3��ʼ��Ϊ115200
	
}


int yanse()
{
	int i=0;
	u8 red=0;
	u8 blue=0;
	u8 green=0;
	u8 ret;
	for(i=0;i<5;i++)
	{
		ret=TCS230_Distinguish2();
		if(ret==1)
		{red++;
		}
		if(ret==2)
		{blue++;
		}
		if(ret==3)
		{green++;
		}
	}
	if(red>blue&&red>green)
	{
		return 1;
	}
	if(blue>red&&blue>green)
	{
		return 3;
	}
	if(green>blue&&green>red)
	{
		return 2;
	}
	
}


/*****************************************************
         1               2               3

//passoneline();
//passtowline();






         6               5               4

******************************************************/

/*************************·��4->1****************************/
void path_1()
{
	
	
	  blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_right_90(250);
      delay_ms(200);
			
//////***********************************ֱ�߹�����4*********************************************/
passtowline();
//////***********************************ֱ�߹�����3*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
delay_ms(200);
///***********************************�����߶�*********************************************/	
passoneline();
///***********************************ä��*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
	
}
/*************************·��4->2****************************/
void path_2()
{
	  blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
			
//////***********************************ֱ�߹�����4*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
 delay_ms(250);
///***********************************�����߶�*********************************************/	
passoneline();	
///***********************************ä��*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
		
}
/*************************·��4->3****************************/
void path_3()
{
	  blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_left_90(250);
      delay_ms(250);
			
//////***********************************ֱ�߹�����5*********************************************/
passtowline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
		
///***********************************�����߶�*********************************************/			
passoneline();	
///***********************************ä��*********************************************/	
blindonepath(1800);
blindpath(580);
delay_ms(250);
Servo_Mode_Config(1570,2000,1499,1499);
delay_s(1.65);	
Servo_Mode_Config(870,1500,1499,1499);
delay_ms(250);	
}
/*************************·��5->1****************************/
void path_4()
{
	  blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
			
//////***********************************ֱ�߹�����3*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
delay_ms(250);
///***********************************�����߶�*********************************************/	
passoneline();
///***********************************ä��*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
delay_ms(250);	
}
/********************************************·��5->2****************************************************/
void path_5()
{
	  blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
	
///***********************************�����߶�*********************************************/	
    passoneline();
///***********************************ä��*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
delay_ms(250);	
}
/*************************·��5->3****************************/
void path_6()
{
	  blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_left_90(250);
      delay_ms(250);
//***********************************ֱ�߹�����5*********************************************/
passtowline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
///***********************************�����߶�*********************************************/	
passoneline();
///***********************************ä��*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
delay_ms(250);	
}
/*************************·��6->1****************************/
void path_7()
{
       blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
/////***********************************ֱ�߹�����5*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
delay_ms(250);
///***********************************�����߶�*********************************************/	
passoneline();
///**ä��**/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
}
/*************************·��6->2****************************/

void path_8()
{
       blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_left_90(250);
      delay_ms(250);
			
//////***********************************ֱ�߹�����4*********************************************/
passtowline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
///***********************************�����߶�*********************************************/	
passoneline();
///***********************************ä��*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
}
/*************************·��6->3****************************/
void path_9()
{
       blindtowpathbackwards(backdistance);//����
      delay_ms(250);
      turn_left_90(250);
      delay_ms(250);
			
//////***********************************ֱ�߹�����4*********************************************/
passtowline();
//////***********************************ֱ�߹�����5*********************************************/
passtowline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
///***********************************�����߶�*********************************************/	
passoneline();
///***********************************ä��*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
}
/*************************·��1->4****************************/
void path_10()
{
       blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
passoneline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
//////***********************************ֱ�߹�����4*********************************************/
passtowline();
//////***********************************ֱ�߹�����5*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
delay_ms(250);
///***********************************������1*********************************************/	
passoneline();
delay_ms(250);
turn_right_90(250);
delay_ms(200);
//***********************************ä��һ�ξ���*********************************************/			
blindtowpath(1300);
//***********************************��������ʶ����ɫ*********************************************/	
	turn_left_90(250);
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
    blindpath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(500);
	
}
/*************************·��1->5****************************/
void path_11()
{
       blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
passoneline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
//////***********************************ֱ�߹�����4*********************************************/
passtowline();
	
delay_ms(250);
turn_right_90(250);
delay_ms(250);	
///***********************************������1*********************************************/	
passoneline();
//***********************************��������ʶ����ɫ*********************************************/	
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
    blindonepath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(500);
	
}
/*************************·��1->6****************************/
void path_12()
{
      blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
passoneline();
/***********************************������1*********************************************/	
passoneline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
	
//***********************************ä��һ�ξ���*********************************************/		
blindtowpath(1200);
//***********************************��������ʶ����ɫ*********************************************/	
	turn_right_90(250);
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
    blindpath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(500);
}
/*************************·��2->4****************************/
void path_13()
{
      blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
passoneline();		

/***********************************������1*********************************************/	
passoneline();
	
delay_ms(250);
turn_left_90(250);
delay_ms(250);	
	
/////***********************************ä��һ�ξ���*********************************************/		
blindtowpath(1300);
//***********************************��������ʶ����ɫ*********************************************/	
	turn_right_90(250);
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
     blindpath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(500);
}
/*************************·��2->5****************************/
void path_14()
{
      blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
passoneline();	
/***********************************������1*********************************************/	
passoneline();		
//***********************************��������ʶ����ɫ*********************************************/	
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
    blindonepath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(250);

}
/*************************·��2->6****************************/
void path_15()
{
      blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
passoneline();	
/***********************************������1*********************************************/	
passoneline();
delay_ms(250);
turn_right_90(250);
delay_ms(250);		
//***********************************ä��һ�ξ���*********************************************/		
blindtowpath(1450);
//***********************************��������ʶ����ɫ*********************************************/	
	turn_left_90(250);
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
     blindpath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(500);
		
}
/*************************·��3->4****************************/
void path_16()
{
      blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
		
passoneline();
/***********************************������1*********************************************/	
passoneline();
	
delay_ms(250);
turn_right_90(250);
delay_ms(250);	
///***********************************ä��*********************************************/	
blindtowpath(1350);
//***********************************��������ʶ����ɫ*********************************************/	
	turn_left_90(250);
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
     blindpath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(500);
}

		
		

/*************************·��3->5****************************/
void path_17()
{
     blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
	passoneline();	
/***********************************������1*********************************************/	
	passoneline();	
	delay_ms(250);
    turn_right_90(250);
	delay_ms(250);
/************************************����4������********************************************/
    passtowline();
	delay_ms(250);
//***********************************��������ʶ����ɫ*********************************************/	
	turn_left_90(250);
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
     blindonepath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(500);
}
/*************************·��3->6****************************/
void path_18()
{
     blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
	passoneline();	
/***********************************������1*********************************************/	
	passoneline();	
	delay_ms(250);
turn_right_90(250);
delay_ms(250);	
/************************************����4������********************************************/
    passtowline();
	/*ä��*/
	blindtowpath(1200);
//***********************************��������ʶ����ɫ*********************************************/	
	turn_left_90(250);
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
     blindpath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(500);

}

void path_19()
{
	  blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
	passoneline();	
/***********************************������1*********************************************/	
	passoneline();	
	delay_ms(250);
    turn_right_90(250);
    delay_ms(250);	
/************************************����2������********************************************/
    passtowline();
/************************************����1������********************************************/	
	passtowline();
/************************************ä��********************************************/		
    blindtowpath(1300);
	delay_ms(250);
    turn_left_90(250);
    delay_ms(250);
	blindpath(1200);
}
void path_20()
{
	  blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
	passoneline();	
/***********************************������1*********************************************/	
	passoneline();	
	delay_ms(250);
    turn_right_90(250);
    delay_ms(250);
/************************************����3������********************************************/
    passtowline();	
/************************************����2������********************************************/
    passtowline();
/************************************����1������********************************************/	
	passtowline();
/************************************ä��********************************************/		
    blindtowpath(1300);
	delay_ms(250);
    turn_left_90(250);
    delay_ms(250);
	blindpath(1200);
}
void path_21()
{
	  blindtowpathbackwards(500);//����
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************������2*********************************************/	
	passoneline();	
/***********************************������1*********************************************/	
	passoneline();	
	delay_ms(250);
    turn_right_90(250);
    delay_ms(250);
/************************************����4������********************************************/
    passtowline();
/************************************����3������********************************************/
    passtowline();	
/************************************����2������********************************************/
    passtowline();
/************************************����1������********************************************/	
	passtowline();
/************************************ä��********************************************/		
    blindtowpath(1300);
	delay_ms(250);
    turn_left_90(250);
    delay_ms(250);
	blindpath(1200);
}
void passoneline()
	
{
	u16 i;
			for(;;)													
		{
			if( !line2 &line3& !line4 )forward(200); 					//*016*	
			else if( line1&line2&line3&line4&line5 ){break;}
			else if( line1 )turn_left(250); //
			else if( line2)turn_left(250); //
			else if( line4 )turn_right(250); //
			else if( line5 )turn_right(250); //
			else forward(200);
		}
			for(i=0;i<500;i++)
		{
	         forward(200);
		}
}
void passtowline()
{
	
	u32 i;
	for(;;)//������������-1
		{
			if( line2 & !line3& line4 )forward(200);
		    else if( line1&line2&line3&line4&line5 ){break;}//11111
			else if(!line4&!line5)turn_left(250);
			else if(!line1&!line2)turn_right(250);		
			else if(line3& !line2)turn_right(250); //
			else if(!line4&line3)turn_left(250);//
			else if(line5& !line2)turn_right(250); //
			else if(line1&!line4)turn_left(250);//	

			else forward(200);	
		}
		for(i=0;i<500;i++)
   		{
		    if( line2 & !line3& line4 )forward(200);
			else if(!line4&!line5)turn_left(250);
			else if(!line1&!line2)turn_right(250);		
			else if(line3& !line2)turn_right(250); //
			else if(!line4&line3)turn_left(250);//
			else if(line5& !line2)turn_right(250); //
			else if(line1&!line4)turn_left(250);//	

			else forward(200);	
		}
}
void blindpath(u32 distance)
{
	u32 i;
	for(i=0;i<distance;i++)
	{
		forward(200);
	}
}
void blindtowpath(u32 distance)
{
	u32 i;
	for(i=0;i<distance;i++)
   		{
		    if( line2 & !line3& line4 )forward(200);
			else if(!line4&!line5)turn_left(250);
			else if(!line1&!line2)turn_right(250);		
			else if(line3& !line2)turn_right(250); //
			else if(!line4&line3)turn_left(250);//
			else if(line5& !line2)turn_right(250); //
			else if(line1&!line4)turn_left(250);//	

			else forward(200);	
		}
	
}
void blindtowpathbackwards(u32 distance)
{
		u32 i;
	for(i=0;i<distance;i++)
   		{	

			 backwards(400);	
		}
}
void blindonepath(u32 distance)
{
	u32 i;
	for(i=0;i<distance;i++)													
		{
			if( !line2 &line3& !line4 )forward(200); 	
			else if( line1 )turn_left(250); //
			else if( line2)turn_left(250); //
			else if( line4 )turn_right(250); //
			else if( line5 )turn_right(250); //
			else forward(200);
		}
}
