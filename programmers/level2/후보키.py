import itertools

def solution(relation):
    def check_duplicated(candidate_combination_key):
        for ck in ck_list: # �� �ĺ�Ű�� ����
            duplicated = True
            for splited_key in ck: # �ĺ�Ű�� �� ���ҵ���
                if splited_key not in candidate_combination_key: duplicated = False # ��� �̹� ����Ű�� ������ �ĺ�Ű�� �ƴϴ�
            if duplicated: return True
        return False
                
    row_count = len(relation)
    ck_list = []
    for i in range(1, len(relation[0])+1):
        idx_list = list(itertools.combinations([i for i in range(1, len(relation[0])+1)], i)) # �ε��� ���� ����Ʈ
        ck_candidate_list = list(map(lambda x: list(itertools.combinations(x, i)), relation)) # i������ �÷����� ���� ���� ����Ʈ
        set_record_ck_candidate = list(map(lambda x: set(x), zip(*ck_candidate_list))) # ���� ����Ʈ�� �÷��������� ���� -> set ����
        each_count = list(map(lambda x: len(x), set_record_ck_candidate)) # idx_list[i]��� Ű���� ������ set���� ���ڵ��� ��

        for idx, count in enumerate(each_count):
            if count == row_count and not check_duplicated(idx_list[idx]):
                ck_list.append(idx_list[idx])
    return len(ck_list)