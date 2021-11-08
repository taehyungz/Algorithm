def solution(grid):
    def get_cycle(y, x, i):
        cnt = 0
        while True:
            if is_visited[y][x][i]: return cnt
            cnt += 1
            is_visited[y][x][i] = True

            if grid[y][x] == 'R': i = (4 + i + 1) % 4
            elif grid[y][x] == 'L': i = (4 + i - 1) % 4
            y, x = (len(grid) + y + move_y[i]) % len(grid), (len(grid[0]) + x + move_x[i]) % len(grid[0])
            
    answer = []
    move_y, move_x = [1,0,-1,0], [0,-1,0,1]
    is_visited = [[[False for i in range(4)] for j in range(len(grid[0]))] for k in range(len(grid))]
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            for i in range(4):
                if not is_visited[y][x][i]: answer.append(get_cycle(y, x, i))
    return sorted(answer)