class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        window = []
        ans = []
        cnt = 0
        temp_max = -sys.maxsize
        
        for i, v in enumerate(nums):
            cnt += 1
            heapq.heappush(window, (-v, i))
            if cnt<k:
                continue
            while True:
                n, idx = heapq.heappop(window)
                n = -n
                if i-k < idx <= i:
                    cnt -= 1
                    ans.append(n)
                    if idx!=i-k+1:
                        heapq.heappush(window, (-n, idx))
                    break
                        
        return ans