class TreeNode (object):
    def __init__(self, x):
        self.val = x 
        self.left = None 
        self.right = None 

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 1
        def dfs (node: TreeNode):
            if not node: 
                return 0
            l = dfs(node.left)
            r = dfs(node.right)
            self.ans = max(self.ans, l + r + 1)
            return max(l, r) + 1
        dfs(root)
        return self.ans  

if __name__ == "__main__":
    sol = Solution()