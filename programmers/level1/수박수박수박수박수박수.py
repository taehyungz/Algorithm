def solution(n):
    answer = "����"
    answer *= n//2
    return answer if n%2==0 else answer+"��"