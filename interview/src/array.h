#ifndef __ARRAY_TEST__
#define __ARRAY_TEST__
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))  //宏定义，注意加括号
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
/*最小的k个数，消耗内存，快排法*/
void getLeastNumber(int *input, int *output, int length,int k);
/*最小的k个数，不消耗内存，堆排*/
void getLeastNumbers(int *input, int *output, int length,int k);
/*和为定值的两个数*/
bool findNumberWithSum(int *array,int *num1,int *num2,int length,int sum);
/*和为定值的多个数*/
void printContinueSequence(int start,int end);
void findContunieSequence(int num);
/*斐波那契数列数列的递归实现，跳台阶问题*/
int faBonacci(int num);
/*斐波那契数列数列的非递归实现，跳台阶问题*/
int faBonacci1(int num);
/*奇数在偶数前面两个指针思想*/
void reOderOddEven(int *array,int length);
/*红白蓝球问题，三个指针思想*/
void sortRedWhiteBlue(int *array,int length);
/*二维排序数组中的查找*/
bool findNumberInArray(int *array,int width,int high,int num);
/*连续子数组的最大积*/
double findMaxProduct(double *array,int length);
/*连续子数组的最大和*/
double findMaxSum(double *array,int length);
/*数组中K的个数*/
int getNumberOfK(int *array,int length,int k);
/*给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。*/
int removeDuplicates(int* nums, int numsSize);
/*买卖股票的最佳时机 II*/
int maxProfit(int* prices, int pricesSize);
/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
/*给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。*/
void rotate(int* nums, int numsSize, int k);
/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素*/
int singleNumber(int* nums, int numsSize);
/*给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。*/
int* plusOne(int* digits, int digitsSize, int* returnSize);
int * plusOne1(int *digits,int length) ;
/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。*/
void moveZeroes(int* nums, int numsSize);
#endif