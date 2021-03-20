import itertools

def solution(relation):
    def examine(idxs): #�ּ�Ű ���� �˻�
        for key in key_idx: #Ű�� �Ǻ��� �͵� �߿���
            check = False
            for part_key in key: #�˻��ؼ� Ű�� �Ǻ��� ���� ������ �����ϸ� �ּ�Ű �ƴ�
                if part_key not in idxs: #�ּ�Ű ���ɼ� ����
                    check = True
            if not check: return False #��� �˻� ����ϸ� �ּ�Ű��
        return True
    
    len_rel = len(relation[0])
    key_idx = set()
    idx_list = list(range(len_rel)) #idx �ĺ���
    for length in range(1,len_rel+1):
        idx_arr = tuple(itertools.combinations(idx_list, length)) #���� �ε�����
        temp_rel = list(zip(*relation)) #�ο�� ����
        for idxs in idx_arr:
            ls = []
            for i in idxs: #�ο�� ���� �迭���� ���� �ε����� �ִ� ������� ����
                ls.append(temp_rel[i])
            final_rel = list(zip(*ls))
            if len(list(set(final_rel))) == len(final_rel) and examine(idxs):
                key_idx.add(idxs)
    return len(key_idx)