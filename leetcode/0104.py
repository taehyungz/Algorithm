# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def DFS(root, md):
            left, right = 1, 1
            if not root.left and not root.right:
                return md
            if root.left:
                left = DFS(root.left, md+1)
            if root.right:
                right = DFS(root.right, md+1)
            return max(left, right)
        
        if not root: return 0
        return DFS(root, 1)