#include "include.h"

#include "oled.h"
#include "bmp.h"

#define max(a,b)  (a)>(b) ? (a):(b)
#define max2(a,b,c)   (a)>(max(a,b))?(a):(max(a,b))
int yanse();
u16 backdistance=500;
//**函数声明
void init(void);//初始化函数
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
void passoneline();//寻单线
void passtowline();//寻双线
void blindtowpath(u32 distance);//双线盲走
void blindonepath(u32 distance);//单线盲走
void blindpath(u32 distance);//盲走
void blindtowpathbackwards(u32 distance);//倒退
//870舵机张开，1570舵机合着

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
	
//**过第一条横线**/	
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
/**过第一条纵线**/	
passtowline();
/**过第二条纵线**/
passtowline();
/**过第三条纵线**/
passtowline();
/**过第四条纵线**/
passtowline();
/**过第五条纵线**/
passtowline();	

/****过第六条纵线**/
passtowline();
delay_ms(250);	
//**右转识别二维码**/		
 turn_left_90(250);
 delay_ms(250);
//**过横线二**/		
passoneline();
//**过横线3**/			
passoneline();
delay_ms(250);
turn_left_180(250);
delay_ms(250);
//**过横线二**/		
passoneline();
//**过横线1**/		
passoneline();
delay_ms(250);
buf3[0]=buf[1];
buf3[1]=buf[2];
buf3[2]=buf[3];
//OLED_ShowString(0,0,buf3,16);
/////////************************************再右转朝向搬运处********************************************/	
turn_right_90(250);
delay_ms(250);
///***********************************返回过第五条纵线*********************************************/		
passtowline();
//***********************************盲走一段距离*********************************************/			
blindtowpath(950);
//***********************************面向物体识别颜色*********************************************/	
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

///***********************************面向物体识别颜色*********************************************/		
	  buf5[1]=yanse()+'0';
//  OLED_ShowString(4,4,buf5,16);
     /*判断是第二个*/
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
		 //判断不是第二个，直接抓取第三个，这三个颜色也就知道了 
     Servo_Mode_Config(870,1500,1499,1499); 
	  delay_ms(250); 
	  blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
	  passtowline();
	  delay_ms(250);
//***********************************面向物体识别颜色*********************************************/	
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
	
	  blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
//////***********************************直走过纵线4*********************************************/
    passtowline();
//***********************************面向物体识别颜色*********************************************/	
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
		//前两个都不是第一个，直接抓取第三个，此时已经识别了两种颜色
		 
	  Servo_Mode_Config(870,1500,1499,1499);
	  delay_ms(250); 
	  blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
      blindtowpath(1600);
//***********************************面向物体识别颜色*********************************************/	
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


