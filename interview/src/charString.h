/*字符串倒置*/
void reserve(char *s, int from, int end);
/*检查是否是回文*/
int reserveCheck(char *s, int length);
/*将含有空格的字符串倒置*/
void reserveString(char *s);
/*最大回文长度*/
int maxHuiWen(char *s,int length);
/*交换字符串*/
void swapChar(char *s,int low,int high);
/*字符串全排列*/
void calcAllPermutation(char *s,int from,int to);
/*字符串包含*/
bool stringContain(char *a, char *b);
/*对字符串中的所有单词进行倒排。

说明：

1、每个单词是以26个大写或小写英文字母构成；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；*/
void reserveString1(char *s);
/*验证回文字符串,给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。leetcode 字符串*/
bool isPalindrome(char *s);
/*给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。*/
int firstUniqChar(char * s);
/*整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转*/
int reverse(int x);
/*有效的字母异位词,给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。leetcode*/
bool isAnagram(char * s, char * t);
/*字符串转换整数 (atoi)leetcode*/
int myAtoi(char * str);