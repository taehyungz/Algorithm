class Solution:
    def isValid(self, s: str) -> bool:
        ls = []
        for ch in s:
            if ch=='(' or ch=='{' or ch=='[':
                ls.append(ch)
            elif ch==')' and ls and ls[-1]=='(':
                ls.pop()
            elif ch=='}' and ls and ls[-1]=='{':
                ls.pop()
            elif ch==']' and ls and ls[-1]=='[':
                ls.pop()
            else: return False
        if not ls:
            return True
        else:
            return False