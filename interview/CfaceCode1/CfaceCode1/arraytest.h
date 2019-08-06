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
#endif