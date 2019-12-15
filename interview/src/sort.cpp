#include<stdio.h>
#include<malloc.h>

#include "sort.h"


/*数组两元素交换*/
void swap(int *a,int low,int high)
{
	int temp = a[low];
	a[low]=a[high];
	a[high]=temp;
}

/*冒泡排序O(n2)*/
void bubleAsceningSort(int *array,int length)     
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

/*简单选择插入，循环一遍找出值最小的索引，然后与前面的值交换O(n2)*/
void simpleSelectSort(int *array,int length) 
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

/*扑克牌的插入方式，前面的都是有序的O(n2)*/
void directInsertSort(int *array,int length) 
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

/*希尔排序，将其分解成几个小子序列，每个子序列插入排序，O(n*logn)*/
void shellSort(int *array,int length)   
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

/*快排*/
int partition(int *a, int low, int high)
{
	int pivot = a[low];
	while(low < high)
	{
		while((low<high)&&(a[high]>=pivot))
			high--;
		swap(a,low,high);
		while((low<high)&&(a[low]<pivot))
			low++;
		swap(a,low,high);
	}
	return low;
}

void quickSort(int *a ,int low,int high)
{
	int pivot;
	if (NULL == a || 0 >= (high-low))
	{
		printf("number is null!\n");
		return;
	}

	pivot = partition(a,low,high);
	quickSort(a,low,pivot-1);
	quickSort(a,pivot+1,high); 
}

/*归并*/
void merge(int *a,int low, int half, int high)
{
	int i = low;
	int j = half+1;
	int m = 0;
	int n = 0;
	int *temp = (int *)malloc((high - low + 1)*sizeof(int));
	if (NULL == temp)
		return;
	while (i <= half && j <= high)
	{
		if (a[i] <= a[j])
			temp[m++] = a[i++];
		else
			temp[m++] = a[j++];
	}
	while (i<=half)
		temp[m++] = a[i++];
	while (j<=high)
		temp[m++] = a[j++];
	while (n < high - low + 1)
	{
		a[low + n] = temp[n];
		n++;
	}
	free(temp);
	return;
}

void mergeSort(int *a, int low, int high)
{
	int half;
	if (NULL == a || 0 >= (high - low))
		return;
	half = (high + low) / 2;
	mergeSort(a, 0, half);
	mergeSort(a, half + 1, high);
	merge(a, 0, half, high);
	return;
}

/*堆排 大顶堆*/
void headAdjust(int *a, int from, int end)
{
	int i;
	int temp = a[from];
	for (i = 2 * from + 1; i <= end; i = i * 2 + 1)
	{
		if (i<end && a[i]<a[i + 1])
			i++;
		if (temp >= a[i])
			break;
		a[from] = a[i];
		from = i;
	}
	a[from] = temp;
}
void heapSort(int *a, int length)
{
	int i;
	if (NULL == a || 0>length)
		return;
	for (i = length / 2; i >= 0; i--) 
		headAdjust(a, i, length - 1);
	for (i = length - 1; i >= 0; i--)
	{
		swap(a, 0, i);
		headAdjust(a, 0, i - 1);
	}

}