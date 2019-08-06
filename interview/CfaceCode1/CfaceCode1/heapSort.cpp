#include<stdio.h>
#include"quickSortTest.h"

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
void makeTopK(int *source,int *dest,int K,int n)
{
	int i = 0;
	int temp = 0;
	for(i=0;i<K,i++)
	{
		dest[i++] = source[i++];
	}
	headAdjust(dest,0,K-1);
	for(i=K-1;i<n,i++)
	{
		temp = source[K];
		if(temp>dest[0])
		{
			dest[0]=temp;
			headAdjust(dest,0,K-1);
		}
	}
}
