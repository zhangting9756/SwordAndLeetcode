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
	int length = 5;
	//int a = -123;
	int nums1[6]= {4,5,6,0,0,0};
	int nums2[3]= {1,2,3};
	int m=-1;
	//int b[6] = {0};
	char c[] = {"ABCD"};
	char b[]= {"BAD"};
	//length = reverse(a);
	merge(nums1, 6, 3, nums2, 3, 3);
	system("pause");
	return 0;
}

