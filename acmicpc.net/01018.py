def chess_check(chess, last, cnt, starty, startx):
    for i in range(starty, starty+8):
        for j in range(startx, startx+8):
            if chess[i][j] != last:
                last = chess[i][j]
                continue
            else:
                if chess[i][j]==block[0]:
                    last=block[1]
                    cnt+=1
                else:
                    last=block[0]
                    cnt+=1
        if last==block[0]: last=block[1]
        else: last=block[0]
    return cnt
a, b = map(int, input().split())
chess = list()
block = ['W','B']
for i in range(a):
    chess.append([])
    chess[i] = input()
case1 = 0
case2 = 0
ans = 64
for i in range(0,a-7):
    for j in range(0, b-7):
        case1 = chess_check(chess, 'W', 0, i, j)
        if ans>case1: ans=case1
        case2 = chess_check(chess, 'B', 0, i, j)
        if ans>case2: ans=case2
print(ans)