import heapq

def solution(n, works):
    answer = 0
    heap = []
    if sum(works) < n: return 0
    
    for more_time in works:
        heapq.heappush(heap, -more_time)
    while heap and n>0:
        big_num = -heapq.heappop(heap)
        big_num -= 1
        n -= 1
        if big_num!=0: heapq.heappush(heap,-big_num)
    return sum([x**2 for x in heap])