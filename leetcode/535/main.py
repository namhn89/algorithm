class Trie(object):
    def __init__(self):
        self.root = {}
        
    def insert(self, word):
        cur = self.root
        for c in word:
            if c not in cur:
                cur[c] = {} 
            cur = cur[c] 
        cur["-"] = True

    def search(self, word):
        cur = self.root
        for c in word:
            if c not in cur: 
                return False
            cur = cur[c]
        return "-" in cur 
    
    def startsWith(self, prefix):
        cur = self.root
        for c in prefix:
            if c not in cur: 
                return False
            cur = cur[c]
        
        return True

if __name__ == "__main__":
    trie = Trie()
    trie.insert("aaa")
    trie.insert("bac")
    trie.insert("cab")
    print(trie.search("aaa"))
    print(trie.startsWith("ca"))
