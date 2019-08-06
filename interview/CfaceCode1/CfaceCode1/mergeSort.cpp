#include <stdio.h>
#include<malloc.h>
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