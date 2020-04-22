from collections import defaultdict

def myfn (c):
    return [-c[0], c[1]]

def chooseEmployee(skill, salary, requestSkill, k):
    a = defaultdict(int)
    p = defaultdict(list)

    for i in range(len(skill)):
        p[skill[i]].append(salary[i])
    for c in p: 
        sorted(p[c])

    for c in skill: 
        a[c] += 1

    b = list()
    for c in a: 
        b.append((a[c], c))

    b.sort(key=myfn)

    res = 0 
    y = p[requestSkill]
    y.sort()
    for c in y: 
        if k > 0: 
            res += c 
            k -= 1

    if k > 0: 
        for c in b : 
            y = p[c[1]]
            y.sort()
            if c[1] != requestSkill: 
                for z in y: 
                    if k > 0: 
                        res += z
                        k -= 1 

    if k > 0: 
        return -1 
    else:
        return res

if __name__ == "__main__":
    print(chooseEmployee(["Java",".Net","C++","Java"], [20,40,60,80], ".Net", 3))
    print(chooseEmployee(["B","C","C","A","B","B","A","A"], [30, 50, 20, 10, 40, 60, 80, 70], "C", 4))