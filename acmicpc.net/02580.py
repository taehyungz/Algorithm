import sys

def examine(y, x):
    bitmask = "00000000000"
    starty = (y // 3) * 3
    startx = (x // 3) * 3
    for i in range(9):
        if board[y][i] > 0:
            bitmask = bitmask[:board[y][i]] + "1" + bitmask[board[y][i] + 1:]
        if board[i][x] > 0:
            bitmask = bitmask[:board[i][x]] + "1" + bitmask[board[i][x] + 1:]
        if board[starty + i // 3][startx + i % 3] > 0:
            bitmask = bitmask[:board[starty + i // 3][startx + i % 3]] + "1" + bitmask[board[starty + i // 3][startx + i % 3] + 1:]
    return [i for i in range(1,10) if bitmask[i]=="0"]

def dfs(level):
    global flag
    if flag:
        return
    if level == len(stack):
        for line in board:
            print(' '.join(map(str, line)))
        flag = True
        return
    y, x = stack[level]
    candidate = examine(y, x)

    for n in candidate:
        board[y][x] = n
        dfs(level+1)
        board[y][x] = 0

flag = False
board = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]
stack = [(y, x) for y in range(9) for x in range(9) if board[y][x] == 0]
dfs(0)
