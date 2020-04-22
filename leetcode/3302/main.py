import sys
from typing import List 
from collections import deque
import queue

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        direction = [(-1, 0), (1, 0), (0, -1), (0, 1)] 
        vis = set() 
        m = len(grid)
        if m == 0: 
            return 0 
        n = len(grid[0])
        ans = 0 
        for i in range(0, len(grid)): 
            for j in range(0, len(grid[i])): 
                if grid[i][j] == "1" and (i, j) not in vis :
                    q = queue.Queue()
                    q.put((i, j))
                    vis.add((i, j))
                    while not q.empty():
                        (u, v) = q.get()
                        # print(u, v)
                        for (x, y) in direction:
                            du = x + u 
                            dv = y + v 
                            if du < 0 or du >= m or dv < 0 or dv >= n or (du, dv) in vis: 
                                continue 
                            if grid[du][dv] == "1" :
                                # print("BFS : ")
                                # print(du, dv)
                                q.put((du, dv))
                                vis.add((du, dv))
                    ans += 1

        return ans  

if __name__ == "__main__":
    sol = Solution()
    print(sol.numIslands([["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]))