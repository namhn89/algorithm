
class Solution(object):

    def isEscapePossible(self, blocked, source, target):
        """
        :type blocked: List[List[int]]
        :type source: List[int]
        :type target: List[int]
        :rtype: bool
        """
        blocked = set([(x[0], x[1]) for x in blocked])
        dir = [(-1, 0), (1, 0), (0, 1), (0, -1)]

        def gen_neighbor(x, y):
            for dx, dy in dir:
                if x + dx < 0 or x + dx > 1e6 or y + dy < 0 or y + dy > 1e6:
                    continue
                nx, ny = x + dx, y + dy
                yield nx, ny

        def is_in_box(x, y, center_x, center_y, length):
            return center_x - length <= x <= center_x + length and \
                center_y - length <= y <= center_y + length


        def is_blocked(start_x, start_y, end_x, end_y):
            seen = set()
            stack = [(start_x, start_y)]
            seen.add((start_x, start_y))
            while stack:
                x, y = stack.pop(-1)
                if not is_in_box(x, y, start_x, start_y, len(blocked)) or \
                        (x == end_x and y == end_y):
                    return True

                for nx, ny in gen_neighbor(x, y):
                    if (nx, ny) in blocked or (nx, ny) in seen: continue
                    seen.add((nx, ny))
                    stack.append((nx, ny))
            return False

        return is_blocked(source[0], source[1], target[0], target[1]) and \
               is_blocked(target[0], target[1], source[0], source[1])

if __name__ == "__main__":
    sol = Solution()
    print(sol.isEscapePossible([[1, 1]], [0, 0], [10, 10]))