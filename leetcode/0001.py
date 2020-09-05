class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        n = len(nums)
        for i, n in enumerate(nums):
            diff = target-n
            if diff in hash_map:
                return [i,hash_map[diff]]
            hash_map[n] = i