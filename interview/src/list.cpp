#include<stdio.h>
#include<string.h>
#include<malloc.h>


#include "list.h"
#include "sort.h"

/*
逆序输出链表
*/
void reserveList(pList headList)
{
	if(NULL == headList)
	{
		printf("the list is NULL!\n");
	}
	else
	{
		if(headList->Next != NULL)
		{
			reserveList(headList->Next);
			printf("%d\n",headList->data);
		}
		else
		{
			printf("%d\n",headList->data);
		}
	}
}

pList creatList()
{
	int i = 0;
	pList pNode;
	pList p;
	pList headList = NULL;
	pNode = (pList)malloc(sizeof(Node));
	pNode->data = 8;
	pNode->Next=NULL;
	headList = pNode;
	p = pNode;
	for(i=0;i<5;++i)
	{
		pNode = (pList)malloc(sizeof(Node));
		pNode->data = i;
		pNode->Next = NULL;
		p->Next = pNode;
		p = pNode;
	}
	return headList;

}
/*找出数组中长度超过数组长度一半的数字，代码不对，再修改
*/
int moreThanHalfNumber(int *array,int length)
{
	int count = 1;
	int number = array[0];
	int i = 0;
	for(i=1;i<length;i++)
	{
		if(array[i]!=number)
		{
			count=1;
			number = array[i];
		}
		else
			count++;
	}
	if(count>0)
		return number;
	else
		return 0;
}