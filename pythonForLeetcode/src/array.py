# -*- coding: UTF-8 -*-
import numpy as np

class Solution(object):
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
if __name__ == '__main__':
    a=[7,6,4,3,1]
    t=Solution1()
    print(t.maxProfit(a))   
    print(a)    #a已经改变[1, 2, 2]