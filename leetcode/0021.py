# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = None
        if l1 or l2:
            head = ListNode()
            result = head
        
        while l1 and l2:
            result.next = ListNode()
            if l1.val<l2.val:
                result.val=l1.val
                result = result.next
                l1 = l1.next
            else:
                result.val=l2.val
                result = result.next
                l2 = l2.next
        while l1:
            result.val = l1.val
            l1 = l1.next
            if l1:
                result.next = ListNode()
                result = result.next                
            
        while l2:
            result.val = l2.val
            print(result.val)
            l2 = l2.next
            if l2:
                result.next = ListNode()
                result = result.next
            
        return head