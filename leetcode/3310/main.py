from typing import List

class Solution:
    def canJump(self, numbers: List[int]) -> bool:
        if not numbers: 
            return False

        ans = 0 
        for i, step in enumerate(numbers[:-1]):
            if ans >= i:
                ans = max(ans, i + step)
            if ans >= len(numbers) - 1:
                return True
        return len(numbers) == 1 

if __name__ == "__main__":
    sol = Solution()
    print(sol.canJump([3,2,1,0,4]))      