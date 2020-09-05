class Solution:
    def isPalindrome(self,s: str) -> bool:
        s = s.lower()
        length = len(s)
        ch_nc = []
        for ch in s:
            if ch.isalnum():
                ch_nc.append(ch)
        length = len(ch_nc)
        for i in range(length):
            if ch_nc[i]!= ch_nc[length-1-i]:
                return False
        return True