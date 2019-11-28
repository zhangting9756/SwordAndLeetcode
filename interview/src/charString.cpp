
#include<stdio.h>
#include<string.h>
#include "stdafx.h"
#include <stdlib.h>
#include  <malloc.h>


#include "charString.h"

/*交换两个字符*/
void swapChar(char *s,int low,int high)
{
	char temp = s[low];
	s[low]=s[high];
	s[high]=temp;
}
/*检验是否为回文字符串*/
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
		if (s[low++] != s[high--])
			return 0;
	}
	return 1;

}
/*翻转字符串*/
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
		s[from] = s[end];
		s [end] = c;
		from++;
		end--;
	}
	return;
}

/*翻转单词顺序 剑指offer42
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
eg：“I am a student.”输出“student. a am I”
左旋也可以使用,
给定一个字符串，要求把字符串前面的若干个字符移动到字符串的尾部，
如把字符串“abcdef”前面的2个字符'a'和'b'移动到字符串的尾部，使得原字符串变成字符串“cdefab”。
请写一个函数完成此功能，要求对长度为n的字符串操作的时间复杂度为 O(n)，空间复杂度为 O(1)。
*/
void reserveString(char *s)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int length = strlen(s);
	reserve(s,0,length-1);
	char *pBegin = s;
	char *pEnd = s;
	while(*pBegin != '\0')
	{
		if(*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
			start++;
			end++;
		}
		else if((*pEnd == ' ')||(*pEnd == '\0'))
		{
			reserve(s,start,--end);
			pBegin = pEnd;
			start = ++end;
		}
		else
		{
			*pEnd++;
			end++;
		}
	}
}

/*找出最大回文字符串*/
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

/*
给定两个分别由字母组成的字符串A和字符串B，字符串B的长度比字符串A短。
请问，如何最快地判断字符串B中所有字母是否都在字符串A里？
*/

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
