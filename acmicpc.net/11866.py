N, K = map(int,input().split())
ls = []
people = [i for i in range(1,N+1)]
idx = -1
print("<",end='')
while len(people)!=1:
    idx = idx+K
    if idx>len(people)-1:
        idx = idx % len(people)
    print(f"{people[idx]},", end=' ')
    people.pop(idx)
    idx -= 1
print(f"{people[0]}>")