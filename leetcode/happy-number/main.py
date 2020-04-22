from collections import defaultdict

class Solution:
    def isHappy(self, n: int) -> bool:
        mp = defaultdict(int)

        def solve(n):
            if n == 1: 
                return 1
            ans = 0 
            while n > 0: 
                ans = ans + (n % 10) ** 2 
                n = n // 10 
            return ans
        
        mp[n] = 1
        while n != 1:
            n = solve(n)
            # print(n)
            if mp[n] == 1:
                break 

        if n == 1:
            return True 
        
        return False

if __name__ == "__main__":
    sol = Solution()
    a = 1
    b = 1
    print(a is b)
    a = 300  
    b = 300 
    print(a is b)
    # print(sol.isHappy(7))