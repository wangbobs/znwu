
#ifndef  __INCLUDE_H__
#define  __INCLUDE_H__

//标准C库函数
#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdlib.h>
#include    <stdarg.h>

//STM32内核相关头文件
#include "stm32f10x.h"
#include "core_cm3.h"

//硬件接口相关头文件
#include "sys.h"
#include "usart1.h"
#include "bsp_SysTick.h"
#include "motor.h"
#include "line.h"
#include "duoji.h"
#include "color.h"

#define g 1
#define r 3
#define b 5
#define w 2
#define bl 4

#endif
