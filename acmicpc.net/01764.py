import sys

N, M = map(int, input().split())
nohear = set()
nosee = set()
for i in range(N):
    nohear.add(sys.stdin.readline().rstrip())
for i in range(M):
    nosee.add(sys.stdin.readline().rstrip())
sort_nohearsee = sorted(nohear.intersection(nosee))
n = len(sort_nohearsee)
print(n)
for i in range(n):
    print(sort_nohearsee[i])