import sys
import heapq

N = int(sys.stdin.readline().rstrip())
plus = []
minus = []
for i in range(N):
    x = int(sys.stdin.readline().rstrip())
    if x > 0: heapq.heappush(plus, x)
    elif x < 0 : heapq.heappush(minus,-x)
    else:
        pluslen = len(plus)
        minuslen = len(minus)
        if pluslen>0: a = heapq.heappop(plus)
        if minuslen>0: b = heapq.heappop(minus)

        if pluslen==0 and minuslen==0: print("0")
        elif pluslen==0: print(-b)
        elif minuslen==0: print(a)
        elif a<b:
            print(a)
            heapq.heappush(minus,b)
        else:
            print(-b)
            heapq.heappush(plus,a)