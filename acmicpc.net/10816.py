import collections
N = int(input())
cards = list(map(int,input().split()))
M = int(input())
solve = list(map(int, input().split()))
counter = collections.Counter(cards)
for i in range(M):
    ans = counter.get(solve[i])
    if ans!=None:
        print(ans, end=' ')
    else:
        print("0", end=' ')
