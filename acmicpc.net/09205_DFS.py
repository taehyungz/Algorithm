import sys

t = int(sys.stdin.readline().rstrip())

def DFS(nowx, nowy, visit_idx):
    visit[visit_idx] = True
    for i in range(n+2):
        if not visit[i]:
            diffx = abs(points[i][0]-nowx)
            diffy = abs(points[i][1]-nowy)
            if diffx+diffy <= 1000:
                DFS(points[i][0],points[i][1],i)

while t>0:
    n = int(sys.stdin.readline().rstrip())
    points = []
    visit = []
    for i in range(n+2):
        visit.append(False)
    for i in range(n+2):
        # 좌표들 입력
        # 0-> 집, 1~n-> 편의점, n+1->공연장
        points.append(tuple(map(int,sys.stdin.readline().rstrip().split())))
    DFS(points[0][0], points[0][1], 0)
    if visit[n+1]==True:
        print("happy")
    else:
        print("sad")
    t -= 1