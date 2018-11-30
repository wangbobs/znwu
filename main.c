#include "include.h"

#include "oled.h"
#include "bmp.h"

#define max(a,b)  (a)>(b) ? (a):(b)
#define max2(a,b,c)   (a)>(max(a,b))?(a):(max(a,b))
int yanse();
u8 width1=23,width2=20;
u8 d1=14,d2=15,d3=12,d4=15,d5=12,flag=0;//过横线前进距离、过纵线前近距离

u8 q1_flag=0,q2_flag=0;//暂时存货区标志
u8 A=0,B=0,C=0,D=0,E=0;
u16 pp;//舵机角度变量	
u8 j=0;
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
void passoneline();//寻单线
void passtowline();//寻双线
void Back_starting_point(void);//回到原点
//870舵机张开，1570舵机合着
void test(void);//测试函数

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

	
	if(buf5[0]=='1')
	{	
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
		
	}

////////************************************过第一条横线********************************************/	
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
	 
		
	//掉过头,准备过第一条纵线
/************************************过第一条纵线********************************************/	
passtowline();
/************************************过第二条纵线********************************************/
passtowline();
/************************************过第三条纵线********************************************/
passtowline();
/************************************过第四条纵线********************************************/
passtowline();
/************************************过第五条纵线********************************************/
passtowline();	

/************************************过第六条纵线********************************************/
passtowline();
delay_ms(250);	
/////////************************************右转识别二维码********************************************/		
 turn_left_90(250);
 delay_ms(250);
//////////***********************************过横线二*********************************************/		
passoneline();
///////////***********************************过横线3*********************************************/			
passoneline();

delay_ms(250);
turn_left_180(250);
delay_ms(250);
////***********************************过横线二*********************************************/		
passoneline();
//////***********************************过横线1*********************************************/		
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
		for(i=0;i<1500;i++)
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

	
///////////***********************************面向物体识别颜色*********************************************/	
	turn_left_90(250);
	delay_ms(250);
	Servo_Mode_Config(870,1000,1499,1499);
    delay_s(1.7);
	Servo_Mode_Config(870,1500,1499,1499);
    for(i=0;i<500;i++)forward(200);
    delay_ms(250);
    Servo_Mode_Config(1500,1500,1499,1499);
	buf5[0]=yanse()+'0';
