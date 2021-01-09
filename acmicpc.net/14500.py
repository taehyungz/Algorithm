import sys

N, M = map(int, input().split())
blocks = []
for i in range(N):
    blocks.append(list(map(int, sys.stdin.readline().split())))

max_score = 0
visited = [[False] * M for i in range(N)]


def dfs(y, x, cnt, hap):
    global blocks
    global N
    global M
    global max_score

    if cnt == 4:
        max_score = max(max_score, hap)
        return
    visited[y][x] = True
    #if y-1 >= 0 and not visited[y-1][x]: dfs(y-1, x, cnt+1, hap+blocks[y-1][x])
    if y+1 < N and not visited[y+1][x]: dfs(y+1, x, cnt+1, hap+blocks[y+1][x])
    if x+1 < M and not visited[y][x+1]: dfs(y, x+1, cnt+1, hap+blocks[y][x+1])
    if x-1 >= 0 and not visited[y][x-1]: dfs(y, x-1, cnt+1, hap+blocks[y][x-1])
    visited[y][x] = False


for i in range(N):
    for j in range(M):
        if j==4:
            p=1
        dfs(i, j, 1, blocks[i][j])
for i in range(N):
    for j in range(M):
        if i+1<N and j+2<M:
            max_score = max(max_score, blocks[i][j]+blocks[i][j+1]+blocks[i][j+2]+blocks[i+1][j+1],
                            blocks[i+1][j]+blocks[i+1][j+1]+blocks[i+1][j+2]+blocks[i][j+1])
        if i+2<N and j+1<M:
            max_score = max(max_score, blocks[i][j]+blocks[i+1][j]+blocks[i+2][j]+blocks[i+1][j+1],
                            blocks[i][j+1]+blocks[i+1][j+1]+blocks[i+2][j+1]+blocks[i+1][j])

print(max_score)