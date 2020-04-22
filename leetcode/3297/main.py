from typing import List 

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        ans = 0
        while len(stones) > 0:
            if len(stones) == 1:
                ans += stones[0]
                break
            else:
                stones.sort()
                # print(stones)
                y = stones[len(stones) - 1]
                x = stones[len(stones) - 2]
                stones.pop()
                stones.pop()
                if y == x: 
                    continue
                else:
                    k = y - x 
                    stones.append(k)
        
        return ans
                
if __name__ == "__main__":
    sol = Solution()
    print(sol.lastStoneWeight([2, 7, 4, 1, 8, 1]))