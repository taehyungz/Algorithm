# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # preorder : V L R
    # inorder : L V R
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if inorder:
            div_index = inorder.index(preorder.pop(0))
            node = TreeNode(inorder[div_index])
            
            node.left = self.buildTree(preorder, inorder[:div_index])
            node.right = self.buildTree(preorder, inorder[div_index+1:])
            return node