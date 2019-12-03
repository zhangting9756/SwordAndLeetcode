#ifndef __QUICK_SORT_TEST__
#define __QUICK_SORT_TEST__
/*冒泡*/;
void bubleAsceningSort(int *array,int length);
//简单选择，跟冒泡差不多，但是交换次数少
void simpleSelectSort(int *array,int length);
//直接插入
void directInsertSort(int *array,int length);
//希尔排序
void shellSort(int *array,int length);
//快排
void quickSort(int *a ,int low,int high);
void swap(int *a,int low,int high);
int partition(int *a, int low, int high);
//归并
void merge(int *a,int low, int half, int high);
void mergeSort(int *a, int low, int high);

//堆排
void heapSort(int *a, int length);
void headAdjust(int *a, int from, int end);
#endif