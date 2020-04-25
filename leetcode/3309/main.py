from collections import OrderedDict

class LRUCache: 
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.values = OrderedDict()

    @property
    def is_at_capacity(self):
        return len(self.values) > self.capacity 

    def get(self, key: int) -> int:
        val = self.values.get(key, -1)
        if not val is -1: 
            del self.values[key]
            self.values[key] = val
        return val
    
    def put(self, key: int, value: int) -> None:
        if key in self.values:
            del self.values[key]
        self.values[key] = value

        if self.is_at_capacity:
            self.values.popitem(last=False)

if __name__ == "__main__":
    pass


