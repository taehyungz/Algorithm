def solution(m, n, board):
    def expand(y,x, ch):
        board[y][x] = board[y+1][x] = board[y][x+1] = board[y+1][x+1] = "#"
        if x+2<n and y+1<m and board[y][x+2] == board[y+1][x+2] and board[y][x+2] == ch: expand(y, x+1, ch)
        if x+2<n and y+2<m and board[y+1][x+2] == board[y+2][x+2] and board[y+2][x+1]==board[y+1][x+2] and board[y+1][x+2]==ch: expand(y+1, x+1, ch)
        if y+2<m and x+1<n and board[y+2][x]==board[y+2][x+1] and board[y+2][x]==ch: expand(y+1, x, ch)
        if y+2<m and x-1>=0 and board[y+2][x]==board[y+2][x-1] and board[y+1][x-1]==board[y+2][x] and board[y+2][x]==ch: expand(y+1,x-1,ch)
        if y+1<m and x-1>=0 and board[y][x-1]==board[y+1][x-1] and board[y][x-1]==ch: expand(y,x-1,ch)
    
    def arrange():
        for x in range(n):
            ypos = last = m-1
            while ypos>=0:
                if board[ypos][x]=='#':
                    ypos -= 1
                    continue
                board[last][x] = board[ypos][x]
                if last!=ypos: board[ypos][x] = '#'
                ypos -= 1
                last -= 1
    
    board = [[board[y][x] for x in range(n)] for y in range(m)]
    while True:
        check = True
        for y in range(m-1):
            for x in range(n-1):
                if board[y][x]!="#" and board[y][x]==board[y][x+1] and board[y+1][x] == board[y+1][x+1] and board[y][x] == board[y+1][x]:
                    check = False
                    expand(y,x,board[y][x])
        arrange()
        if check:
            break
    ans = 0
    for y in range(m):
        for x in range(n):
            if board[y][x] == '#': ans += 1
    return ans