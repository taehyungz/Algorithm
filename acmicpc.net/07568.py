N = int(input())

ls = []
for i in range(N):
    ls.append(tuple(map(int,input().split())))
rank = []
for i in range(len(ls)):
    sum = 1
    a, b = ls[i]
    for j in range(len(ls)):
        if i==j: continue
        c, d = ls[j]
        if a<c and b<d: sum += 1
    rank.append(sum)
for i in range(len(ls)-1): print(f'{rank[i]} ', end='')
print(rank[len(rank)-1])