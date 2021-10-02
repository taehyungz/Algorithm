def solution(sizes):
    row_with_col = list(zip(*(map(lambda x: [max(x), min(x)], sizes))))
    return max(row_with_col[0]) * max(row_with_col[1])