import itertools

def solution(k, dungeons):
    def explore_dungeons(k, permutation):
        cnt = 0
        for dungeon in permutation:
            if dungeon[0] <= k:
                k -= dungeon[1]
                cnt += 1
        return cnt
    
    cnt, permutation_list = 0, itertools.permutations(dungeons)
    for permutation in permutation_list:
        cnt = max(cnt, explore_dungeons(k, permutation))
    return cnt