//    OLED_ShowString(4,4,buf5,16);
//	if(buf5[0]==buf3[0])	
//	{	switch(buf5[0])	
//		{
//		case '1':path_1();break;
//		case '2':path_2();break;
//		case '3':path_3();break;	
//		}
//		
//	}
//		
//		
//	 
//if(buf5[0]==buf3[0])
//	{
//if(buf5[0]=='1')
//		{
//	
//		
//	}
//		
//	
//if(buf5[0]=='2')
//{
//		for(i=0;i<30;i++)backwards(70);
//	stop();delay_ms(250);
//     turn_right_90(40);
//	   stop();
//      delay_ms(200);
////////***********************************直走过纵线4*********************************************/
//		for(;;)//过出发区纵线-1
//		{
//			if( line2 & !line3& line4 )forward(40);
//		   else if(line2&line3&line4 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//       for(i=0;i<7;i++)forward(40);
//			stop();delay_ms(250);
//     turn_right_90(40);
//	   stop();
//      delay_ms(200);
/////***********************************过横线二*********************************************/	
//		
//		for(;;)													
//		{
//			if( !line2 &line3& !line4 )forward(40); 					//*016*	
//			else if( line2&line3&line4 ){stop();break;}//11111
//			else if( line1 )turn_left(40); //
//			else if( line1& line2 )turn_left(40); //
//			else if( line2& line3 )turn_left(40); //
//			else if( line5 )turn_right(40); //
//			else if( line4& line5 )turn_right(40); //
//			else if(line3&line4 )turn_right(40);
//			else forward(40);
//		}
//		for(i=0;i<2;i++)forward(40);	
/////***********************************盲走*********************************************/	
//       for(i=0;i<28;i++)forward(40);
//	{	if( !line2 &line3& !line4 )forward(40); 					//*016*	
//	    else if( line2&line3&line4 )forward(40); //11111
//		else if( line1 )turn_left(40); //
//		else if( line1& line2 )turn_left(40); //
//		else if( line2& line3 )turn_left(40); //
//		else if( line5 )turn_right(40); //
//		else if( line4& line5 )turn_right(40); //
//		else if(line3&line4 )turn_right(40);
//		else forward(40);	
//    }
//	stop();delay_ms(100);
//	Servo_Mode_Config(2000,2200,1499,1499);
//    delay_s(1.65);	
//	Servo_Mode_Config(2000,2000,1499,1499);	
//	}
//	
//if(buf5[0]=='3')
//	{
//	for(i=0;i<30;i++)backwards(70);
//	stop();delay_ms(250);
//     turn_left_90(40);
//	   stop();
//      delay_ms(200);
////////***********************************直走过纵线5*********************************************/
//		for(;;)//过出发区纵线-1
//		{
//			if( line2 & !line3& line4 )forward(40);
//		   else if(line2&line3&line4 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//       for(i=0;i<7;i++)forward(40);
//	stop();delay_ms(250);
//     turn_left_90(40);
//	   stop();
//      delay_ms(200);
/////***********************************过横线二*********************************************/	
//		
//		for(;;)													
//		{
//			if( !line2 &line3& !line4 )forward(40); 					//*016*	
//			else if( line2&line3&line4 ){stop();break;}//11111
//			else if( line1 )turn_left(40); //
//			else if( line1& line2 )turn_left(40); //
//			else if( line2& line3 )turn_left(40); //
//			else if( line5 )turn_right(40); //
//			else if( line4& line5 )turn_right(40); //
//			else if(line3&line4 )turn_right(40);
//			else forward(40);
//		}
//		for(i=0;i<2;i++)forward(40);	
/////***********************************盲走*********************************************/	
//       for(i=0;i<28;i++)forward(40);
//	{	if( !line2 &line3& !line4 )forward(40); 					//*016*	
//	    else if( line2&line3&line4 )forward(40); //11111
//		else if( line1 )turn_left(40); //
//		else if( line1& line2 )turn_left(40); //
//		else if( line2& line3 )turn_left(40); //
//		else if( line5 )turn_right(40); //
//		else if( line4& line5 )turn_right(40); //
//		else if(line3&line4 )turn_right(40);
//		else forward(40);	
//    }
//	stop();delay_ms(100);
//	Servo_Mode_Config(2000,2200,1499,1499);
//    delay_s(1.65);	
//	Servo_Mode_Config(2000,2000,1499,1499);	
//	}
//	

//}
//	

//else
//{
//	/////////***********************************后退左转*********************************************/
//		
//    for(i=0;i<30;i++)backwards(70);
//	stop();delay_ms(250);
//     turn_right_90(40);
//	   stop();
//      delay_ms(200);	
//      
//	
/////////***********************************直走过纵线4*********************************************/
//		for(;;)//过出发区纵线-1
//		{
//			if( line2 & !line3& line4 )forward(40);
//		   else if(line2&line3&line4 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//     for(i=0;i<7;i++)forward(40);
///////////***********************************左转*********************************************/

//	stop();delay_ms(250);
//     turn_left_90(40);
//	   stop();
//      delay_s(1);
//		
//    for(i=0;i<38;i++)forward(40);
//	{	if( !line2 &line3& !line4 )forward(40); 					//*016*	
//	    else if( line2&line3&line4 )forward(40); //11111
//		else if( line1 )turn_left(40); //
//		else if( line1& line2 )turn_left(40); //
//		else if( line2& line3 )turn_left(40); //
//		else if( line5 )turn_right(40); //
//		else if( line4& line5 )turn_right(40); //
//		else if(line3&line4 )turn_right(40);
//		else forward(40);	
//    }
//	stop();delay_ms(250);
//	Servo_Mode_Config(2000,2000,1499,1499);
//	buf5[1]=yanse()+'0';
//    OLED_ShowString(8,0,buf5,16);
//	
//if(buf5[1]==buf3[0])
//	{
//		if(buf5[1]=='1')
//		{
//			
//	for(i=0;i<35;i++)backwards(70);
//	stop();delay_ms(250);
//     turn_right_90(40);
//	   stop();
//      delay_ms(200);
//			
////////***********************************直走过纵线4*********************************************/
//		for(;;)//过出发区纵线-1
//		{
//			if( line2 & !line3& line4 )forward(40);
//		   else if(line2&line3&line4 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//       for(i=0;i<7;i++)forward(40);

