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
if __name__ == '__main__':
    a=[1,1,2]
    t=Solution()
    print(t.removeDuplicates(a))   
    print(a)    #a已经改变[1, 2, 2]