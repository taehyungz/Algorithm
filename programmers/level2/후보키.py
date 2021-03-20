import itertools

def solution(relation):
    def examine(idxs): #최소키 여부 검사
        for key in key_idx: #키로 판별된 것들 중에서
            check = False
            for part_key in key: #검사해서 키로 판별된 것을 완전히 포함하면 최소키 아님
                if part_key not in idxs: #최소키 가능성 있음
                    check = True
            if not check: return False #모든 검사 통과하면 최소키임
        return True
    
    len_rel = len(relation[0])
    key_idx = set()
    idx_list = list(range(len_rel)) #idx 후보들
    for length in range(1,len_rel+1):
        idx_arr = tuple(itertools.combinations(idx_list, length)) #조합 인덱스들
        temp_rel = list(zip(*relation)) #로우로 묶기
        for idxs in idx_arr:
            ls = []
            for i in idxs: #로우로 묶은 배열에서 조합 인덱스에 있는 내용들을 선택
                ls.append(temp_rel[i])
            final_rel = list(zip(*ls))
            if len(list(set(final_rel))) == len(final_rel) and examine(idxs):
                key_idx.add(idxs)
    return len(key_idx)