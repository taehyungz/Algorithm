def solution(weights, head2head):
    def get_win_heavier(idx):
        cnt = 0
        for i in range(len(weights)):
            if weights[i] > weights[idx] and head2head[idx][i] == 'W': cnt += 1
        return cnt
    
    answer = []
    for i in range(len(weights)):
        win_cnt, lose_cnt = head2head[i].count('W'), head2head[i].count('L')
        win_ratio = 0
        if win_cnt + lose_cnt != 0: win_ratio = win_cnt / (win_cnt + lose_cnt)
        answer.append((win_ratio, get_win_heavier(i), weights[i], i+1))
    return list(map(lambda x: x[3], sorted(answer, key = lambda x: (-x[0], -x[1], -x[2], x[3]))))