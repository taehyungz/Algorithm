class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(idx: int, string: str):
            if len(string)==len(digits):
                ans.append(string)
                return
            for j in dic[digits[idx]]:
                dfs(idx+1, string+j)
        
        if not digits: return []
        ans = []
        dic = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl",
               "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        
        dfs(0, "")
        return ans