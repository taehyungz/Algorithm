class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(temp_nums, temp_ans):
            for i in range(len(temp_nums)):
                temp_ans.append(temp_nums[i])
                dfs(temp_nums[:i]+temp_nums[i+1:], temp_ans)
                temp_ans.pop()
            if len(temp_ans) == len(nums):
                ans.append(temp_ans[:])
        ans = []
        dfs(nums, [])
        return ans