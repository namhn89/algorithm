import math

class Solution (object):
    def solve(self, p): 
        W, H, L, U, R, D = [int(c) for c in p.split()]

        def nCr (k, n):
            ans = pow(0.5, n)
            for i in range(1, k + 1):
                ans = ans * (float((n + 1 - i)) / float(i))

            return ans
        
        res = 0.0 
        if L > 1 and D < H:
            ansC = 0 
            N = D + L - 2 
            ansC += nCr(L - 2, N)
            res += ansC 
        
        if U > 1 and R < W: 
            ansR = 0
            N = R + U - 2
            ansR += nCr(U - 2, N)
            res += ansR 
        
        return res

if __name__ == "__main__":
    n_test = int(input())
    sol = Solution()
    for tc in range(n_test):
        ans = sol.solve(input())
        print('Case #' + str(tc + 1) + ': ' + str(ans))
    
