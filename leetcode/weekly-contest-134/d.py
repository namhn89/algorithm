from collections import deque 
from typing import List
class Solution(object):
    def gen(self, x, y):
        for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            xx = x + dx 
            yy = y + dy 
            if xx > 10**6 or yy > 10**6 or xx < 0 or yy < 0: 
                continue
            yield xx, yy

    def dfs (self, x, y, step): 
        if (x, y) == self.target or len(self.visited) > self.len_blocked * (self.len_blocked - 1) // 2 : 
            return True
        self.visited.add((x, y))

        for xx, yy in self.gen(x, y):
            if (xx, yy) not in self.visited and (xx, yy) not in self.blocked: 
                self.visited.add((xx, yy))
                if self.dfs(xx, yy, step + 1):
                    return True

        return False

    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        self.blocked = set(map(tuple, blocked))
        self.len_blocked = len(blocked)
        self.target = tuple(target)
        self.source = tuple(source)
        self.visited = set()
        result = self.dfs(source[0], source[1], 0)
        self.target = tuple(source)
        self.visited.clear()
        result = result and self.dfs(target[0], target[1], 0)
        return result

if __name__ == "__main__":
    sol = Solution()
    print(sol.isEscapePossible([[100059,100063],[100060,100064],[100061,100065],[100062,100066],[100063,100067],[100064,100068],[100065,100069],[100066,100070],[100067,100071],[100068,100072],[100069,100073],[100070,100074],[100071,100075],[100072,100076],[100073,100077],[100074,100078],[100075,100079],[100076,100080],[100077,100081],[100078,100082],[100079,100083],[100080,100082],[100081,100081],[100082,100080],[100083,100079],[100084,100078],[100085,100077],[100086,100076],[100087,100075],[100088,100074],[100089,100073],[100090,100072],[100091,100071],[100092,100070],[100093,100069],[100094,100068],[100095,100067],[100096,100066],[100097,100065],[100098,100064],[100099,100063],[100098,100062],[100097,100061],[100096,100060],[100095,100059],[100094,100058],[100093,100057],[100092,100056],[100091,100055],[100090,100054],[100089,100053],[100088,100052],[100087,100051],[100086,100050],[100085,100049],[100084,100048],[100083,100047],[100082,100046],[100081,100045],[100080,100044],[100079,100043],[100078,100044],[100077,100045],[100076,100046],[100075,100047],[100074,100048],[100073,100049],[100072,100050],[100071,100051],[100070,100052],[100069,100053],[100068,100054],[100067,100055],[100066,100056],[100065,100057],[100064,100058],[100063,100059],[100062,100060],[100061,100061],[100060,100062]]
,[100079,100063],
[999948,999967]))
        
