import heapq
def solution(scoville, K):
    heap = []
    cnt = 0
    for sc in scoville:
        heapq.heappush(heap, sc)
    if heap[0]>=K: return 0
    while len(heap)>=2 and heap[0]<K:
        cnt += 1
        score = heapq.heappop(heap)
        score2 = heapq.heappop(heap)
        new_score = score + 2*score2
        heapq.heappush(heap, new_score)
    return cnt if heap and heap[0]>=K else -1