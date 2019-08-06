#include<stdio.h>
#include<malloc.h>

#include "quickSort.h"

/*øÏ≈≈*/

void swap(int *a,int low,int high)
{
	int temp = a[low];
	a[low]=a[high];
	a[high]=temp;
}

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

/*πÈ≤¢*/
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

/*∂—≈≈*/

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