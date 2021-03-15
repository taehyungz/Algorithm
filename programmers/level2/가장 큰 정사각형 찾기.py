def solution(board):
    for y in range(1, len(board)):
        for x in range(1, len(board[0])):
            if board[y][x] >= 1:
                board[y][x] = min(board[y][x-1],board[y-1][x],board[y-1][x-1])+1
    return max([num for row in board for num in  row])**2