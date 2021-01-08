import sys
from itertools import combinations

N, M = tuple(map(int, sys.stdin.readline().split()))
houses = []
stores = []
for i in range(N):
    temp = list(map(int, sys.stdin.readline().split()))
    for j in range(len(temp)):
        if temp[j] == 1:
            houses.append((i, j))
        elif temp[j] == 2:
            stores.append((i, j))

min_distance = sys.maxsize
for store in combinations(stores, M):
    dis_sum = 0
    for house in houses:
        dis_sum += min([abs(house[0]-each_store[0])+abs(house[1]-each_store[1]) for each_store in store])
    min_distance = min(min_distance, dis_sum)
print(min_distance)
