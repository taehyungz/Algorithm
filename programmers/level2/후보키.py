import itertools

def solution(relation):
    def check_duplicated(candidate_combination_key):
        for ck in ck_list: # 각 후보키에 대해
            duplicated = True
            for splited_key in ck: # 후보키의 각 원소들이
                if splited_key not in candidate_combination_key: duplicated = False # 모두 이번 예비키에 있으면 후보키가 아니다
            if duplicated: return True
        return False
                
    row_count = len(relation)
    ck_list = []
    for i in range(1, len(relation[0])+1):
        idx_list = list(itertools.combinations([i for i in range(1, len(relation[0])+1)], i)) # 인덱스 집합 리스트
        ck_candidate_list = list(map(lambda x: list(itertools.combinations(x, i)), relation)) # i개씩의 컬럼으로 묶은 집합 리스트
        set_record_ck_candidate = list(map(lambda x: set(x), zip(*ck_candidate_list))) # 위의 리스트를 컬럼기준으로 묶음 -> set 적용
        each_count = list(map(lambda x: len(x), set_record_ck_candidate)) # idx_list[i]대로 키집합 설정시 set적용 레코드의 수

        for idx, count in enumerate(each_count):
            if count == row_count and not check_duplicated(idx_list[idx]):
                ck_list.append(idx_list[idx])
    return len(ck_list)