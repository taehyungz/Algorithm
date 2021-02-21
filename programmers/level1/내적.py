def solution(a, b):
    for idx, n in enumerate(b):
        a[idx] *= n
    return sum(a)