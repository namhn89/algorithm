from typing import List 

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n, m = len(text1), len(text2)
        k = max(n, m)
        f = [[0] * (k + 1) for i in range(0, k + 1)]
        for i in range(1, n + 1):
            for j in range (1, m + 1):
                if text1[i - 1] == text2[j - 1]:
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1)
                f[i][j] = max(f[i][j - 1], f[i][j])
                f[i][j] = max(f[i - 1][j], f[i][j])
        return f[n][m]


if __name__ == "__main__":
    sol = Solution()
    print(sol.longestCommonSubsequence("abcde", "ace"))