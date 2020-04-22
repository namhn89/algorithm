inf = 10**9

def equalitree(parents, values):
    children = [[] for _ in range(len(parents))]
    for i in range(1, len(parents)):
        children[parents[i]] += [i]
        
    memo = {}
    def tf(r):
        if r not in memo:
            if not children[r]:
                memo[r] = (0, 1) if values[r] else (1, 0)
            elif len(children[r]) == 1:
                memo[r] = 1 - values[r] + min(tf(children[r][0])), inf
            else:
                ct, cf = zip(*[tf(c) for c in children[r]])
                t = min(sum(ct), sum(cf)) + 1 - values[r]
                f = values[r]
                mch = inf
                fl = 0
                for tt, ff in (tf(c) for c in children[r]):
                    if tt < ff:
                        f += tt
                        fl |= 1
                    elif ff < tt:
                        f += ff
                        fl |= 2
                    else:
                        f += ff
                        fl |= 3
                    mch = min(mch, abs(tt - ff))
                if fl != 3:
                    f += mch
                memo[r] = t, f
        return memo[r]

    return min(tf(0))