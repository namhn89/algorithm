from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0:
            return 0
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * (n + 1) for i in range(m + 1)]
        max_len = 0 
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if matrix[i - 1][j - 1] == '1':
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1
                    max_len = max(max_len, dp[i][j]) 

        return max_len * max_len
        

if __name__ == "__main__":
    sol = Solution()
    print(sol.maximalSquare([["1", "1"], ["1", "1"]]))