//	stop();delay_ms(250);
//     turn_right_90(40);
//	   stop();
//      delay_ms(200);
/////***********************************过横线二*********************************************/	
//		
//		for(;;)													
//		{
//			if( !line2 &line3& !line4 )forward(40); 					//*016*	
//			else if( line2&line3&line4 ){stop();break;}//11111
//			else if( line1 )turn_left(40); //
//			else if( line1& line2 )turn_left(40); //
//			else if( line2& line3 )turn_left(40); //
//			else if( line5 )turn_right(40); //
//			else if( line4& line5 )turn_right(40); //
//			else if(line3&line4 )turn_right(40);
//			else forward(40);
//		}
//		for(i=0;i<2;i++)forward(40);	
/////***********************************盲走*********************************************/	
//       for(i=0;i<25;i++)forward(40);
//	{	if( !line2 &line3& !line4 )forward(40); 					//*016*	
//	    else if( line2&line3&line4 )forward(40); //11111
//		else if( line1 )turn_left(40); //
//		else if( line1& line2 )turn_left(40); //
//		else if( line2& line3 )turn_left(40); //
//		else if( line5 )turn_right(40); //
//		else if( line4& line5 )turn_right(40); //
//		else if(line3&line4 )turn_right(40);
//		else forward(40);	
//    }
//	stop();delay_ms(100);
//	Servo_Mode_Config(2000,2200,1499,1499);
//    delay_s(1.65);	
//	Servo_Mode_Config(2000,2000,1499,1499);	
//	
//		
//	}
//		
//	
//	if(buf5[1]=='2')
//{
//	for(i=0;i<30;i++)backwards(70);
//	stop();
//   delay_ms(250);
//   turn_left_180(40);stop();
//   delay_ms(200);

/////***********************************过横线二*********************************************/	
//		
//		for(;;)													
//		{
//			if( !line2 &line3& !line4 )forward(40); 					//*016*	
//			else if( line2&line3&line4 ){stop();break;}//11111
//			else if( line1 )turn_left(40); //
//			else if( line1& line2 )turn_left(40); //
//			else if( line2& line3 )turn_left(40); //
//			else if( line5 )turn_right(40); //
//			else if( line4& line5 )turn_right(40); //
//			else if(line3&line4 )turn_right(40);
//			else forward(40);
//		}
//		for(i=0;i<2;i++)forward(40);	
/////***********************************盲走*********************************************/	
//       for(i=0;i<35;i++)forward(40);
//	{	if( !line2 &line3& !line4 )forward(40); 					//*016*	
//	    else if( line2&line3&line4 )forward(40); //11111
//		else if( line1 )turn_left(40); //
//		else if( line1& line2 )turn_left(40); //
//		else if( line2& line3 )turn_left(40); //
//		else if( line5 )turn_right(40); //
//		else if( line4& line5 )turn_right(40); //
//		else if(line3&line4 )turn_right(40);
//		else forward(40);	
//    }
//	stop();delay_ms(100);
//	Servo_Mode_Config(2000,2200,1499,1499);
//    delay_s(1.65);	
//	Servo_Mode_Config(2000,2000,1499,1499);	
//	}
//	
//	if(buf5[1]=='3')
//	{
//	for(i=0;i<30;i++)backwards(70);
//	stop();delay_ms(250);
//     turn_left_90(40);
//	   stop();
//      delay_ms(200);
////////***********************************直走过纵线5*********************************************/
//		for(;;)//过出发区纵线-1
//		{
//			if( line2 & !line3& line4 )forward(40);
//		   else if(line2&line3&line4 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//       for(i=0;i<7;i++)forward(40);
//	stop();delay_ms(250);
//     turn_left_90(40);
//	   stop();
//      delay_ms(200);
/////***********************************过横线二*********************************************/	
//		
//		for(;;)													
//		{
//			if( !line2 &line3& !line4 )forward(40); 					//*016*	
//			else if( line2&line3&line4 ){stop();break;}//11111
//			else if( line1 )turn_left(40); //
//			else if( line1& line2 )turn_left(40); //
//			else if( line2& line3 )turn_left(40); //
//			else if( line5 )turn_right(40); //
//			else if( line4& line5 )turn_right(40); //
//			else if(line3&line4 )turn_right(40);
//			else forward(40);
//		}
//		for(i=0;i<2;i++)forward(40);	
/////***********************************盲走*********************************************/	
//       for(i=0;i<35;i++)forward(40);
//	{	if( !line2 &line3& !line4 )forward(40); 					//*016*	
//	    else if( line2&line3&line4 )forward(40); //11111
//		else if( line1 )turn_left(40); //
//		else if( line1& line2 )turn_left(40); //
//		else if( line2& line3 )turn_left(40); //
//		else if( line5 )turn_right(40); //
//		else if( line4& line5 )turn_right(40); //
//		else if(line3&line4 )turn_right(40);
//		else forward(40);	
//    }
//	stop();delay_ms(100);
//	Servo_Mode_Config(2000,2200,1499,1499);
//    delay_s(1.65);	
//	Servo_Mode_Config(2000,2000,1499,1499);	
//	}
//	

