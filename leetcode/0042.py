class Solution:
    def trap(self, height: List[int]) -> int:
        
        if height==[]: return 0
        left, right = 0, len(height)-1
        lheight_max, rheight_max = height[0], height[right]
        
        total = 0
        while left<right:
            if lheight_max <= rheight_max:
                left += 1
                lheight_max = max(height[left], lheight_max)
                total += (lheight_max-height[left])
            else:
                right -= 1
                rheight_max = max(height[right], rheight_max)
                total += (rheight_max-height[right])
        return total