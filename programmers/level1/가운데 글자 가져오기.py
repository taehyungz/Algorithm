def solution(s):
    lens = len(s)
    return s[lens//2] if lens%2==1 else s[lens//2-1:lens//2+1]