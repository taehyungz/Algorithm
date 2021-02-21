def solution(n):
    answer = "¼ö¹Ú"
    answer *= n//2
    return answer if n%2==0 else answer+"¼ö"