//}
//	
//else
//	{
///////////***********************************后退左转*********************************************/
//		
//    for(i=0;i<30;i++)backwards(70);
//	stop();delay_ms(250);
//     turn_right_90(40);
//	   stop();
//      delay_ms(200);	
//      
//	
//for(i=0;i<28;i++)													//走向物块前方
//		{
//			if( line2 & !line3& line4 )forward(40);
//		    else if( line1&line2&line3&line4&line5 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//		stop();
//		delay_ms(250);
//	
///////////***********************************面向物体识别颜色*********************************************/	
//	turn_left_90(40);
//	stop();
//	delay_ms(250);
//    for(i=0;i<25;i++)forward(40);stop();delay_ms(250);
//	stop();
//	Servo_Mode_Config(2000,2200,1499,1499);
//    delay_s(1);
//	buf5[2]=yanse()+'0';
//    OLED_ShowString(8,0,buf5,16);
//		
//		if(buf5[2]=='1')
//		{
//			
//	for(i=0;i<35;i++)backwards(70);
//	stop();delay_ms(250);
//     turn_right_90(40);
//	   stop();
//      delay_ms(200);
//			
////////***********************************直走过纵线3*********************************************/
//		for(;;)//过出发区纵线-1
//		{
//			if( line2 & !line3& line4 )forward(40);
//		   else if(line2&line3&line4 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//       for(i=0;i<7;i++)forward(40);