void init(void)//初始化函数
{
	
	SysTick_Init();			//系统滴答定时器初始化
//	USART1_Config();		//串口初始化 	A-9-16
	Line_GPIO_Config();//循迹端口初始化，D-1-2-3-4-5-6-7
	Motor_GPIO_Config();	//电机端口初始化，E8-9-16-11,F-0-1-2-3
	Servo_GPIO_Config();	//舵机PWM波端口初始化，B-6-7-9-10
	color_Init();			//颜色传感器初始化	
	uart_init(115200);	 //串口1初始化为9600
	USART3_Initialise(115200);//串口3初始化为115200
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	OLED_Init();			//初始化OLED  
	OLED_Clear(); 
//	Servo_Mode_Config(1600,1800,1800,2250);//初始化
//	USART3_Initialise(115200);//串口3初始化为115200
	
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

/*************************路径4->1****************************/
void path_1()
{
	
	
	  blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_right_90(250);
      delay_ms(200);
			
//////***********************************直走过纵线4*********************************************/
passtowline();
//////***********************************直走过纵线3*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
delay_ms(200);
///***********************************过横线二*********************************************/	
passoneline();
///***********************************盲走*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
	
}
/*************************路径4->2****************************/
void path_2()
{
	  blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
			
//////***********************************直走过纵线4*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
 delay_ms(250);
///***********************************过横线二*********************************************/	
passoneline();	
///***********************************盲走*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
		
}
/*************************路径4->3****************************/
void path_3()
{
	  blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_left_90(250);
      delay_ms(250);
			
//////***********************************直走过纵线5*********************************************/
passtowline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
		
///***********************************过横线二*********************************************/			
passoneline();	
///***********************************盲走*********************************************/	
blindonepath(1800);
blindpath(580);
delay_ms(250);
Servo_Mode_Config(1570,2000,1499,1499);
delay_s(1.65);	
Servo_Mode_Config(870,1500,1499,1499);
delay_ms(250);	
}
/*************************路径5->1****************************/
void path_4()
{
	  blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
			
//////***********************************直走过纵线3*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
delay_ms(250);
///***********************************过横线二*********************************************/	
passoneline();
///***********************************盲走*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
delay_ms(250);	
}
/********************************************路径5->2****************************************************/
void path_5()
{
	  blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
	
///***********************************过横线二*********************************************/	
    passoneline();
///***********************************盲走*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
delay_ms(250);	
}
/*************************路径5->3****************************/
void path_6()
{
	  blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_left_90(250);
      delay_ms(250);
//***********************************直走过纵线5*********************************************/
passtowline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
///***********************************过横线二*********************************************/	
passoneline();
///***********************************盲走*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
delay_ms(250);	
}
/*************************路径6->1****************************/
void path_7()
{
       blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_right_90(250);
      delay_ms(250);
/////***********************************直走过纵线5*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
delay_ms(250);
///***********************************过横线二*********************************************/	
passoneline();
///**盲走**/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
}
/*************************路径6->2****************************/

void path_8()
{
       blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_left_90(250);
      delay_ms(250);
			
//////***********************************直走过纵线4*********************************************/
passtowline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
///***********************************过横线二*********************************************/	
passoneline();
///***********************************盲走*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
}
/*************************路径6->3****************************/
void path_9()
{
       blindtowpathbackwards(backdistance);//倒退
      delay_ms(250);
      turn_left_90(250);
      delay_ms(250);
			
//////***********************************直走过纵线4*********************************************/
passtowline();
//////***********************************直走过纵线5*********************************************/
passtowline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
///***********************************过横线二*********************************************/	
passoneline();
///***********************************盲走*********************************************/	
blindonepath(1800);
blindpath(500);
	delay_ms(250);
	Servo_Mode_Config(1570,2000,1499,1499);
    delay_s(1.65);	
	Servo_Mode_Config(870,1500,1499,1499);
	delay_ms(250);
}
/*************************路径1->4****************************/
void path_10()
{
       blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
passoneline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
//////***********************************直走过纵线4*********************************************/
passtowline();
//////***********************************直走过纵线5*********************************************/
passtowline();
delay_ms(250);
turn_right_90(250);
delay_ms(250);
///***********************************过横线1*********************************************/	
passoneline();
delay_ms(250);
turn_right_90(250);
delay_ms(200);
//***********************************盲走一段距离*********************************************/			
blindtowpath(1300);
//***********************************面向物体识别颜色*********************************************/	
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
/*************************路径1->5****************************/
void path_11()
{
       blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
passoneline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
//////***********************************直走过纵线4*********************************************/
passtowline();
	
delay_ms(250);
turn_right_90(250);
delay_ms(250);	
///***********************************过横线1*********************************************/	
passoneline();
//***********************************面向物体识别颜色*********************************************/	
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
    blindonepath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(500);
	
}
/*************************路径1->6****************************/
void path_12()
{
      blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
passoneline();
/***********************************过横线1*********************************************/	
passoneline();
delay_ms(250);
turn_left_90(250);
delay_ms(250);
	
//***********************************盲走一段距离*********************************************/		
blindtowpath(1200);
//***********************************面向物体识别颜色*********************************************/	
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
/*************************路径2->4****************************/
void path_13()
{
      blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
passoneline();		

/***********************************过横线1*********************************************/	
passoneline();
	
delay_ms(250);
turn_left_90(250);
delay_ms(250);	
	
/////***********************************盲走一段距离*********************************************/		
blindtowpath(1300);
//***********************************面向物体识别颜色*********************************************/	
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
/*************************路径2->5****************************/
void path_14()
{
      blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
passoneline();	
/***********************************过横线1*********************************************/	
passoneline();		
//***********************************面向物体识别颜色*********************************************/	
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
    blindonepath(600);
    delay_ms(250);
	Servo_Mode_Config(1570,1500,1499,1499);
	delay_ms(250);

}
/*************************路径2->6****************************/
void path_15()
{
      blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
passoneline();	
/***********************************过横线1*********************************************/	
passoneline();
delay_ms(250);
turn_right_90(250);
delay_ms(250);		
//***********************************盲走一段距离*********************************************/		
blindtowpath(1450);
//***********************************面向物体识别颜色*********************************************/	
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
/*************************路径3->4****************************/
void path_16()
{
      blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
		
passoneline();
/***********************************过横线1*********************************************/	
passoneline();
	
delay_ms(250);
turn_right_90(250);
delay_ms(250);	
///***********************************盲走*********************************************/	
blindtowpath(1350);
//***********************************面向物体识别颜色*********************************************/	
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

		
		

/*************************路径3->5****************************/
void path_17()
{
     blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
	passoneline();	
/***********************************过横线1*********************************************/	
	passoneline();	
	delay_ms(250);
    turn_right_90(250);
	delay_ms(250);
/************************************过第4条纵线********************************************/
    passtowline();
	delay_ms(250);
//***********************************面向物体识别颜色*********************************************/	
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
/*************************路径3->6****************************/
void path_18()
{
     blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
	passoneline();	
/***********************************过横线1*********************************************/	
	passoneline();	
	delay_ms(250);
turn_right_90(250);
delay_ms(250);	
/************************************过第4条纵线********************************************/
    passtowline();
	/*盲走*/
	blindtowpath(1200);
//***********************************面向物体识别颜色*********************************************/	
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
	  blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
	passoneline();	
/***********************************过横线1*********************************************/	
	passoneline();	
	delay_ms(250);
    turn_right_90(250);
    delay_ms(250);	
/************************************过第2条纵线********************************************/
    passtowline();
/************************************过第1条纵线********************************************/	
	passtowline();
/************************************盲走********************************************/		
    blindtowpath(1300);
	delay_ms(250);
    turn_left_90(250);
    delay_ms(250);
	blindpath(1200);
}
void path_20()
{
	  blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
	passoneline();	
/***********************************过横线1*********************************************/	
	passoneline();	
	delay_ms(250);
    turn_right_90(250);
    delay_ms(250);
/************************************过第3条纵线********************************************/
    passtowline();	
/************************************过第2条纵线********************************************/
    passtowline();
/************************************过第1条纵线********************************************/	
	passtowline();
/************************************盲走********************************************/		
    blindtowpath(1300);
	delay_ms(250);
    turn_left_90(250);
    delay_ms(250);
	blindpath(1200);
}
void path_21()
{
	  blindtowpathbackwards(500);//倒退
      delay_ms(250);
      turn_left_180(250);
      delay_ms(250);
//***********************************过横线2*********************************************/	
	passoneline();	
/***********************************过横线1*********************************************/	
	passoneline();	
	delay_ms(250);
    turn_right_90(250);
    delay_ms(250);
/************************************过第4条纵线********************************************/
    passtowline();
/************************************过第3条纵线********************************************/
    passtowline();	
/************************************过第2条纵线********************************************/
    passtowline();
/************************************过第1条纵线********************************************/	
	passtowline();
/************************************盲走********************************************/		
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
	for(;;)//过出发区纵线-1
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
