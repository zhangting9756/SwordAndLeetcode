//#include "stdafx.h"
//#include <string.h>
//#include <stdlib.h>
//#include "zt1.h"

#include<stdio.h>
#include<string.h>
#include "stdafx.h"
#include <stdlib.h>
#include  <malloc.h>
#include "huiWen.h"

void swapChar(char *s,int low,int high)
{
	char temp = s[low];
	s[low]=s[high];
	s[high]=temp;
}
int reserveCheck(char *s,int length)
{
	int high = length-1;
	int low = 0;
	if (NULL == s || 1>length)
	{
		printf("the string is NULL!\n");
		return 0;
	}
	while (low <= high)
	{
		printf("s[%d]:%c s[%d]:%c\n", low, s[low], high, s[high]);
		if (s[low++] != s[high--])
			return 0;
	}
	return 1;

}

void reserve(char *s, int from,int end)
{
	if (NULL == s || 0 >(end - from))
	{
		printf("the string is NULL!\n");
		return ;
	}
	while (from <= end)
	{
		char c =  s[from];
		printf("a[%d] is:%c a[%d] is:%c", from, s[from], end, s[end]);
		s[from] = s[end];
		s [end] = c;
		from++;
		end--;
	}
	return;
}

void reserveString(char *s)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int length = strlen(s);
	reserve(s,0,length-1);
	for(i=0;i<length;i++)
	{
		if(s[i]==' '||(i == length-1))
		{
			end = i-1;
			reserve(s,start,end);
			start = i+1;
		}
	}
}

int maxHuiWen(char *s,int length)
{
	int i,j;
	int max = 0;
	int templeMax = 0;
	for(i=0;i<length;i++)
	{
		for(j=0;(((i-j)>=0) && ((i+j)<length));++j)     //奇数情况
		{
			if(s[i-j] != s[i+j])
				break;
		}
		templeMax = (j-1)*2 +1;
		if(templeMax > max)
			max = templeMax;
		for(j=0;(((i-j)>=0) && ((i+j)<length));++j)     //偶数情况
		{
			if(s[i-j] != s[i+j+1])
				break;
		}
		templeMax = (j-1)*2 +2;
		if(templeMax > max)
			max = templeMax;
	}
	return max;
}

void calcAllPermutation(char *s,int from,int to)
{
	if(from == to)
	{
		for(int m = 0;m<=to;m++)
			printf("%c",s[m]);
		printf("\n");
	}
	else
	{
		for(int i=from;i<=to;i++)
		{
			swapChar(s,from,i);
			calcAllPermutation(s,from+1,to);
			swapChar(s,from,i);
		}
	}
}



bool stringContain(char *a, char *b)
{
	int alength = strlen(a);
	int blength = strlen(b);
	int hash = 0;
	int i = 0;
	for(i = 0;i<alength;++i)
	{
		hash |= (1<<(a[i]-'A'));
	}
	for(i = 0;i<blength;++i)
	{
		if((hash & (1<<(b[i]-'A'))) == 0)
			return false;
	}
	return true;
}
