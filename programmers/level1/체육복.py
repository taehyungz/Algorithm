import collections

def solution(n, lost, reserve):
    dic = collections.defaultdict(int)
    for i in range(len(lost)):
        dic[lost[i]-1] -= 1
    for i in range(len(reserve)):
        dic[reserve[i]-1] += 2
    total = 0
    for i in range(n):
        if dic[i]==-1:#i가 없으면
            if 0<i and dic[i-1]>1:
                dic[i-1]-=1
                dic[i]+=1
                total += 1
            elif i<n and dic[i+1]>1:
                dic[i+1]-=1
                dic[i]+=1
                total += 1
        else: total += 1
    return total