from typing import List 

class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        n = len(s)
        for direction in shift:
            option = direction[0]
            length = direction[1]
            if option == 1: 
                pos = n - length 
                new_str = s[pos:] + s[:pos]
                s = new_str
                # print(new_str)
            else:
                new_str = s[length:] + s[:length]
                s = new_str 
                # print(new_str)
        return s
if __name__ == "__main__":
    sol = Solution()
    print(sol.stringShift("abcdefg", [[1,1],[1,1],[0,2],[1,3]]))