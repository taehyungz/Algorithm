from itertools import permutations
import math

def solution(n, k):
    def fill_factorials(n):
        idx = 1
        while idx <= n:
            factorials.append(factorials[idx-1] * idx)
            idx += 1

    answer, factorials, cand = [], [1], [i for i in range(1, n+1)]
    fill_factorials(n)

    while n >= 1:
        idx = math.ceil(k / factorials[n-1])
        answer.append(cand[idx-1])
        cand.pop(idx-1)
        k -= math.floor(k / factorials[n-1]) * factorials[n-1]
        n -= 1
    return answer