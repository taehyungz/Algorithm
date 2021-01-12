# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        def DFS(node1, node2):
            if node1.left and node2.left:
                DFS(node1.left, node2.left)
            elif not node1.left:
                node1.left = node2.left
            if node1.right and node2.right:
                DFS(node1.right, node2.right)
            elif not node1.right:
                node1.right = node2.right
            node1.val += node2.val
            return
        if not t1:
            return t2
        if not t2:
            return t1
        DFS(t1, t2)
        return t1
            