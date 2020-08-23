import math
ls = list(map(int, input().split()))
while ls.count(0)!=3:
    minnum = min(ls)
    ls.remove(minnum)
    maxnum = max(ls)
    ls.remove(maxnum)
    midnum = ls[0]
    ls.remove(midnum)
    if math.pow(minnum,2)+math.pow(midnum,2) == math.pow(maxnum,2):
        print("right")
    else:
        print("wrong")
    ls = list(map(int, input().split()))