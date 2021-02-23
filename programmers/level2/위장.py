import collections
from itertools import permutations
def solution(clothes):
    dic = collections.defaultdict(int)
    for c in clothes:
        dic[c[1]] += 1
    ans = 1
    for k in dic.keys(): #각 항목별로
        ans *= (dic[k]+1)
        #항목 안의 물건들을 입을 경우(dic[k])+안 입을 경우(1)
    return ans-1