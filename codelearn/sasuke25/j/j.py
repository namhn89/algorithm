from typing import List 
import collections 

def safeCells(n, connections : List[List[int]], locations: List[int]) -> int:
    graph = [[i] for i in range(0, n)]
    for connection in connections:
        u, v = connection[0], connection[1]
        u -= 1
        v -= 1
        graph[u].append(v)
        graph[v].append(u)

    def parent (mouse_position, cat_position, cat2_position, turn): 
        if turn == 1:
            for cat2 in graph[cat2_position]:
                yield mouse_position, cat_position, cat2, 3
            # yield mouse_position, cat_position, cat2_position, 3
        if turn == 2: 
            for mouse in graph[mouse_position]:
                yield mouse, cat_position, cat2_position, 1
            # yield mouse_position, cat_position, cat2_position, 1
        if turn == 3: 
            for cat in graph[cat_position]:
                yield mouse_position, cat, cat2_position, 2 
            # yield mouse_position, cat_position, cat2_position, 2


    
    color = collections.defaultdict(int)

    childs = {}
    for mouse in range(0, n):
        for cat in range(0, n): 
            for cat2 in range(0, n): 
                childs[mouse, cat, cat2, 1] = len(graph[mouse])
                childs[mouse, cat, cat2, 2] = len(graph[cat]) 
                childs[mouse, cat, cat2, 3] = len(graph[cat2])
    
    queue = collections.deque([])

    for cat in range(0, n):
        for cat2 in range(0, n):
            for turn in range(2, 4):
                if turn == 2:
                    for v in graph[cat]:
                        color[v, cat, cat2, turn] = 1
                        queue.append((v, cat, cat2, turn, 1))
                elif turn == 3:
                    for v in graph[cat2]:
                        color[v, cat, cat2, turn] = 1
                        queue.append((v, cat, cat2, turn, 1))

    while queue: 
        mouse, cat, cat2, turn, colorcurrent = queue.popleft()
        # print(f'{mouse} {cat} {cat2} {turn} {colorcurrent}')
        for m, c, c2, t in parent(mouse, cat, cat2, turn) :
            if color[m, c, c2, t] == 0:
                if colorcurrent == 1 and (t == 2 or t == 3):
                    color[m, c, c2, t] = colorcurrent
                    queue.append((m, c, c2, t, colorcurrent))
                elif colorcurrent == 2 and t == 1:
                    color[m, c, c2, t] = colorcurrent
                    queue.append((m, c, c2, t, colorcurrent))
                else:
                    childs[m, c, c2, t] -= 1
                    if childs[m, c, c2, t] == 0:
                        if t == 2 or t == 3:
                            color[m, c, c2, t] = 2
                            queue.append((m, c, c2, t, 2))
                        else:
                            color[m, c, c2, t] = 1 
                            queue.append((m, c, c2, t, 1))
                # print(f'\t{m} {c} {c2} {t} -> {color[m, c, c2, t]}')

    x, y = locations[0], locations[1]
    x -= 1
    y -= 1
    result = 0
    # print(color)
    for i in range(0, n): 
        oke = True
        if color[i, x, y, 1] == 1: 
            oke = False
        if oke == True:
            result += 1
    return result

if __name__ == "__main__":
    n, con, loc = 9, [[9, 5], [7, 8], [1, 9], [6, 7], [5, 6], [2, 3], [1, 2]], [1, 8]
    print(safeCells(n, con, loc))