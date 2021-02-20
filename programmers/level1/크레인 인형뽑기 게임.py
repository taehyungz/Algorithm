import collections
def solution(board, moves):
    st_board = [collections.deque() for i in range(len(board))]
    stack = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j]: st_board[j].appendleft(board[i][j])
    box = []
    cnt = 0
    print(st_board)
    for mv in moves:
        if len(st_board[mv-1])>0:
            box.append(st_board[mv-1].pop())
        
        if len(box)>1 and box[-1]==box[-2]:
            cnt += 2
            box.pop()
            box.pop()
    return cnt