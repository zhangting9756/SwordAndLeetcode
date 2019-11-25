#ifndef __QUICK_SORT_TEST__
#define __QUICK_SORT_TEST__

void quickSort(int *a ,int low,int high);
void swap(int *a,int low,int high);
int partition(int *a, int low, int high);
//πÈ≤¢
void merge(int *a,int low, int half, int high);
void mergeSort(int *a, int low, int high);

//∂—≈≈
void heapSort(int *a, int length);
void headAdjust(int *a, int from, int end);
#endif