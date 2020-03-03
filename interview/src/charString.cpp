
#include<stdio.h>
#include<string.h>
#include "stdafx.h"
#include <stdlib.h>
#include  <malloc.h>


#include "charString.h"
#include "strToInt.h"

/*交换两个字符*/;
void swapChar(char *s,int low,int high)
{
	char temp = s[low];
	s[low]=s[high];
	s[high]=temp;
}

bool checkChar(char c)
{
	if(('a'<=c)&&(c<='z'))
		return 1;
	else if(('A'<=c)&&(c<='Z'))
		return 1;
	else
		return 0;
}
bool checkNum(char c)
{
	return (c>='0'&&c<='9');
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
/*字符串的全排列
*/
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
hash相当于是个位图，出现的字符上置为1，不出现的就是0
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

/*对字符串中的所有单词进行倒排。

说明：

1、每个单词是以26个大写或小写英文字母构成；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；*/

void reserveString1(char *s)
{
	if(NULL == s )
		return;
	int from=0;
	int end = 0;
	int i =0;
	int j = 0;
	int length = strlen(s);
	reserve(s,0,length-1);
	char dest[1000];
	for(i=0;i<length;i++)
	{
		if(checkChar(s[i]))
		{
			dest[j++]=s[i];
			if(i == length-1)
				reserve(dest,from,i);
		}
		else
		{
			if(i==0)
			{
				dest[0]=' ';
				j++;
			}
			if(dest[j-1]==' ')
			{
				continue;
			}
			end = j-1;
			reserve(dest,from,end);
			dest[j]=' ';
			j++;
			from = j;
			end = j;
		}
	}
	dest[j]='\0';
}

/*验证回文字符串,给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。leetcode 字符串*/
bool isPalindrome(char *s)
{
	char *pBegin=s;
	char *pEnd = s;
	while(*pEnd!='\0')
		pEnd++;
	pEnd--;
	while(pBegin<pEnd)
	{
		if(!(checkChar(*pBegin)||checkNum(*pBegin)))
		{
			pBegin++;
			continue;
		}
		if(!(checkChar(*pEnd)||checkNum(*pEnd)))
		{
			pEnd--;
			continue;
		}
		if(('A'<=*pBegin)&&(*pBegin<='Z'))
		{
			*pBegin = *pBegin + 32;
		}
		if(('A'<=*pEnd)&&(*pEnd<='Z'))
		{
			*pEnd = *pEnd + 32;
		}
		if(*pBegin == *pEnd)
		{
			pBegin++;
			pEnd--;
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

/*给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
注意标志位的使用*/

int firstUniqChar(char *s)
{
	
	if (s==NULL)
		return -1;
	int length = strlen(s);
	if(length == 1)
		return 0;
	int i = 0;
	int j = 0;
	int flag = 0;
	for(i=0;i<length;i++)
	{
		flag = 0;
		for(j=0;j<length;j++)
		{
			if(s[i]==s[j]&&j!=i)
			{	
				flag = 1;
				break;
			}
			
		}
		if(flag==0)
			return i;
	}
	return -1;
}

/*整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转*/
bool checkNumMax(int num, int c)
{
	if ((num <= MAX_NUM / 10) && ((MAX_NUM - num * 10) >= c))
		return TRUE;
	else
		return FALSE;
}

bool checkNumMin(int num, int c)
{
	if ((num >= int(MIN_NUM) / 10) && (int(MIN_NUM - num * 10) <= c))
		return TRUE;
	else
		return FALSE;
}
int reverse(int x)
{
	int s = x;
	int flag = 0;
	int num = 0;
	if (x < 0)
	{
		flag = 1;
	}
	if (flag)
	{
		while (s)
		{
			if (checkNumMin(num, s % 10))
			{
				num = num * 10 + s % 10;
				s = s / 10;
			}
			else
			{
				return 0;
			}
			
		}
		
	}
	else
	{
		while (s)
		{
			if (checkNumMax(num, s % 10))
			{
				num = num * 10 + s % 10;
				s = s / 10;
			}
			else
				return 0;
			
		}
	}
	return num;
}

/*有效的字母异位词,给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。leetcode*/
bool isAnagram(char * s, char * t)
{
	int i,num1[123]={0};
	int num2[123]={0};
	int s_len,t_len;
	s_len=strlen(s);
	t_len=strlen(t);
	if(s_len!=t_len) return false;

	for(i=0;i<s_len;i++)
	{    
		num1[(int)s[i]]++;
		num2[(int)t[i]]++;        
	}
	for(i=97;i<123;i++)
	{
		if(num1[i]!=num2[i]) return false;
	}

	return true;

}
/*字符串转换整数 (atoi)leetcode*/
bool checkFirstChar(char c)
{
	if(c == '-')
		return true;
	if(c == '+')
		return true;
	if('0'<=c && c<='9')
		return true;
	return false;
}
int myAtoi(char * str)
{
	if(str == NULL)
		return 0;
	int flag = 1;
	int num = 0;
	while(*str != '\0')
	{
		/*找到第一个非空字符*/
		if(*str!=' ')
		{
			if(checkFirstChar(*str))
			{
				if(*str == '-')
					flag = -1;
				else if(*str == '-')
					flag = 1;
				else
					num = *str -'0';
				break;
			}
			else
				return 0;
		}
		else
		{
			str++;
		}
		
	}
	while(*str++ != '\0'&&(checkStrInt(*str)))
	{
		if(checkMax(num,*str))
		{
			return (flag == 1) ?MAX_NUM : MIN_NUM;
		}
		num = 10 * num + (*str - '0');
	}
	return num*flag;
}
/*实现 strStr()
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。*/
int strStr(char * haystack, char * needle)
{
	if(haystack==NULL || needle == NULL)
		return -1;
	int length1=strlen(haystack);
	int length2=strlen(needle);
	if (length1 == 0 && length2 > 0)
		return -1;
	if(length2 == 0 )
		return 0;
	if(length2>length1)
		return -1;
	int i=0;
	int j=0;
	int m = 0;
	int flag = 0;
	for(i=0;i<length1;i++)
	{
		j = 0;
		if(haystack[i]!=needle[j])
		{
			continue;
		}
		else
		{
			m=i;
			if((length1-m+1)<length2)
				return -1;
			for(j=0;j<length2 && m<length1;j++,m++)
			{
				if(haystack[m]!=needle[j])
					break;
			}
			if(j==length2 && m==i+length2)
				return i;
		}
	}
	return -1;
}

/*最长公共前缀*/
char *longestCommonPrefix(char ** strs, int strsSize)
{
	int length = strlen(strs[0]);

	//char *str = strs[0];//利用第一个来判断

	//char *str = (char *)malloc(sizeof(char)*length);//利用第一个来判断   这里str一定要自己分配，否则改变不了str里的值，因为是在静态区分配的
	char str[5000];
	int m =0;
	for(m =0;m<length;m++)
		str[m]=strs[0][m];
	str[m]='\0';
	int i,j;
	if(strsSize == 0) return "";
	for(i = 1; i<strsSize;i++){
		j = 0;
		while(str[j]&&strs[i][j]&&str[j]==strs[i][j])j++;//避免数组溢出并判断下一个元素是否相同
		str[j] ='\0';//字符串结束符只输出前面对应相同的
	}
	return str;
}

/*有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。*/
bool isValid(char * s){
	if( s == NULL )
		return false;
	char *stack = (char *) malloc( sizeof(char) * ( strlen(s)+1 ) );
	int top = 0;
	for( int i=0; s[i]!='\0'; i++)
	{
		if(s[i]=='(' || s[i]=='[' || s[i]=='{') //左括号入栈
			stack[++top] = s[i];
		else if( (s[i]==')'&&stack[top]=='(') || (s[i]==']'&&stack[top]=='[') || (s[i]=='}'&&stack[top]=='{') ) //右括号比对
			top--;
		else    //比对失败
			return false;
	}
	if( stack!= NULL)
	{
		free(stack);
		stack = NULL;
	}
	if( top == 0 )  //字符串结束且栈空
		return true;
	return false;


}