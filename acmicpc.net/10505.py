import sys
import collections
N, M = map(int, input().split())
ls = list(map(int,sys.stdin.readline().rstrip().split()))
maxh = max(ls)-1

d = collections.Counter(ls)
m = d.most_common()
m = sorted(m)
left = 0
right = maxh

while left<=right:
    mid = (left+right)//2
    sum = 0
    for i in range(len(m)):
        a, b = m[i]
        if a>mid:
            sum = sum + (a-mid)*b
    if sum<M:
        right = mid-1
    else:
        left = mid+1
print((left+right)//2)