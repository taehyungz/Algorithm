import collections
def solution(citations):
    def get_dic_key(max_h):
        #dic_key�߿��� max_h���� ũ�鼭 ���� ���� �� ����
        for k in dic_key[::-1]:
            if k>=max_h: return k
        return None

    dic = collections.defaultdict(int) #n�� �ο�� �� ��
    accu_dic = collections.defaultdict(int) #n�� �̻� �ο�� �� ��
    
    for ci in citations:
        dic[ci] += 1
    
    dic_key = sorted(dic.keys(), reverse=True)
    for idx, dk in enumerate(dic_key):
        if idx>0: accu_dic[dk] = accu_dic[dic_key[idx-1]]+dic[dk]
        else: accu_dic[dk] = dic[dk]
    
    max_h = len(citations)
    while True:
        n = get_dic_key(max_h) #max_h���� ���ų� ũ�鼭 ������ųʸ��� Ű�� ���� ���� ���� ����
        if n is None:
            max_h -= 1
        elif accu_dic[n]>=max_h: return max_h
        else: max_h -= 1