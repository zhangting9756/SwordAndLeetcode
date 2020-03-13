#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sort.h"
#include "array.h"

/*最小的K个数，采用快排的思想*/
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
/*最小的K个数，采用堆排的思想*/
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

/*寻找和为定值的两个数
输入一个数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字。
*/
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
/*寻找和为定值的多个数*/
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
/*青蛙跳台阶*/
int faBonacci(int num)
{
	if(num <= 0)
		return 0;
	if(num == 1)
		return 1;
	if(num == 2)
		return 2;
	else
	{
		return faBonacci(num-1)+faBonacci(num-2);
	}
}

int faBonacci1(int num)
{
	int minNum=1;   //一个台阶时的方法数
	int maxNum=2;   //两个台阶的方法数
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
/*调整数组顺序使奇数位于偶数前面，剑指offer 面试题14*/
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
/*红白蓝球，现有n个红白蓝三种不同颜色的小球，乱序排列在一起，请通过两两交换任意两个球，使得从左至右，依次是一些红球、一些白球、一些蓝球。
*/
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


/*二维数组中查找，有序数组*/
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
/*数组中连乘最大的，可能有负号*/
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
/*数组连续和最大的*/
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
/*打家劫舍，动态规划*/
int rob(int* nums, int numsSize){
	if(numsSize == 0)
		return 0;
	if(numsSize == 1)
		return nums[0];
	if(numsSize == 2)
		return MAX(nums[0],nums[1]);
	int *maxvalue = (int *)malloc(sizeof(int)*numsSize);
	maxvalue[0]=nums[0];
	maxvalue[1]=MAX(nums[0],nums[1]);
	int i = 0;
	int value1 = 0;
	int value2 = 0;
	for(i=2;i<numsSize;i++)
	{
		value1 = nums[i] + maxvalue[i - 2];
		value2 = maxvalue[i - 1];
		maxvalue[i] = MAX(value1, value2);
	}
	return maxvalue[numsSize-1];
}

/*数字在排序数组中出现的次数 面试题38*/
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

/*找出数组中长度超过数组长度一半的数字，代码不对，再修改
*/
int moreThanHalfNumber(int *array,int length)
{
	int count = 1;
	int number = array[0];
	int i = 0;
	for(i=1;i<length;i++)
	{
		if(count ==0)
		{
			number=array[i];
			count = 1;
		}
		else if(array[i]==number)
		{
			count++;
		}
		else
			count--;
	}
	if(count>0)
		return number;
	else
		return 0;
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
/*买卖股票的最佳时机 II可以交易多次*/
int maxProfit(int* prices, int pricesSize)
{
	if(prices == NULL || pricesSize <=0)
		return 0;
	int i =0;
	int maxProfit = 0;
	for(i = 1;i<pricesSize;i++)
	{
		if(prices[i]>prices[i-1])
			maxProfit += prices[i]-prices[i-1];
	}
	return maxProfit;
}

/*买卖股票的最佳时机 动态规划只允许交易一次*/
int maxProfit2(int* prices, int pricesSize){
	if(prices == NULL || pricesSize <=0)
		return 0;
	int i =0;
	int maxProfit = 0;
	int cur = prices[0];
	for(i = 1;i<pricesSize;i++)
	{
		if(prices[i]<cur)
			cur = prices[i];
		else{
			int tmp = prices[i]-cur;
			if(tmp>maxProfit)
				maxProfit = tmp;
		}

	}
	return maxProfit;

}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	if(nums == NULL || numsSize <=0)
		return NULL;
	int front = 0;
	int end   = numsSize - 1;
	while(front<end)
	{
		if(nums[front]+nums[end] == target)
		{	
			returnSize[0]=front;
			returnSize[1]=end;
			break;
		}
		if(nums[front]+nums[end]>target)
			end--;
		else
			front++;
	}
	return returnSize;
}

/*给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。*/
void reserveArray(int*nums,int begin,int end)
{
	int temp =0;
	int temp_end = end;
	for(int i=begin;i<=(begin+end)/2;i++)
	{
		temp = nums[i];
		nums[i]=nums[temp_end];
		nums[temp_end] = temp;
		temp_end--;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	if(nums == NULL || numsSize==0 || k == 0)
		return;
	reserveArray(nums,0,numsSize-k-1);
	reserveArray(nums,numsSize-k,numsSize-1);
	reserveArray(nums,0,numsSize-1);

}
/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素*/
int singleNumber(int* nums, int numsSize)
{
	if(nums==NULL || numsSize<=0)
		return 0;
	int num = nums[0];
	for(int i=1;i<numsSize;i++)
	{
		num =num^nums[i];
	}
	return num;
}

/*给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。*/
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	if(digits == NULL || digitsSize == 0)
		return NULL;
	int carry=1;
	int i = digitsSize-1;
	while(i>=0)
	{
		digits[i]=digits[i]+1;
		if(digits[i]>9)
		{
			digits[i]=digits[i]-10;
			carry = 1;
		}
		else
		{
			carry = 0;
			break;
		}
		i--;
	}
	if(carry==1)
	{
		returnSize[0]=1;
		for(i=0;i<digitsSize;i++)
		{
			returnSize[i+1]=digits[i];
		}
	}
	else
	{
		for(i=0;i<digitsSize;i++)
		{
			returnSize[i]=digits[i];
		}
	}
	return returnSize;
}

int * plusOne1(int *digits,int length) 
{
	int len = length - 1; 
	for(;len>0 && digits[len]==9  ;--len)
	{
		digits[len]=0;
	}
	if (len == 0 && digits[0] == 9) 
	{
		digits[0] = 0;
	}
	else 
	{
		++digits[len];
	}
	return digits;
}
/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。*/
void moveZeroes(int* nums, int numsSize)
{
	int begin=0;
	int net = begin+1;
	while(begin<numsSize)
	{
		if(nums[begin]==0)
		{
			while((nums[net]==0)&&(net<numsSize))
			{
				net++;
			}
			if((net==numsSize-1)&&(nums[net]==0))
			{
				break;
			}
			else
			{
				swap(nums,begin,net);
				begin++;
				net++;
			}
		}
		else
			begin++;
	}
}

/*丑数*/
bool isAugly(int num)
{
	while(num%2==0)
		num=num/2;
	while(num%3==0)
		num=num/3;
	while(num%5==0)
		num=num/5;
	if(num==1)
		return true;
	else
		return false;
}
/*简单粗暴方法寻找第index个丑数*/
int getAuglyNum(int index)
{
	int count=0;
	int number=0;
	while(count<index)
	{
		number++;
		if(isAugly(number))
			count++;
	}
	return number;
}
int minNum(int a,int b,int c)
{
	int min = (a<b)?a:b;
	min = (min<c)?min:c;
	return min;
}
/*保存丑数方法*/
int getAuglyNum1(int index)
{
	int *uglyNumbers = (int *)malloc(sizeof(int)*index);
	uglyNumbers[0]=1;
	int m2 =0;
	int m3 =0;
	int m5 =0;
	int m  =1;
	while(m<index)
	{
		uglyNumbers[m]=minNum(uglyNumbers[m2]*2,uglyNumbers[m3]*3,uglyNumbers[m5]*5);
		while(uglyNumbers[m2]*2<=uglyNumbers[m])
			m2++;
		while(uglyNumbers[m3]*3<=uglyNumbers[m])
			m3++;
		while(uglyNumbers[m5]*5<=uglyNumbers[m])
			m5++;
		m++;
	}
	return uglyNumbers[index-1];

}
/*合并两个有序数组
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i=m-1;
	int j=n-1;
	int k=m+n-1;
	if (k<nums1Size-1)
		return;
	while(i>=0&&j>=0&&m>=0)
	{
		if(nums1[i]>nums2[j])
		{
			nums1[k]=nums1[i];
			i--;
		}
		else
		{
			nums1[k]=nums2[j];
			j--;
		}
		k--;
		if(i<0||j<0)
			break;
	}
	if(i<0&&k>=0)
	{
		for(;j>=0&&k>=0;j--)
		{
			nums1[k]=nums2[j];
			k--;
		}
	}
	if(j<0&&k>=0)
	{
		for(;i>=0&&m>=0;i--)
		{
			nums1[k]=nums1[i];
			k--;
		}
	}

}
/*数组中的逆序对*/
int InversePairsCore(int *data,int *copy,int start,int end)
{
	if(start == end)
	{
		copy[start]=data[end];
		return 0;
	}
	int half = (end-start)/2;
	int left = InversePairsCore(copy,data,start,start+half);
	int right = InversePairsCore(copy,data,start+half+1,end);

	int i = start+half;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while(i>=start && j>=start+half+1)
	{
		if(data[i]>data[j])
		{
			copy[indexCopy--]=data[i--];
			count += j-start-half;
		}
		else
		{
			copy[indexCopy--]=data[j--];
		}
	}
	for(;i>=start;i--)
	{
		copy[indexCopy--]=data[i];
	}
	for(;j>=start+half+1;j--)
	{
		copy[indexCopy--]=data[j];
	}
	return left+right+count;
}

int inversePairs(int *data,int length)
{
	if(data == NULL || length<0)
		return 0;
	int *copy = new int[length];
	for(int i=0;i<length;i++)
	{
		copy[i]=data[i];
	}
	int count = InversePairsCore(data,copy,0,length-1);
	delete[] copy;
	return count;
}

/*汉明距离
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目*/
int hammingDistance(int x, int y){
	int count = 0;
	int a = x^y;
	while(a!=0)
	{
		if((a&1)==1)
			count++;
		a=a>>1;
	}
	return count;
}
/*颠倒二进制位数*/
unsigned reverseBits(unsigned int n) {
	unsigned int m = 0;
	int t = 0;
	while(t<32)
	{	
		m |= (n&0x1);
	    if(t<31)
			m <<= 1;

		n = n >> 1;
	    t++;
	}
	return m;

}

/*缺失数字*/
int missingNumber(int* nums, int numsSize){

	int i =0;
	int sum = 0;
	for(i=0;i<numsSize;i++)
	{
		sum += (i+1-nums[i]);
	}
	return sum;
}

/*统计质数*/
bool isPrimes(int m)
{
	int i=2;
	int s = int(sqrt(double (m)));
	while(i<=s)
	{
		if(m%i==0)
			return false;
		i++;
	}
	return true;
}
int countPrimes(int n){
	if (n<=1)
		return 0;
	if(n==2)
		return 0;
	int count = 1;
	int i = 3;
	while(i<n)
	{
		if(isPrimes(i))
			count++;
		i++;
	}
	return count;
}
/*统计质数1*/
int countPrimes1(int n){
	if (n<=1)
		return 0;
	if(n==2)
		return 0;
	int* flag = (int *)malloc(n*sizeof(int));
	for(int i = 0;i<n+1;i++)
		flag[i]=true;
	int count = 0;
	for(int i =2;i<n;i++)
	{
		if(flag[i])
		{
			for(int j = i+i;j<n;j+=i)
				flag[j]=false;
			count++;
		}
	}
	return count;
}
/*判断是否为3的幂*/
bool isPowerOf3_1(int m)
{
	if (m == 1) 
		return true;
	while (m > 3 && m % 3 == 0) 
	{
		m = m / 3;
	}
	return m == 3;
}

bool isPowerOf3_2(int m)
{
	if (m == 1) 
		return true;
	if (m >= 3 && m % 3 == 0) 
		return isPowerOf3_2(m / 3);
	return false;
}

bool isPowerOf3_3(int m)
{
	return m > 0 && 1162261467 % m == 0;
}

/*将数组分成和相等的三个部分
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。
*/
bool  canThreePartsEqualSum(int* A, int ASize)
{
	if (A == NULL || ASize == 0)
		return false;
	int i = 1, j = ASize-2, sum = 0;
	int presum = A[0], latersum = A[ASize-1];
	for (i = 0; i < ASize; i++)
		sum += A[i];
	if (sum % 3 != 0)
		return false;
	int avg = sum / 3;
	/*
	for (i = 1; i < ASize; i++)
	{
		if (presum == avg)
			break;
		else
			presum += A[i];
	}
	if (i > ASize-2)
		return false;
	for (j = ASize - 2; j>=i; j--)
	{
		if (latersum == avg)
			break;
		else
			latersum += A[j];
	}
	if (j < i)
		return false;
	else
		return true;*/
	i = 1;
	while (i < j)
	{
		if (presum!=avg)
			presum += A[i++];
		if (latersum != avg)
			latersum += A[j--];
		if (presum == avg && latersum == avg && j>=i)
			return true;
	}
	return false;
}
/* 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/
int majorityElement(int* nums, int numsSize)
{
	int count = 1;
	int number = nums[0];
	int i = 0;
	for(i=1;i<numsSize;i++)
	{
		if(count ==0)
		{
			number=nums[i];
			count = 1;
		}
		else if(nums[i]==number)
		{
			count++;
		}
		else
			count--;
	}
	if(count>0)
		return number;
	else
		return 0;
}
