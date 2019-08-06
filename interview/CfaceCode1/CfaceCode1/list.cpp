#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include "list.h"
#include "quickSort.h"


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
/*
int moreThanHalfNum(int *array,int length)
{
	if(NULL == array)
	{
		printf("the array is null!\n");
		return 0;
	}
	int middle = length/2;
	int start = 0;
	int end = length-1;
	int index = 0;
	while(index!=middle)
	{
		index = partition(array,start,end);
		if(index>middle)
			end = index -1;
		else
			start = index + 1;
	}
	return array[middle];
}
*/
int moreThanHalfNumber1(int *array,int length)
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