import collections
import heapq
def solution(N, stages):
    stage_cleared = collections.defaultdict(int)
    stage_visited_non_cleared = collections.defaultdict(int)
    failure = []
    ans = []
    
    for st in stages:
        stage_cleared[st-1] += 1
    for level in range(N, -1, -1):
        stage_cleared[level] += stage_cleared[level+1]
    for level in range(1, N+1):
        stage_visited_non_cleared[level] = max(0,stage_cleared[level-1] - stage_cleared[level])
        if stage_cleared[level-1]!=0: heapq.heappush(failure, (-stage_visited_non_cleared[level]/stage_cleared[level-1], level))
        else: heapq.heappush(failure, (0, level))
    
    while failure:
        ans.append(heapq.heappop(failure)[1])
    return ans