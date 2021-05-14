def solution(n, s):
    if s//n == 0: return [-1]
    diff = s - s//n * n
    answer = [s//n for _ in range(n-diff)]
    
    if diff != 0: answer.extend([s//n+1 for _ in range(diff)])
    
    return answer