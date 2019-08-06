#include<stdio.h>
#include<string.h>
#include "strToInt.h"

bool checkStrInt(char c)
{
	if('0' <= c && ('9' >= c))
		return TRUE;
	else
		return FALSE;
}

bool checkMax(int num, char c)
{
	if((num <= MAX_NUM/10) && ((MAX_NUM - num *10) >= (c - '0')))
		return TRUE;
	else
		return FALSE;
}

bool checkMin(int num, char c)
{
	int m = MIN_NUM;
	int n = int(MIN_NUM)/10;
	int x = MIN_NUM - num *10;
	int y = -(c - '0');
	if((num >= int(MIN_NUM)/10) && ((MIN_NUM - num *10) <= (-(c - '0'))))
		return TRUE;
	else
		return FALSE;
}

int strToInt(char *str)
{
	if((NULL == str)||('\0' == *str))
		return FALSE;
	int flag = 0;
	int num = 0;
	int length = strlen(str);
	if('-' == *str)
	{
		flag = 1;
		str++;
	}
	while('\0'!=*str)
	{
		if(checkStrInt(*str))
		{
			if(flag)         //字符串里的数字是负数
			{
				if(checkMin(num,*str))
				{
					num = num*10 - (*str - '0');
				}
				else
				{
					return FALSE;
				}
			}
			else
			{
				if(checkMax(num,*str))
				{
					num = num*10 + (*str - '0');
				}
				else
				{
					return FALSE;
				}
			}
		}
		str++;
	}
	return num;
}