//	stop();delay_ms(250);
//     turn_right_90(40);
//	   stop();
//      delay_ms(200);
/////***********************************过横线二*********************************************/	
//		
//		for(;;)													
//		{
//			if( !line2 &line3& !line4 )forward(40); 					//*016*	
//			else if( line2&line3&line4 ){stop();break;}//11111
//			else if( line1 )turn_left(40); //
//			else if( line1& line2 )turn_left(40); //
//			else if( line2& line3 )turn_left(40); //
//			else if( line5 )turn_right(40); //
//			else if( line4& line5 )turn_right(40); //
//			else if(line3&line4 )turn_right(40);
//			else forward(40);
//		}
//		for(i=0;i<2;i++)forward(40);	
/////***********************************盲走*********************************************/	
//       for(i=0;i<35;i++)forward(40);
//	{	if( !line2 &line3& !line4 )forward(40); 					//*016*	
//	    else if( line2&line3&line4 )forward(40); //11111
//		else if( line1 )turn_left(40); //
//		else if( line1& line2 )turn_left(40); //
//		else if( line2& line3 )turn_left(40); //
//		else if( line5 )turn_right(40); //
//		else if( line4& line5 )turn_right(40); //
//		else if(line3&line4 )turn_right(40);
//		else forward(40);	
//    }
//	stop();delay_ms(100);
//	Servo_Mode_Config(2000,2200,1499,1499);
//    delay_s(1.65);	
//	Servo_Mode_Config(2000,2000,1499,1499);	
//	
//		
//	}
//		
//	
//	if(buf5[1]=='2')
//{
//	for(i=0;i<30;i++)backwards(70);
//	stop();
//   delay_ms(250);
//   turn_left_90(40);stop();
//   delay_ms(200);
////////***********************************直走过纵线4*********************************************/
//		for(;;)//过出发区纵线-1
//		{
//			if( line2 & !line3& line4 )forward(40);
//		   else if(line2&line3&line4 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//       for(i=0;i<7;i++)forward(40);
//		stop();
//   delay_ms(250);
//   turn_left_90(40);stop();
//   delay_ms(200);
//		
/////***********************************过横线二*********************************************/	
//		
//		for(;;)													
//		{
//			if( !line2 &line3& !line4 )forward(40); 					//*016*	
//			else if( line2&line3&line4 ){stop();break;}//11111
//			else if( line1 )turn_left(40); //
//			else if( line1& line2 )turn_left(40); //
//			else if( line2& line3 )turn_left(40); //
//			else if( line5 )turn_right(40); //
//			else if( line4& line5 )turn_right(40); //
//			else if(line3&line4 )turn_right(40);
//			else forward(40);
//		}
//		for(i=0;i<2;i++)forward(40);	
/////***********************************盲走*********************************************/	
//       for(i=0;i<35;i++)forward(40);
//	{	if( !line2 &line3& !line4 )forward(40); 					//*016*	
//	    else if( line2&line3&line4 )forward(40); //11111
//		else if( line1 )turn_left(40); //
//		else if( line1& line2 )turn_left(40); //
//		else if( line2& line3 )turn_left(40); //
//		else if( line5 )turn_right(40); //
//		else if( line4& line5 )turn_right(40); //
//		else if(line3&line4 )turn_right(40);
//		else forward(40);	
//    }
//	stop();delay_ms(100);
//	Servo_Mode_Config(2000,2200,1499,1499);
//    delay_s(1.65);	
//	Servo_Mode_Config(2000,2000,1499,1499);	
//	}
//	
//if(buf5[1]=='3')
//	{
//	for(i=0;i<30;i++)backwards(70);
//	stop();delay_ms(250);
//     turn_left_90(40);
//	   stop();
//      delay_ms(200);
////////***********************************直走过纵线4*********************************************/
//		for(;;)//过出发区纵线-1
//		{
//			if( line2 & !line3& line4 )forward(40);
//		   else if(line2&line3&line4 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//       for(i=0;i<7;i++)forward(40);
////////***********************************直走过纵线5*********************************************/
//		for(;;)//过出发区纵线-1
//		{
//			if( line2 & !line3& line4 )forward(40);
//		   else if(line2&line3&line4 ){stop();break;}//11111
//			else if(!line4&!line5)turn_left(40);
//			else if(!line1&!line2)turn_right(40);		
//			else if(line3& !line2)turn_right(40); //
//			else if(!line4&line3)turn_left(40);//
//			else if(line5& !line2)turn_right(40); //
//			else if(line1&!line4)turn_left(40);//	

//			else forward(40);	
//		}
//       for(i=0;i<7;i++)forward(40);
//	stop();delay_ms(250);
//     turn_left_90(40);
//	   stop();
//      delay_ms(200);
/////***********************************过横线二*********************************************/	
//		
//		for(;;)													
//		{
//			if( !line2 &line3& !line4 )forward(40); 					//*016*	
//			else if( line2&line3&line4 ){stop();break;}//11111
//			else if( line1 )turn_left(40); //
//			else if( line1& line2 )turn_left(40); //
//			else if( line2& line3 )turn_left(40); //
//			else if( line5 )turn_right(40); //
//			else if( line4& line5 )turn_right(40); //
//			else if(line3&line4 )turn_right(40);
//			else forward(40);
//		}
//		for(i=0;i<2;i++)forward(40);	
/////***********************************盲走*********************************************/	
//       for(i=0;i<35;i++)forward(40);
//	{	if( !line2 &line3& !line4 )forward(40); 					//*016*	
//	    else if( line2&line3&line4 )forward(40); //11111
//		else if( line1 )turn_left(40); //
//		else if( line1& line2 )turn_left(40); //
//		else if( line2& line3 )turn_left(40); //
//		else if( line5 )turn_right(40); //
//		else if( line4& line5 )turn_right(40); //
//		else if(line3&line4 )turn_right(40);
//		else forward(40);	
//    }
//	stop();delay_ms(100);
//	Servo_Mode_Config(2000,2200,1499,1499);
//    delay_s(1.65);	
//	Servo_Mode_Config(2000,2000,1499,1499);	
//	}
//		
//	}


//}
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








         6               5               4

******************************************************/

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