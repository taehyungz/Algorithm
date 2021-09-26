def solution(m, n, puddles):
    record_map = [[0 for i in range(m)] for j in range(n)]
    record_map[0][0] = 1
    for now_y in range(n):
        for now_x in range(m):
            if [now_x+1,now_y+1] in puddles: continue
            if now_x > 0: record_map[now_y][now_x] = (record_map[now_y][now_x] + record_map[now_y][now_x-1]) % 1000000007
            if now_y > 0: record_map[now_y][now_x] = (record_map[now_y][now_x] + record_map[now_y-1][now_x]) % 1000000007
    return record_map[n-1][m-1]