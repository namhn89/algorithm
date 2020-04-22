import math
def countCase(n):
    if n == 0:
        return 0
    k = int(math.sqrt(n)) + 1 
    ans = 0
    used = [0] * 50
    def make(x, z):
        if x == 0:
            global ans
            ans += 1 
            return 1
        ok = 0
        for i in range(k):
            if i * i > x:
                break
            if used[i] == 1:
                continue
            if i < z: 
                continue
            used[i] = 1 
            a = i
            ok = ok | make(n - i * i, a)
            used[i] = 0 
        return ok

    for i in range(k):
        for j in range(k):
            used[j] = 0
        used[i] = 1 
        if n >= i * i:
            ans += make(n - i * i, i)
    return ans

if __name__ == "__main__":
    print(countCase(100))