from collections import defaultdict, deque
from typing import Iterator, List, Tuple
import math
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m = len(grid) 
        n = len(grid[0])
        visited = set()

        def generate (x: int, y: int) -> Iterator[Tuple[int, int, int]]:
            if x + 1 < m : 
                yield x + 1, y, (grid[x][y] != 3) 
            if x > 0 : 
                yield x - 1, y, (grid[x][y] != 4)
            if y + 1 < n: 
                yield x, y + 1, (grid[x][y] != 1) 
            if y > 0:
                yield x, y - 1, (grid[x][y] != 2)

        dist = defaultdict(lambda : math.inf, {(0, 0) : 0}) 
        queue = deque([(0, 0, 0)])
        while queue: 
            cost, x, y = queue.popleft()
            # print(cost, x, y)
            
            if cost != dist[x, y]: 
                continue

            if x == m - 1 and y == n - 1: 
                return cost 

            for next_x, next_y, weight in generate(x, y):
                weight = int(weight) 
                # print(next_x, next_y, weight)
                next_dist = weight + cost
                if next_dist < dist[next_x, next_y]:
                    dist[next_x, next_y] = next_dist
                    if not weight: 
                        queue.appendleft((next_dist, next_x, next_y))
                    else:
                        queue.append((next_dist, next_x, next_y))
        print(dist)   
        
if __name__ == "__main__":
    sol = Solution()
    print(sol.minCost([[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]))
    pass