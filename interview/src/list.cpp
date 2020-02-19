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
		if(headList->next != NULL)
		{
			reserveList(headList->next);
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
	pNode->next=NULL;
	headList = pNode;
	p = pNode;
	for(i=0;i<5;++i)
	{
		pNode = (pList)malloc(sizeof(Node));
		pNode->data = i;
		pNode->next = NULL;
		p->next = pNode;
		p = pNode;
	}
	return headList;
}
/*给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	pList p =head;
	int size = 0;
	while(p!=NULL)
	{
		size++;
		p = p->next;
	}
	if( size == 1)//只有一个结点的情况直接返回null
	{   
		return NULL;
	}

	size = size - n;//倒变正,也即是所要删除的节点前面有几个节点

	if(size == 0)//链表节点数>1,且为删除链表的第一个节点的情况下
	{
		return head->next;
	}
	p = head;
	for(int i = 0;i<size-1;i++)//注意i是从0到size-2的，因为从0到size-1为size个位移量，但是我们是从第一个开始偏移，只需要偏移size-1个位移量，所以边界值为size -1
	{
		p = p->next;
	}
	p->next = p->next->next;
	return head;

}
/*反转链表*/
struct ListNode* reverseList(struct ListNode* head){
	pList pReversedHead = NULL;
	pList pNode = head;
	pList pPrev = NULL;
	while(pNode!=NULL)
	{
		pList pNext = pNode->next;
		if(pNext==NULL)
			pReversedHead = pNode;
		pNode->next = pPrev;
		pPrev=pNode;
		pNode=pNext;
	}
	return pReversedHead;
}
/*合并两个排序的链表*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	pList pHead = (pList)malloc(sizeof(Node));
	pList p = pHead;


	while(l1&&l2)
	{
		if(l1->data <l2->data){
			p->next=l1;
			l1=l1->next;
		}
			
		else{
			p->next =l2;
			l2=l2->next;
		}
		p=p->next;	
	}
	if(l1==NULL)
		p->next=l2;
	if(l2==NULL)
		p->next=l1;
	return pHead->next;
}
/*判断回文链表*/
bool isPalindrome(struct ListNode* head){
	int size = 0;
	struct ListNode* p =head;
	while(p)
	{
		size++;
		p=p->next;
	}
		
	int *a = (int *)malloc(sizeof(int)*size);
	p=head;
	int i = 0;
	for(i=0;i<size;i++)
	{
		a[i]=p->data;
		p=p->next;
	}
	for(i=0;i<size/2;i++)
	{
		if(a[i]!=a[size-i-1])
			return false;
	}
	return true;
}

bool isPalindrome1(struct ListNode* head){
	if(head==NULL) return true;
	struct ListNode *fast,*slow,*p,*q,*temp=NULL;
	fast=slow=head;
	while(fast->next && fast->next->next){     //快慢指针寻找中点
		fast=fast->next->next;
		slow=slow->next;
	}
	slow=slow->next;
	while(slow!=NULL){                      //慢指针翻转后面的链表
		p=slow;
		slow=slow->next;
		p->next=temp;
		temp=p;
	}
	while(temp!=NULL){
		if(temp->data!=head->data){
			return false;
		}
		temp=temp->next;
		head=head->next;
	}
	return true;

}
