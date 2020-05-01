from typing import List

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left 
        self.right = right

class Solution(object):
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        def existPath(root: TreeNode, arr: List[int], n: int, index: int) -> bool:
            if index >= n: 
                return False
            if root == None:
                return (n == 0)
            # print (index, arr[index])
            if root.left == None and root.right == None \
                and root.val == arr[index] and index == n - 1 :
                return True
            
            return (index < n) and (root.val == arr[index]) and \
                (existPath(root.left, arr, n, index + 1) or \
                existPath(root.right, arr, n, index + 1) )

        return existPath(root, arr, len(arr), 0)

if __name__ == "__main__":
    sol = Solution()
    root = TreeNode(1)
    root.left = TreeNode(0)
    root.right = TreeNode(0)
    root.right.left = TreeNode(0)
    root.left.left = TreeNode(0)
    root.left.left.left = TreeNode(1)
    root.left.right = TreeNode(1)
    root.left.right.left = TreeNode(0)
    root.left.right.right = TreeNode(0)

    print(sol.isValidSequence(root, [0, 1, 1]))
