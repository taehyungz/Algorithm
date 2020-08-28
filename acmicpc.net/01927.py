import sys
import heapq

minimum_h = []
N = int(sys.stdin.readline().rstrip())
while N>0:
    x = int(sys.stdin.readline().rstrip())
    lenq = len(minimum_h)
    if lenq != 0 and x == 0:
        minx = heapq.heappop(minimum_h)
        print(minx)
    elif lenq == 0 and x == 0:
        print("0")
    else: heapq.heappush(minimum_h, x)
    N -= 1