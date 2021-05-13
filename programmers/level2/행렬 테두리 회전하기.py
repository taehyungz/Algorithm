def solution(rows, columns, queries):
    board = [[i+1 for i in range(row_start, row_start+columns)] for row_start in range(0, rows*columns, columns)]
    ans = []
    for q in queries:
        y, x = q[0]-1, q[1]-1
        y2, x2 = q[2]-1, q[3]-1
        temp = board[y][x]
        minimum = temp
        
        for i in range(x2-x):
            temp2 = board[y][x+i+1]
            board[y][x+i+1] = temp
            minimum = min(temp, minimum)
            temp = temp2
            
        for i in range(y2-y):
            temp2 = board[y+i+1][x2]
            board[y+i+1][x2] = temp
            minimum = min(temp, minimum)
            temp = temp2
            
        for i in range(x2-x):
            temp2 = board[y2][x2-i-1]
            board[y2][x2-i-1] = temp
            minimum = min(temp, minimum)
            temp = temp2
            
        for i in range(y2-y):
            temp2 = board[y2-i-1][x]
            board[y2-i-1][x] = temp
            minimum = min(temp, minimum)
            temp = temp2
        
        ans.append(minimum)
    return ans