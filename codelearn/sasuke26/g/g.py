def moveCandy(candies):
    cnt = [0] * 10; 
    for v in candies:
        cnt[v] += 1 
    ans = 0 
    res = min(cnt[2], cnt[1])
    ans += res
    cnt[1] -= res 
    cnt[2] -= res 
    res = min(cnt[2], cnt[4])
    ans += res 
    cnt[2] -= res 
    cnt[4] -= res 
    ans += 2 * (cnt[1] / 3) + cnt[1] % 3 
    if (cnt[2] > 0):
        return -1
    if len(candies) == 1 and candies[0] == 1:
        return -1 
    elif len(candies) == 2 and candies[0] == 1 and candies[1] == 1:
        return -1 
    return ans 


