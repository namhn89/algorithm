import math
from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        f = nums[0]
        n = len(nums)
        ans = f
        for i in range(1, n):
            f = max(nums[i], f + nums[i])
            ans = max(ans, f)
        return ans

if __name__ == "__main__":
    sol = Solution()
    print(sol.maxSubArray([1]))