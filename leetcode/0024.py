# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        root = prev = ListNode()
        prev.next = head
        
        while head and head.next:
            second = head.next
            head.next = second.next
            second.next = head
            
            prev.next = second
            
            prev = prev.next.next
            head = head.next
            
        return root.next