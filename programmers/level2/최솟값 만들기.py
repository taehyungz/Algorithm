def solution(A,B):
    A = sorted(A)
    B = sorted(B, reverse = True)
    total = 0
    for a, b in zip(A, B): #큰 수 * 작은 수
        total += a*b
    return total