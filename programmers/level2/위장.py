import collections
from itertools import permutations
def solution(clothes):
    dic = collections.defaultdict(int)
    for c in clothes:
        dic[c[1]] += 1
    ans = 1
    for k in dic.keys(): #�� �׸񺰷�
        ans *= (dic[k]+1)
        #�׸� ���� ���ǵ��� ���� ���(dic[k])+�� ���� ���(1)
    return ans-1