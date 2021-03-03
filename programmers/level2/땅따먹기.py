def solution(land):
    for line in range(1,len(land)):
        for now_idx in range(4):
            temp = land[line][now_idx]
            for upper_idx in range(4):
                if now_idx != upper_idx:
                    temp = max(temp, land[line-1][upper_idx]+land[line][now_idx])
            land[line][now_idx] = temp
    return max(land[len(land)-1])