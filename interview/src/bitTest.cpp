#include <stdio.h>
#include <string.h>

/*二进制中1的个数面试题10 剑指offer*/
int countOneInNumber(int num)
{
	int count = 0;
	while(num!=0)
	{
		if((num&1)==1)
			count++;
		num=num>>1;
	}
	return count;
}
/*第一个只出现一次的字符  面试题35 剑指offer 开hash表*/
char findFirstOneChar(char *s)
{
	if(NULL == s)
	{
		return '\0';
	}
	char *pString =s;
	const int length = 256;
	unsigned int hashTable[length];
	for(unsigned int i=0;i<length;i++)
	{
		hashTable[i]=0;
	}
	while(*pString!='\0')
	{
		hashTable[*(pString)]++;
		pString++;
	}
	pString = s;
	while(*pString!='\0')
	{

		if(hashTable[*pString]==1)
			return *pString;
		pString++;
	}
	return '\0';
}
/*替换空格  面试题4 剑指offer*/
void replaceBlank(char *string,int length)
{
	int i = 0;
	int newLength = 0;
	int stringLength = 0;
	int blankNumber = 0;
	while(string[i]!='\0')
	{
		stringLength++;
		if(string[i]==' ')
			blankNumber++;
		++i;
	}
	newLength = stringLength + blankNumber*2;
	if(newLength > length)
		return;
	int newIndex = newLength;
	int indexOfOrignal = stringLength;
	while(indexOfOrignal<=newIndex && indexOfOrignal >= 0)
	{
		if(string[indexOfOrignal]!=' ')
		{
			string[newIndex--] = string[indexOfOrignal];
		}
		else
		{
			string[newIndex--]='0';
			string[newIndex--]='2';
			string[newIndex--]='%';
		}
		indexOfOrignal--;
	}
}

/*数组中只出现一次的数字
一个整型数组里除了连个数字之外，其他数字都出现了两次。请写出程序找出这两个出现一次的数字，
要求时间复杂度是O（n），空间复杂度是O（1）*/
/*两个异或结果肯定不为0，找出第一个为1的位数，根据这个位数来区分两个数组*/
int findFirst1inbit(int num)
{
	int firstBitIndex = 0;
	for(int i=0;i<=32;++i)
	{
		if((num&1) == 1)
			return firstBitIndex;
		else
		{
			num = num>>1;
			firstBitIndex++;
		}
	}
}
void findOnlyOnceNumber(int data[],int length,int *num1,int *num2)
{
	int i=0;
	int allXOR = 0;
	int firstOneIndexInBit = 0;
	for(i=0;i<length;i++)
	{
		allXOR = allXOR^data[i];
	}
	firstOneIndexInBit = findFirst1inbit(allXOR);
	for(i=0;i<length;++i)
	{
		if ((data[i]>>firstOneIndexInBit)&1==1)
			*num1 =(*num1 ^ data[i]);
		else
			*num2 =(*num2 ^ data[i]);
	}
}