class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def maxPathSum(self, root: TreeNode) -> int:
        self.result = float("-inf")
        def dfs(root: TreeNode) -> int:
            if not root:
                return 0
            left_result = dfs(root.left)
            right_result = dfs(root.right)
            res = max(root.val, root.val + max(left_result, right_result))
            self.result = max(res, self.result, root.val + left_result + right_result)
            return res
        return max(dfs(root), self.result)

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    sol = Solution()
    print(sol.maxPathSum(root))




        