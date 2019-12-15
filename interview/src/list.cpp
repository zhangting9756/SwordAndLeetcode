#include<stdio.h>
#include<string.h>
#include<malloc.h>


#include "list.h"
#include "sort.h"

/*
ÄæÐòÊä³öÁ´±í
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
