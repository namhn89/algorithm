from typing import List

class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        n = len(slices) // 3
        # print(len(slices[1:]), len(slices[: -1]))
        def linear(arr):
            # index = nb slices eaten.
            a = [0] * (n+1)  # Two slices ago.
            b = [0] * (n+1)  # Previous slice.
            for x in arr:
                a, b = b, [i and max(x + a[i-1], b[i]) for i in range(n+1)]
            return b[-1]
        return max(linear(slices[1:]), linear(slices[:-1])) 

if __name__ == "__main__":
    sol = Solution() 
    print(sol.maxSizeSlices([8,9,8,6,1,1])) 
