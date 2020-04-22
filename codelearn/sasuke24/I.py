from collections import deque, defaultdict
import collections
import re
from time import time 

def find_all(a_str, sub):
    start = 0
    while True:
        start = a_str.find(sub, start)
        if start == -1: 
            return
        yield start
        start += 1

BASE = 97 
MOD = 10**9 + 7

def encode(string: str):
    ec = 0 
    for c in string : 
        ec = (ec * BASE) + ord(c) - ord('A')
        ec %= MOD 
    return ec 

class Trie(object):

    def __init__(self):
        self.root = {}

    def insert(self, word):
        cur = self.root
        for w in word:
            if w not in cur:
                cur[w] = {}
            cur = cur[w]
        cur['$'] = None # end marker

    def search(self, word) -> bool:
        cur = self.root
        for w in word:
            if w not in cur:
                return False
            cur = cur[w]
        return '$' in cur

    def startsWith(self, prefix) -> bool:
        cur = self.root
        for w in prefix:
            if w not in cur:
                return False
            cur = cur[w]
        return True

class Solution(object): 
    def __init__(self, start : str, target : str, n, arr):
        self.keven = n // 2 
        self.kodd = n - self.keven
        self.start = start 
        self.target = target 
        self.n = n 
        self.arr = arr  
        self.dict = {}
        self.newElement = Trie() 
        self.trie = Trie()
    def solve(self) -> bool: 
        frontset = list()
        nextset = list()

        frontset.append(self.start)
        if self.keven == 0 :
            self.trie.insert(self.start) 
        for k in range(1, self.keven + 1):
            for strStatue in frontset:
                for strOp in self.arr : 
                    strfoo = strOp[0]
                    if len(strfoo) > len(strStatue) : 
                        continue
                    strbar = strOp[1]
                    search = strfoo
                    for index in list(find_all(strStatue, search)):
                        st = index 
                        ed = index + len(search) 
                        newStr = strStatue[:st] + strbar + strStatue[ed:]
                        if self.newElement.search(newStr) == False:
                            self.newElement.insert(newStr)
                            nextset.append(newStr)
                            
                        # print(st, ed)
                        # print(strfoo, strbar)
                        # print(strStatue, newStr)
            # print(str(k) + " : ", end=' ')
            # for c in nextset: 
            #     print(c, end=' ')
            # print('')
            self.newElement = Trie()
            if k == self.keven: 
                for strStatue in nextset:
                    self.trie.insert(strStatue)
            else:
                frontset.clear()
                for c in nextset: 
                    frontset.append(c) 
                nextset.clear()

        nextset.clear()
        frontset.clear()

        if self.kodd == 0: 
            if self.dict.get(encode(self.target)) == 1:
                return True

        frontset.append(self.target)
        for k in range(1, self.kodd + 1):
            for strStatue in frontset:
                for strOp in self.arr : 
                    strfoo = strOp[1]
                    if len(strfoo) > len(strStatue) : 
                        continue
                    strbar = strOp[0]
                    search = strfoo
                    for index in list(find_all(strStatue, search)):
                        st = index 
                        ed = index + len(search) 
                        newStr = strStatue[:st] + strbar + strStatue[ed:]
                        if self.newElement.search(newStr) == False:
                            self.newElement.insert(newStr)
                            nextset.append(newStr)
                        # print(st, ed)
                        # print(strfoo, strbar)
                        # print(strStatue, newStr)
            # print(str(k) + " : ", end=' ')
            # for c in nextset: 
            #     print(c, end=' ')
            # print('')
            self.newElement = Trie()
            if k == self.kodd: 
                for strStatue in nextset:
                    if self.trie.search(strStatue) == True:
                        return True
            else:
                frontset.clear()
                for c in nextset: 
                    frontset.append(c) 
                nextset.clear()

        return False

def unlockTheCode(start, target, n, arr):
    if len(start) >= 30 or len(target) >= 30:
        return True
    sol = Solution(start, target, n, arr)
    return sol.solve()

if __name__ == "__main__":
    start = time()
    print(unlockTheCode("XXXOXXOOXX", "OOOOOOOO", 7, [["X", "O"], ["O", "XX"], ["O", "X"]]))
    end = time()
    print("Total time : {} ms".format((end - start) * 1000))