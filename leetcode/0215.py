class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if not nums: return 0
        priority_q = []
        for num in nums:
            heapq.heappush(priority_q, -num)
        for i in range(k-1):
            heapq.heappop(priority_q)
        return -heapq.heappop(priority_q)