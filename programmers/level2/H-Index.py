import collections
def solution(citations):
    def get_dic_key(max_h):
        #dic_key중에서 max_h보다 크면서 가장 작은 값 리턴
        for k in dic_key[::-1]:
            if k>=max_h: return k
        return None

    dic = collections.defaultdict(int) #n번 인용된 논문 수
    accu_dic = collections.defaultdict(int) #n번 이상 인용된 논문 수
    
    for ci in citations:
        dic[ci] += 1
    
    dic_key = sorted(dic.keys(), reverse=True)
    for idx, dk in enumerate(dic_key):
        if idx>0: accu_dic[dk] = accu_dic[dic_key[idx-1]]+dic[dk]
        else: accu_dic[dk] = dic[dk]
    
    max_h = len(citations)
    while True:
        n = get_dic_key(max_h) #max_h보다 같거나 크면서 누적딕셔너리의 키중 가장 작은 값을 리턴
        if n is None:
            max_h -= 1
        elif accu_dic[n]>=max_h: return max_h
        else: max_h -= 1