import collections 
import queue
from typing import List

class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        N = len(graph) 
        def parent (mouse_position, cat_position, turn): 
            if turn == 2: 
                for mouse in graph[mouse_position]:
                    yield mouse, cat_position, 3 - turn
            else:
                for cat in graph[cat_position]:
                    if cat: 
                        yield mouse_position, cat, 3 - turn 
        
        DRAW, MOUSE, CAT = 0, 1, 2
        color = collections.defaultdict(int)

        childs = {}
        for mouse in range(0, N):
            for cat in range(0, N): 
                childs[mouse, cat, 1] = len(graph[mouse])
                childs[mouse, cat, 2] = len(graph[cat]) - (0 in graph[cat])

        queue = collections.deque([])

        for cat in range(0, N):
            for turn in range(1, 3):
                color[0, cat, turn] = MOUSE
                queue.append((0, cat, turn, MOUSE))
                if cat > 0 : 
                    color[cat, cat, turn] = CAT
                    queue.append((cat, cat, turn, CAT))

        while queue: 
            mouse, cat, turn, colorcurrent = queue.popleft()

            for m, c, t in parent(mouse, cat, turn):
                
                if color[m, c, t] == DRAW: 
                    if t == colorcurrent: 
                        color[m, c, t] = colorcurrent
                        queue.append((m, c, t, colorcurrent))
                    else: 
                        childs[m, c, t] -= 1 
                        if childs[m, c, t] == 0: 
                            color[m, c, t] = 3 - t 
                            queue.append((m, c, t, 3 - t))

        return color[1, 2, 1]

if __name__ == "__main__":
    sol = Solution() 
    print(sol.catMouseGame([[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]))
