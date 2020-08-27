import sys
import heapq

N = int(sys.stdin.readline().rstrip())
heap = []
for i in range(N):
    num = -int(sys.stdin.readline().rstrip())
    if num!=0: heapq.heappush(heap,num)
    elif len(heap)==0:
        print("0")
    else:
        bn = heapq.heappop(heap)
        print(-bn)