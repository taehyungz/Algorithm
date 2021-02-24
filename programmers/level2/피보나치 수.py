import collections
def solution(n):
    dic = collections.defaultdict(int)
    dic[1] = 1
    for i in range(2, n+1):
        dic[i] = (dic[i-1] + dic[i-2])%1234567
    return dic[n]