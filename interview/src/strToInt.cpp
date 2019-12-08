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
	if((num > MAX_NUM / 10) || (num == MAX_NUM / 10 && (c - '0') > 7))
		return TRUE;
	else
		return FALSE;
}

bool checkMin(int num, char c)
{
	if((num >= int(MIN_NUM)/10) && ((MIN_NUM - num *10) <= (-(c - '0'))))
		return TRUE;
	else
		return FALSE;
}

int strToInt(char *str)
{
	if((NULL == str)||('\0' == *str))
		return FALSE;
	int flag = 1;
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
			if(checkMax(num,*str))
			{
				return (flag == 1) ?MAX_NUM : MIN_NUM;
			}
			num = 10 * num + (*str - '0');
		}
		str++;
	}
	return num*flag;
}

