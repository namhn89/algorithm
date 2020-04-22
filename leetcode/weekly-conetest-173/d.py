from typing import List
INT_MAX = 1e9 + 7 

class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if len(jobDifficulty) < d:
            return -1 
        dp = [[float('inf')] * (d + 1) for i in range(n + 1)]
        for i in range(n + 1)
            for  
             