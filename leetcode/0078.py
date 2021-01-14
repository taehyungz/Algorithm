class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        
        def DFS(length: int, temp: List[int], last: int):
            if length == len(temp):
                result.append(temp[:])
                return
            for i in range(last+1, len(nums)):
                DFS(length, temp+[nums[i]], i)                
            
        for length in range(len(nums)+1):
            DFS(length, [], -1)
        
        return result