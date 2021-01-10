import sys
import heapq
T = int(input())

for each_test in range(T):
    N = int(input())
    idx_check = [False]*1000000
    minh = []
    maxh = []
    for each_input in range(N):
        order, num = sys.stdin.readline().split()
        if order == 'I':
            heapq.heappush(minh, (int(num), each_input))
            heapq.heappush(maxh, (-int(num), each_input))
            idx_check[each_input] = True
        elif num == '1': # 최댓값 삭제
            while maxh and not idx_check[maxh[0][1]] : heapq.heappop(maxh)
            if maxh:
                idx_check[maxh[0][1]] = False
                heapq.heappop(maxh)
        else:
            while minh and not idx_check[minh[0][1]] : heapq.heappop(minh)
            if minh:
                idx_check[minh[0][1]] = False
                heapq.heappop(minh)

    while minh and not idx_check[minh[0][1]] : heapq.heappop(minh) # 삭제하거나 없는 값이므로 삭제
    while maxh and not idx_check[maxh[0][1]] : heapq.heappop(maxh) # 삭제하거나 없는 값이므로 삭제

    if minh and maxh:
        print(-maxh[0][0], minh[0][0])
    else:
        print("EMPTY")


