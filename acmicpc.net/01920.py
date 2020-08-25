import sys

def find(ls1, num):
    left = 0
    right = len(ls1)-1
    while left<=right:
        mid = int((left+right+1)/2)
        if ls1[mid]==num: return True
        elif ls1[mid]>num: right = mid-1
        else: left = mid + 1
    return False
N = int(input().rstrip())
ls1 = list(map(int,sys.stdin.readline().rstrip().split()))
ls1 = sorted(ls1)
M = int(input().rstrip())
ls2 = list(map(int,sys.stdin.readline().rstrip().split()))
for i in range(M):
    if find(ls1, ls2[i]):
        print("1")
    else:
        print("0")