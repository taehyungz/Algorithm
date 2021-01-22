# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        ls = []
        res = head
        temp = head
        while head:
            ls.append(head.val)
            head = head.next
        ls = sorted(ls)
        for n in ls:
            temp.val = n
            temp = temp.next
        
        return res