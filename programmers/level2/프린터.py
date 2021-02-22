import collections
import sys
import heapq

def solution(priorities, location):
    heap = [] #가장 높은 우선순위값 얻음
    dq = collections.deque() #현재 저장된 순서
    for idx, pr in enumerate(priorities):
        heapq.heappush(heap, (-pr, idx))
        dq.append((idx, pr))
        
    out = 1
    while True:
        idx, pr = dq.popleft()
        if pr != -heap[0][0]: #최댓값이 아니면
            dq.append((idx, pr))
        elif idx==location: #최댓값이고 찾는위치면
            return out
        else: #최댓값인데 찾는것이 아니면
            out += 1
            heapq.heappop(heap)