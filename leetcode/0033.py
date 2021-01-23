class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def find_idx(target: int) -> int:
            left, right = 0, len(nums2)-1
            
            while left<=right:
                mid = left + (right-left)//2
                
                if nums2[mid] > target:
                    right = mid - 1
                elif nums2[mid] < target:
                    left = mid + 1
                else:
                    return mid
            return -1
        
        nums2 = sorted(nums)
        target_idx = find_idx(target)
        pivot_idx = find_idx(nums[0])
        
        if target_idx == -1:
            return -1
        elif target_idx < pivot_idx:
            return len(nums) - (pivot_idx - target_idx)
        else:
            return target_idx - pivot_idx