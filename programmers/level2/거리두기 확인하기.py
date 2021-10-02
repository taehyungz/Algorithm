def solution(places):
    def check(place):
        for y in range(len(place)):
            for x in range(len(place[0])):
                if place[y][x] == 'P':
                    for i in range(4):
                        #거리 1
                        next_y, next_x = y + move_y[i], x + move_x[i]
                        if 0 <= next_y < len(place) and 0 <= next_x < len(place[0]) and place[next_y][next_x] == 'P':
                            return 0
                        #거리 2, 직선
                        next_y2, next_x2 = y + move_y[i]*2, x + move_x[i]*2
                        if 0 <= next_y2 < len(place) and 0 <= next_x2 < len(place[0]) and place[next_y2][next_x2] == 'P' and place[next_y][next_x] != 'X':
                            return 0
                        #거리 2, 대각선
                        next_y2, next_x2 = y + move_y2[i], x + move_x2[i]
                        if 0 <= next_y2 < len(place) and 0 <= next_x2 < len(place[0]) and place[next_y2][next_x2] == 'P':
                            for j in range(2):
                                ptt_y, ptt_x = y + partitions[i][j][0], x + partitions[i][j][1]
                                if place[ptt_y][ptt_x] != 'X':
                                    return 0
        return 1
    ans = []
    move_y, move_x = [0,0,1,-1], [1,-1,0,0]
    move_y2, move_x2 = [1,1,-1,-1], [1, -1, 1, -1]
    partitions = [[(1,0), (0,1)], [(0,-1),(1,0)], [(-1,0),(0,1)], [(-1,0),(0,-1)]]
    for idx, place in enumerate(places):
        ans.append(check(place))
    return ans