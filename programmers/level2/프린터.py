import collections
import sys
import heapq

def solution(priorities, location):
    heap = [] #���� ���� �켱������ ����
    dq = collections.deque() #���� ����� ����
    for idx, pr in enumerate(priorities):
        heapq.heappush(heap, (-pr, idx))
        dq.append((idx, pr))
        
    out = 1
    while True:
        idx, pr = dq.popleft()
        if pr != -heap[0][0]: #�ִ��� �ƴϸ�
            dq.append((idx, pr))
        elif idx==location: #�ִ��̰� ã����ġ��
            return out
        else: #�ִ��ε� ã�°��� �ƴϸ�
            out += 1
            heapq.heappop(heap)