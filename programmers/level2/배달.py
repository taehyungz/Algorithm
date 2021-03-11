import collections
import sys

def solution(N, road, K):
    dic = collections.defaultdict(collections.deque)
    for road_info in road:
        dic[road_info[0]].append((road_info[1], road_info[2]))
        dic[road_info[1]].append((road_info[0], road_info[2]))
    
    queue = collections.deque()
    time_check = collections.defaultdict(lambda: sys.maxsize)
    queue.append((1,0))
    ans = set()
    while queue:
        dest, time = queue.popleft()
        ans.add(dest)
        time_check[dest] = min(time_check[dest], time)
        for info in dic[dest]:
            if time+info[1] <= K and time_check[info[0]] > time+info[1]:
                queue.append((info[0], time+info[1]))
    return len(ans)