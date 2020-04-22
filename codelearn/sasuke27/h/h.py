def getDay(a, n):
    a = int(a)
    n = int(n)
    ans = 0 
    sum = 0 
    n = n // a
    x = 1 
    if n == 0: 
        return 0 
    while True:
        sum += x
        # print(sum) 
        if sum > n:
            break
        if sum == n :
            ans += 1 
            return ans  
        x = x * 2 
        ans += 1 
if __name__ == "__main__":
    print(getDay("50", "1550"))
     