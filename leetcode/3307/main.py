from typing import List
from collections import defaultdict

class Solution:
    def subarraySum(self, numbers: List[int], k: int) -> int:
        mp = defaultdict(int)
        s = [0] * (len(numbers) + 2)
        n = len(numbers)
        mp[0] = 1
        ans = 0  
        for i in range(1, n + 1): 
            s[i] = s[i - 1] + numbers[i - 1]
            ans = ans + mp[s[i] - k]
            mp[s[i]] += 1
        return ans

if __name__ == "__main__":
    sol = Solution()
    print(sol.subarraySum([1, 2, 3], 3))
    