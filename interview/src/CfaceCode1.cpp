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
#include "sort.h"
#include "strToInt.h"
#include "list.h"

/***************************
*ȫ�ֱ���
****************************/
int b_g[5]={3, 8, 2, 4,5};


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int length= 0;
	char *p[] = {"test1","test2"};
	int nums1[8] = { 6, 7, 5, 2, 4, 5, 9, 3 };
	int m=12;
	int n=0;
	while(m)
	{
		m &= (m-1);
		n++;
	}
	//int b[6] = {0};
	char c[] = {"ABCD"};
	char b[]= {"BAD"};
	unsigned int a = 5;
	length = largestRectangleArea(nums1, 8);
	return 0;
}

