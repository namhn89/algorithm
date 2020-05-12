from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1) 
        dp[0] = 0
        for i in range(1, amount + 1):
            for c in coins: 
                if i >= c: 
                    dp[i] = min(dp[i], dp[i - c] + 1) 
        
        if dp[amount] == float('inf'):
            return -1
        else:
            return dp[amount]
if __name__ == "__main__":
    sol = Solution()
    print(sol.coinChange([2, 5, 1], 11))