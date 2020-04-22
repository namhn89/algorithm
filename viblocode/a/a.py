import math 
import sys
n, x, y = [float(x) for x in input().split(' ')]
k = int(input())

lai = (x / 100.0) / 12.0 
ans = 0
ansz = 0
for i in range(0, k):
    newl = n * (1 + lai) 
    p = newl - y 
    if p < 0.0:
        n = 0.0
        break
    else:
        n = p 
        
ans = int(n)

l = 600 - k
z = -1  
for i in range(0, l):
    newl = n * (1 + lai)
    p = newl - y
    if p <= 0.0: 
        z = i + 1
        n = 0.0
        break 
    else:
        n = p 

print(ans)
if ans == 0:
    print(0) 
else:
    print(z)

