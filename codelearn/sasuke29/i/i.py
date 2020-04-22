from collections import defaultdict

ans = 0 
a = defaultdict(int)

r_mask = [0] * 10
c_mask = [0] * 10
o_mask = [0] * 10

def solve (r, c):
    if r == 9: 
        ans += 1
        print('oke')
        return 0 
    
    if a[r, c] != 0:
        if c == 8:
            solve(r + 1, 0)
        else:
            solve(r, c + 1)
        return 0 
    
    mask = r_mask[r] | c_mask[c] | o_mask[3 * (r // 3) + (c // 3)]

    for v in range(1, 10):
        if ((mask >> v) & 1) == 0:
            print(r, c, v)
            a[r, c] = v 
            r_mask[r] |= (1 << v)
            c_mask[c] |= (1 << v)
            o_mask[3 * (r // 3) + c // 3] |= (1 << v)

            if r == 8: 
                solve(r + 1, 0)
            else:
                solve(r, c + 1)
        
            a[r, c] = 0
            r_mask[r] ^= (1 << v)
            c_mask[c] ^= (1 << v)
            o_mask[3 * (r // 3) + c // 3] ^= (1 << v)


def countSodokuSolve(matrix):
    for i in range(0, 9):
        for j in range(0, 9): 
            a[i, j] = matrix[i][j]
            r_mask[i] |= (1 << matrix[i][j])
            c_mask[j] |= (1 << matrix[i][j])
            o_mask[3 * (i // 3) + j // 3] |= (1 << matrix[i][j])
    print(r_mask)
    print(c_mask)
    print(o_mask)
    print(a)
    solve(0, 0)
    return ans 

if __name__ == "__main__":
    print(countSodokuSolve([[0,0,4,2,0,1,0,6,0],[0,0,0,0,0,0,0,0,0],[9,0,5,0,0,0,3,0,7],[0,0,0,0,0,0,0,0,0],[5,0,7,0,8,0,1,0,4],[0,1,0,0,0,0,0,9,0],[0,0,1,0,0,0,6,0,0],[0,0,0,7,0,5,0,0,0],[6,0,8,9,0,4,5,0,3]]))
