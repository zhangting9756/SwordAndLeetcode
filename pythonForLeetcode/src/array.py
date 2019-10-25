# -*- coding: UTF-8 -*-
import numpy as np
"""买卖股票的最佳时机 II"""        
class Solution1(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        maxProfit = 0
        if(prices):
            for i in range(len(prices)-1):
                if(prices[i+1]>prices[i]):
                    maxProfit += prices[i+1]-prices[i]
            return maxProfit
        else:
            return 0
"""从排序数组中删除重复项 """
class Solution2(object):
    def removeDuplicates(self,nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if(nums):
            count =1
            temp = nums[0]
            for i in range(len(nums)):
                if(temp != nums[i]):
                    nums[count]=nums[i]
                    temp = nums[i]
                    count = count +1
            return count
        else:
            return 0
class Solution3:
    def rotate(self, nums, k):
        """
        Do not return anything, modify nums in-place instead.
        """
        if nums:
            k = k % len(nums)
            nums[:]=nums[-k:]+nums[:-k]
""" 存在重复"""
class Solution4:
    def containsDuplicate(self, nums):
        a = len(nums)
        b = len(set(nums))
        if (a!=b):
            return True
        else:
            return False
        
"""只出现一次的数字 """
class Solution5:
    def singleNumber(self, nums): 
        res = 0
        for i in nums:
            res^=i
        return res
"""   两个数组的交集 II"""    
class Solution6:
    def intersect(self, nums1, nums2): 
        if (nums1):
            if(nums2):
                ret =[]
                ret = [ i for i in nums1 if i in nums2 ]
        return ret                 
           
if __name__ == '__main__':
    a=[1,3,2,4,5,3]
    b=[2,3,7,8,3]
    c=Solution6()
    d=c.intersect(a,b)
    print(d)
    
    
 