class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        return sorted(points, key = lambda x: x[0]**2 + x[1]**2)[:K]

	
    def kClosest2(self, points: List[List[int]], K: int) -> List[List[int]]:
        heap = []
        
        for x, y in points:
            dist = x**2 + y**2
            heapq.heappush(heap, [dist, x, y])
        
        ans = []
        for i in range(K):
            ans.append(heapq.heappop(heap)[1:3])
        return ans