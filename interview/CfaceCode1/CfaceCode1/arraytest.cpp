#include <stdio.h>
#include "quickSort.h"

#include "heapSort.h"
#include "arraytest.h"


void getLeastNumber(int *input, int *output, int length,int k)
{
	int i =0;
	int index =0;
	int start = 0;
	int end = length -1;
	while(index !=k-1)
	{
		index = partition(input,start,end);
		if(index < k-1)
			start = index +1;
		else
			end = index -1;
	}
	for(i = 0;i<k;i++)
	{
		output[i]=input[i];
	}

}

void getLeastNumbers(int *input, int *output, int length,int k)
{
	int i = 0;
	for(i=0;i<k;i++)
	{
		output[i]=input[i];
	}

	heapSort(output, k);
	for(i=k;i<length;i++)
	{
		if(input[i]<output[k-1])
		{
			output[k-1]=input[i];
			heapSort(output,k);
		}
	}
}

bool findNumberWithSum(int *array,int *num1,int *num2,int length,int sum)
{
	int start = 0;
	int end = length -1;
	if (NULL == array || length <=0)
	{
		return false;
	}
	else
	{
		while(start <= end)
		{
			if(array[start]+array[end]==sum)
			{
				*num1 = array[start];
				*num2 = array[end];
				return true;
			}
			else if(array[start]+array[end]<sum)
				start++;
			else
				end--;
		}
	}
	return false;
}
void printContinueSequence(int start,int end)
{
	int i;
	for(i=start;i<=end;++i)
	{
		printf("%3d",i);
	}
	printf("\n");
}
void findContunieSequence(int num)
{
	int start=1;
	int end =2;
	int middle = (num+1)/2;
	int countSum = start+end;
	while(start<middle)
	{
		if(countSum == num)
		{
			printContinueSequence(start,end);
		}
		while(countSum>num && start<middle)
		{

			countSum -= start;
			start++;
			if(countSum == num)
			{
				printContinueSequence(start,end);
			}
		}
		end++;
		countSum +=end;
		
	}

}

int faBonacci(int num)
{
	if(num <= 0)
		return 0;
	if(num == 1)
		return 1;
	else
	{
		return faBonacci(num-1)+faBonacci(num-2);
	}
}

int faBonacci1(int num)
{
	int minNum=0;
	int maxNum=1;
	int fibN=0;
	int i=2;
	if(num ==0)
		return 0;
	if(num ==1)
		return 1;
	else
	{
		for(i=2;i<=num;i++)
		{
			fibN = minNum+maxNum;
			minNum = maxNum;
			maxNum=fibN;
		}
	}
	return fibN;
}
bool oddEven(int num)
{
	if(num%2 == 1)
		return true;
	else
		return false;
}
void reOderOddEven(int *array,int length)
{
	int start=0;
	int end = length-1;
	while(start<=end)
	{
		while(start<=end && oddEven(array[start]))
			start++;
		swap(array,start,end);
		while(start<=end && !(oddEven(array[end])))
			end--;
		swap(array,start,end);
	}
}

void sortRedWhiteBlue(int *array,int length)
{
	int start = 0;
	int current = 0;
	int end = length-1;
	while(current <= end)
	{
		if(array[current]==0)
		{
			swap(array,start,current);
			start++;
			current++;
		}
		else if(array[current]==1)
		{
			current++;
		}
		else
		{
			swap(array,current,end);
			end--;
		}
	}
}



bool findNumberInArray(int *array,int width,int high,int num)
{
	if(NULL == array)
		return false;
	int i = width-1;
	int j =0;
	while(i>=0 && j<high)
	{
		if(array[j*width+i]==num)
			return true;
		else if(array[j*width+i]<num)
			j++;
		else
			i--;
	}
	return false;
}

double findMaxProduct(double *array,int length)//对动态规划问题要找到状态转移方程
{
	if (NULL == array)
		return 0;
	double max = array[0];
	double min = max;
	double maxproduct = min;
	int i=1;
	for(i=1;i<length;++i)
	{
		max = MAX(MAX(max*array[i],min*array[i]),array[i]);
		min = MIN(MIN(max*array[i],min*array[i]),array[i]);
		maxproduct = MAX(max,maxproduct);
	}
	return maxproduct;
}

double findMaxSum(double *array,int length)//对动态规划问题要找到状态转移方程
{
	if (NULL == array)
		return 0;
	double max = array[0];
	double maxSum = array[0];
	int i =1;
	for(i=1;i<length;++i)
	{
		max = MAX(max+array[i],array[i]);
		maxSum=MAX(max,maxSum);
	}
	return maxSum;
}

int getFirstKIndex(int *array,int from,int to,int k)
{
	if(from>to)
		return -1;
	while(from<=to)
	{
		int half = (from+to)/2;
		if(array[half]==k)
		{
			if((half == 0)|| array[half -1]!=k)
				return half;
			else
				to = half -1;
		}
		else if(k<array[half])
		{
			to = half-1;
			
		}
		else
			from = half +1;
	}
	return getFirstKIndex(array,from,to,k);
}

int getLastKIndex(int *array,int from,int to,int k)
{
	if(from>to)
		return -1;
	while(from <= to)
	{
		int half = (from+to)/2;
		if(array[half]==k)
		{
			if((half == to)|| array[half+1]!=k)
				return half;
			else
				from = half+1;
		}
		else if(k<array[half])
		{
			to = half-1;
		}
		else
			from = half +1;
	}
	return getLastKIndex(array,from,to,k);
}

int getNumberOfK(int *array,int length,int k)
{
	if(NULL == array || length<=0)
		return -1;
	int from = 0;
	int end = length -1;
	int kNumber = -1;
	int firstKIndex = getFirstKIndex(array,from,end,k);
	int lastKIndex = getLastKIndex(array,from,end,k);
	if(firstKIndex>-1 && lastKIndex >-1)
	{
		kNumber = lastKIndex - firstKIndex +1;
	}
	return kNumber;
}
/*给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。*/

int removeDuplicates(int* nums, int numsSize)
{
	if((nums==NULL)|| (numsSize<=0))
	{
		return 0;
	}
	int temp = nums[0];
	int i = 0;
	int count = 1;
	for (i=1;i<numsSize;i++)
	{
		if(temp!=nums[i])
		{
			nums[count]=nums[i];
			temp = nums[i];
			count++;
		}
	}
	return count;
}