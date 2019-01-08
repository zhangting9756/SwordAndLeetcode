#include<stdio.h>
#include<stdlib.h>
void printArray(int *array,int length);
void bubleAsceningSort(int *array,int length);
void simpleSelectSort(int *array,int length);
void directInsertSort(int *array,int length);
void shellSort(int *array,int length);
void HeapAdjust(int H[],int start,int end);
void HeapSort(int H[],int length);
void merge(int a[], int start, int mid, int end);
void merge_groups(int a[], int len, int gap);
void merge_sort_down2up(int a[], int len);
void quickSort(int a[],int length);
void QSort(int a[],int low,int high);
int partition (int a[],int low,int high);
int main()
{
	int a[10]={10,5,0,7,4,9,8,32,2,6};
	quickSort(a,10);
	printArray(a,10);

}
void swap(int *a,int *b)   //该函数用于交换两个变量的值
{
	int temp=*a;
	*a=*b;
	*b=temp;
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

void HeapAdjust(int  A[], int i, int N)					  /*堆排序，完全二叉树的性质，O(n*logn)*/
{
	int child;
	int Tmp;

	for (Tmp = A[i]; 2*i+1 < N; i = child){
		child = 2*i+1; //注意数组下标是从0开始的，所以左孩子的求发不是2*i
		if (child != N - 1 && A[child + 1] > A[child])
			++child;                //找到最大的儿子节点
		if (Tmp < A[child])
			A[i] = A[child];
		else
			break;
	}
	A[i] = Tmp;
}
void HeapSort(int A[], int N)                              /*堆排序，完全二叉树的性质，O(n*logn)*/
{
	int i;
	for (i = N / 2; i >= 0; --i)
		HeapAdjust(A, i, N);    //构造堆
	for(i=N-1;i>0;--i)
	{
		swap(&A[0],&A[i]);        //将最大元素（根）与数组末尾元素交换，从而删除最大元素，重新构造堆
		HeapAdjust(A, 0, i);
	}
}

void merge(int a[], int start, int mid, int end)
{
	int *tmp = (int *)malloc((end-start+1)*sizeof(int));    // tmp是汇总2个有序区的临时区域
	int i = start;            // 第1个有序区的索引
	int j = mid + 1;        // 第2个有序区的索引
	int k = 0;                // 临时区域的索引

	while(i <= mid && j <= end)
	{
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}

	while(i <= mid)
		tmp[k++] = a[i++];

	while(j <= end)
		tmp[k++] = a[j++];

	// 将排序后的元素，全部都整合到数组a中。
	for (i = 0; i < k; i++)
		a[start + i] = tmp[i];

	free(tmp);
}
void merge_groups(int a[], int len, int gap)
{
	int i;
	int twolen = 2 * gap;    // 两个相邻的子数组的长度
    // 将"每2个相邻的子数组" 进行合并排序。
	for(i = 0; i+2*gap-1 < len; i+=(2*gap))
	{
		merge(a, i, i+gap-1, i+2*gap-1);
	}

	 // 若 i+gap-1 < len-1，则剩余一个子数组没有配对。
	  // 将该子数组合并到已排序的数组中。
	if ( i+gap-1 < len-1)
	{
		merge(a, i, i + gap - 1, len - 1);
    }
}

void merge_sort_down2up(int a[], int len)
{
	int n;
	if (a==NULL || len<=0)
		return ;
	for(n = 1; n < len; n*=2)
      merge_groups(a, len, n);
 }
void quickSort(int a[],int length)        //快速排序O(n*logn)
{
	if (a ==NULL || length<=0)
		return;
	QSort(a,0,length-1);
}
void QSort(int a[],int low,int high)
{
	int pivot;
	if (a==NULL || high<=0)
		return ;
	if(low < high)
	{
		pivot = partition(a,low,high);

		QSort(a,low,pivot-1);
		QSort(a,pivot+1,high);
	}
}
int partition (int a[],int low,int high)
{
	int pivotkey;
	pivotkey = a[low];
	while(low<high)
	{
		while(low<high&&a[high]>=pivotkey)
			high--;
		swap(&a[low],&a[high]);
		while(low<high&&a[low]<=pivotkey)
			low++;
		swap(&a[low],&a[high]);
	}
	return low;
}
