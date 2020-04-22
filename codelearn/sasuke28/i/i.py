from math import factorial

MOD = 10**9 + 7

def nCr (n, r):
    return factorial(n) // (factorial(n - r) * factorial(r))

def connectingPoints(n):
    n = n // 2 
    return int(nCr(2 * n, n)) % MOD 
    
    
if __name__ == "__main__":
    pass