def solution(d, budget):
    total = 0
    for idx, n in enumerate(sorted(d)):
        total += n
        if total>budget: return idx
    return len(d)