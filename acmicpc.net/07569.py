import sys
import collections
def BFS():
    moveh = [0,0,0,0,1,-1]
    movey = [0,0,1,-1,0,0]
    movex = [1,-1,0,0,0,0]
    readys.append((500,500,500)) #500,500,500은 절대 들어갈 수 없는 수
    days = 0
    while len(readys):
        h, y, x = readys.popleft()
        if h==500 and y==500 and x==500:
            days += 1
            readys.append((500,500,500))
            continue
        tomatos[h][y][x] = 1
        for i in range(6):
            newh = h+moveh[i]
            newy = y+movey[i]
            newx = x+movex[i]
            if newh >= 0 and newh < H and newy >= 0\
                    and newy < N and newx >= 0 and newx < M\
                    and tomatos[newh][newy][newx]==0:
                tomatos[newh][newy][newx] = 1
                readys.append((newh,newy,newx))
        if len(readys)==1: return days

def Check(x):
    for h in range(H):
        for n in range(N):
            for m in range(M):
                if tomatos[h][n][m] == 0:
                    print("-1")
                    return
    print(x)
    return
M, N, H = map(int, sys.stdin.readline().rstrip().split()) # x, y, h
readys = collections.deque()
tomatos = []
for h in range(H):
    tomatos.append([])
    for n in range(N):
        tomatos[h].append([])
        ls = list(map(int, sys.stdin.readline().rstrip().split()))
        for m in range(M):
            tomatos[h][n].append(ls[m])
            if tomatos[h][n][m] == 1: readys.append((h, n, m))

Check(BFS())