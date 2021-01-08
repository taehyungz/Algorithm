import sys

N = int(input())
M = int(input())
broken = []
if M > 0:
    broken = list(map(str, sys.stdin.readline().split()))
result = abs(N-100)
for i in range(1000001):
    check = True
    for each_num in str(i):
        if each_num in broken:
            check = False
            break
    if check:
        result = min(result, abs(N-i) + len(str(i)))
print(result)
