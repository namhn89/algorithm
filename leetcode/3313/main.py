from typing import List
from collections import defaultdict
class FirstUnique:
    def __init__(self, numbers: List[int]):
        self.dict = defaultdict(int)
        self.used = defaultdict(int)
        self.arr = set()
        for c in numbers:
            self.dict[c] += 1
            self.used[c] = 1  
        for c in numbers:
            if self.dict[c] == 1:
                self.arr.add(c)

    def showFirstUnique(self) -> int:
        if len(self.arr) == 0:
            return -1 
        return self.arr[0]

    def add(self, value: int) -> None:
        if value in self.arr: 
            if self.used[value] == 1:
                self.arr.remove(value)
        else:
            if self.used[value] == 0:
                self.used[value] = 1
                self.arr.add(value)
                
if __name__ == "__main__":
    obj = FirstUnique([2, 3, 5])
    print(obj.showFirstUnique())
    obj.add(5)
    print(obj.showFirstUnique())
    obj.add(2)
    print(obj.showFirstUnique())
    obj.add(3)
    print(obj.showFirstUnique())