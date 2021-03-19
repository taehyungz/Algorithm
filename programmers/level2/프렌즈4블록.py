def solution(m, n, board):    
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
        matched = []
        for y in range(m-1):
            for x in range(n-1):
                if board[y][x] == board[y][x+1] == board[y+1][x] == board[y+1][x+1] != '#': matched.append([y,x])
        for y,x in matched:
            board[y][x] = board[y+1][x] = board[y][x+1] = board[y+1][x+1] = '#'
            
        if not matched:
            break
        arrange()
    ans = 0
    for y in range(m):
        for x in range(n):
            if board[y][x] == '#': ans += 1
    return ans