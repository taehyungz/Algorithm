import collections

def solution(maps):
    answer = 0
    queue = collections.deque()
    queue.append((0,0,1))
    setpos = set()
    setpos.add((0,0))
    movex = [1,0,0,-1]
    movey = [0,1,-1,0]
    while queue:
        pos_y, pos_x, now_cnt = queue.popleft()
        for i in range(4):
            next_y, next_x = pos_y+movey[i], pos_x+movex[i]
            if next_x==len(maps[0])-1 and next_y==len(maps)-1: return now_cnt+1
            if 0<=next_x<len(maps[0]) and 0<=next_y<len(maps) and maps[next_y][next_x]!=0 and (next_y,next_x) not in setpos:
                queue.append((next_y,next_x, now_cnt+1))
                setpos.add((next_y, next_x))
    
    return -1