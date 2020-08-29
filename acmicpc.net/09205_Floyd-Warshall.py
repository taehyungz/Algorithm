import sys

t = int(sys.stdin.readline().rstrip())

def Floyd():
    for i in range(n+2):
        for j in range(i+1,n+2):
            if i==j: continue
            distx = points[i][0]-points[j][0]
            disty = points[i][1]-points[j][1]
            dist = abs(distx)+abs(disty)
            if dist<=1000:
                connectivity[i][j] = True
                connectivity[j][i] = True
    for k in range(n+2):
        for i in range(n+2):
            for j in range(n+2):
                if i==j or i==k or j==k: continue
                if (not connectivity[i][j]) and (connectivity[i][k] and connectivity[k][j]):
                    connectivity[i][j] = True
while t>0:
    n = int(sys.stdin.readline().rstrip())
    points = []
    connectivity = []

    for i in range(n+2):
        connectivity.append([])
        for j in range(n+2):
            connectivity[i].append(False)
        connectivity[i][i]=True
    for i in range(n+2):
        # 좌표들 입력
        # 0-> 집, 1~n-> 편의점, n+1->공연장
        points.append(tuple(map(int,sys.stdin.readline().rstrip().split())))
    Floyd()
    if connectivity[0][n+1]: print("happy")
    else: print("sad")
    t -= 1