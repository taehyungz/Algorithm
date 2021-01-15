# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        
        idx = len(nums)//2
        
        node = TreeNode(nums[idx])
        node.left = self.sortedArrayToBST(nums[:idx])
        node.right = self.sortedArrayToBST(nums[idx+1:])
        
        return node