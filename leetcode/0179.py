class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def cond_swap(n1: int, n2: int) -> bool:
            return str(n1)+str(n2) < str(n2)+str(n1)
        
        i = 1
        while len(nums)>i:
            j = i
            while j > 0 and cond_swap(nums[j-1], nums[j]):
                nums[j], nums[j-1] = nums[j-1], nums[j]
                j -= 1
            
            i += 1
            
        return str(int(''.join(map(str,nums))))