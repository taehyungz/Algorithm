from collections import defaultdict

def solution(gems):
    answer, unique_gem_count, gem_count_map = [], len(set(gems)), defaultdict(int)
    end, max_window_size = 0, len(gems) + 2

    for start, gem in enumerate(gems):
        while len(gem_count_map) != unique_gem_count and end < len(gems):
            gem_count_map[gems[end]] += 1
            end += 1
        if len(gem_count_map) == unique_gem_count and end - start + 1 < max_window_size:
            max_window_size = end - start + 1
            answer = [start+1, end]
        gem_count_map[gem] -= 1
        if gem_count_map[gem] == 0:
            del(gem_count_map[gem])

    return answer