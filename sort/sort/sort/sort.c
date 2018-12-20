#include<stdio.h>
void printArray(int *array,int length);
void bubleAsceningSort(int *array,int length);
void simpleSelectSort(int *array,int length);
void directInsertSort(int *array,int length);
void shellSort(int *array,int length);
int main()
{
	int a[10]={1,5,0,7,4,9,8,3,2,6};
	shellSort(a,10);
	printArray(a,10);

}
void printArray(int *array,int length)
{
	int i;
	if((array == NULL)||(length == 0))
	{
		printf("the array is NULL!\n");
		return ;
	}
	for(i=0;i<length;i++)
	{
		printf("array[%d]=%d\n",i,array[i]);
	}
}

void bubleAsceningSort(int *array,int length)     //冒泡排序O(n2)
{
	int i,j;
	int temp;
	if((array == NULL)||(length == 0))
	{
		printf("the array is NULL!\n");
		return ;
	}
	for(i=0;i<length-1;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(array[i]>array[j])
			{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
			}
		}
	}
}

void simpleSelectSort(int *array,int length)  /*简单选择插入，循环一遍找出值最小的索引，然后与前面的值交换O(n2)*/
{
	int tempIndex,temp;
	int i,j;
	if((array == NULL)||(length == 0))
	{
		printf("the array is NULL!\n");
		return;
	}
	for(i=0;i<length;i++)
	{
		tempIndex = i;
		for(j=i+1;j<length;j++)
		{
			if(array[tempIndex]>array[j])
				tempIndex = j;
		}
		if(i!=tempIndex)
		{
			temp = array[i];
			array[i] = array[tempIndex];
			array[tempIndex] = temp;
		}
	}
}

void directInsertSort(int *array,int length)     /*扑克牌的插入方式，前面的都是有序的O(n2)*/
{
	int i,j,temp;
	if((array == NULL)||(length == 0))
	{
		printf("the array is NULL!\n");
		return;
	}
	for(i = 1;i<length;i++)
	{
		if(array[i-1]>array[i])
		{
			temp = array[i];
			for(j=i-1;array[j]>temp;j--)
			{
				array[j+1] = array[j];
			}
			array[j+1]=temp;
		}
	}
}

void shellSort(int *array,int length)        /*希尔排序，将其分解成几个小子序列，每个子序列插入排序，O(n*logn)*/
{
	int i,j,temp;
	int increment = length;
	do 
	{
		increment = increment/3+1;
		for(i=increment+1;i<length;i++)
		{
			temp=array[i];
			for(j=i-increment;j>=0&&array[j]>temp;j-=increment)
			{
				array[j+increment]=array[j];
			}
			array[j+increment] = temp;
		}
	} while (increment>1);
}
