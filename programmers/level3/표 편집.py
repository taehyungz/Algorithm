def solution(n, k, cmd):
    node_list = {i: [i-1, i+1] for i in range(n)}
    node_list[n-1][1] = -1 # -1은 None을 가리키는 노드
    recycle_bin, answer, cur = [], ["O" for i in range(n)], k

    for c in cmd:
        if c == 'C':
            answer[cur] = "X"
            recycle_bin.append(cur)

            prev_v = node_list[cur][0]
            next_v = node_list[cur][1]

            if prev_v != -1:
                node_list[prev_v][1] = next_v
            if next_v != -1:
                node_list[next_v][0] = prev_v
                cur = next_v
            else:
                cur = prev_v
        elif c == 'Z':
            to_recover = recycle_bin.pop()
            answer[to_recover] = "O";

            prev_v = node_list[to_recover][0]
            next_v = node_list[to_recover][1]

            if prev_v != -1:
                node_list[prev_v][1] = to_recover
            if next_v != -1:
                node_list[next_v][0] = to_recover
        else:
            com, move_count = c.split()
            move_count = int(move_count)
            for i in range(move_count):
                cur = node_list[cur][1] if com == 'D' else node_list[cur][0]
    return ''.join(answer)