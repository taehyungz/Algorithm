from collections import defaultdict
import sys


def solution(n, wires):
    def visit(node, from_node):
        connected_list, cnt = tree[node], 1
        for n in connected_list:
            if n == from_node: continue
            cnt += visit(n, node)
        return cnt

    def get_size_of_split_tree(cut_from, cut_to):
        connected_list = tree[cut_from]
        # 여기서 cut_to를 끊는다
        cnt = 1
        for n in connected_list:
            if n == cut_to: continue
            cnt += visit(n, cut_from)
        return cnt

    answer = sys.maxsize
    tree = defaultdict(set)

    for wire in wires:
        tree[wire[0]].add(wire[1])
        tree[wire[1]].add(wire[0])

    for cut_from in range(1, n + 1):
        for cut_to in range(cut_from + 1, n + 1):
            if cut_to not in tree[cut_from]: continue
            # i <-> j를 자름
            size_of_oneside = get_size_of_split_tree(cut_from, cut_to)
            answer = min(answer, abs(n - 2 * size_of_oneside))
    return answer