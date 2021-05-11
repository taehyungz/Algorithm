import collections

def solution(lottos, win_nums):
    dic = collections.defaultdict(int)
    for n in win_nums:
        dic[n] = 1
    zero_cnt = 0
    hit = 0
    for n in lottos:
        if n==0: zero_cnt += 1
        elif dic[n] == 1:
            hit += 1
    max_hit = hit + zero_cnt
    min_hit = hit
    max_rank = 7-max_hit
    min_rank = 7-min_hit
    if max_rank > 6: max_rank = 6
    if min_rank > 6: min_rank = 6
    return [max_rank, min_rank]