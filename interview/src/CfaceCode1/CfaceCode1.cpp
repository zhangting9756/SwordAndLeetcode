// CfaceCode1.cpp : �������̨Ӧ�ó������ڵ㡣
//
/***************************
*ͷ�ļ�
****************************/
#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include  <malloc.h>


#include "array.h"
#include "charString.h"

/***************************
*ȫ�ֱ���
****************************/
int b_g[6]={0,0,3,4,0,7};


void exchange(int *a,int low,int high)
{
	int temp = a[low];
	a[low]=a[high];
	a[high]=temp;
}

void heapAdjust(int *a, int from, int end)
{
	int i;
	int temp = a[from];
	for (i = 2 * from + 1; i <= end; i = i * 2 + 1)
	{
		if (i<end && a[i]>a[i + 1])
			i++;
		if (temp <= a[i])
			break;
		a[from] = a[i];
		from = i;
	}
	a[from] = temp;
}


void makeTopK(int *source,int *dest,int K,int n)
{
	int i = 0;
	int temp = 0;
	for(i=0;i<K;i++)
	{
		dest[i] = source[i];
	}
	heapAdjust(dest,0,K-1);

	for(i=K-1;i<n;i++)
	{
		temp = source[i];
		if(temp>dest[0])
		{
			dest[0]=temp;
			heapAdjust(dest,0,K-1);
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int length = 0;
	int a[5]={1, 1, 1, 4,5};
	int b[6] = {0};
	char c[] = "I am a student.";
	reserveString(c);
	system("pause");
	return 0;
}
