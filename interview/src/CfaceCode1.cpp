// CfaceCode1.cpp : 定义控制台应用程序的入口点。
//
/***************************
*头文件
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
*全局变量
****************************/
int b_g[5]={3, 8, 2, 4,5};


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int length= 0;
	char *p[] = {"test1","test2"};
	int nums1[8] = { 10, 9, 2, 5, 3, 7, 101, 18 };
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
	length = lengthOfLIS(nums1, 8);
	return 0;
}

