def bestFriend(a, b):
    m = min(b[0], b[1]) 
    n = max(b[0], b[1])
    c1 = 0 
    c2 = 0 
    c3 = 0
    for c in a: 
        if c <= m: 
            c1 += 1 
        elif c > m and c <= n:
            c2 += 1 
        elif c > n :
            c3 += 1 
    # print(c1, c2, c3)
    x = min(c1, c2)
    ans = c3 + x 
    c1 -= x 
    c2 -= x
    if c1 > 0 : 
        ans += (c1 + 1) // 2 
    if c2 > 0 :
        ans += c2
    return ans

if __name__ == "__main__":
    print(bestFriend([1, 4, 5, 5], [4, 5]))