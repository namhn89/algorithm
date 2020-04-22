from typing import List 

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        a = 0 
        b = list()
        for c in nums:
            if c != 0:
                b.append(c)
            else: 
                a += 1 
        b = b + [0] * a
        return b 

if __name__ == "__main__":
    sol = Solution()
    print(sol.moveZeroes([1, 0, 2, 0, 3]))
            