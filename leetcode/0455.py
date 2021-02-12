class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)
        idx1 = 0
        idx2 = 0
        while True:
            if idx1<len(g) and idx2<len(s) and g[idx1]<=s[idx2]:
                idx1+=1
                idx2+=1
            elif idx1<len(g) and idx2<len(s) and g[idx1]>s[idx2]:
                idx2+=1
            else:
                break
        
        return idx1