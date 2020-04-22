MOD = 10**9 + 7
from typing import List 
def solve(self, amount: int, coins: List[int]) -> int:
    dp = [0] * (amount + 1)
    dp[0] = 1
    for c in coins:
        for a in range(1, amount + 1):
            if a - c >= 0:
                dp[a] += dp[a - c]
                dp[a] %= MOD

    return dp[-1]

def countWaySum(n, a, b):
    c = list()
    c.append(a)
    c.append(b) 
    return solve(n, c)