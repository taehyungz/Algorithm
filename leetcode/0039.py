class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def DFS(sum_numbers, index, path):
            if sum_numbers < 0:
                return
            elif sum_numbers == 0:
                ans.append(path)
                return
            for i in range(index, len(candidates)):
                DFS(sum_numbers - candidates[i], i, path+[candidates[i]])
        DFS(target, 0, [])
        return ans