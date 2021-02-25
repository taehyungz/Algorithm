def solution(s):
    cnt = 0
    for ch in s: #괄호의 개수를 세서 판단한다
        if ch == '(': cnt += 1
        else: cnt -= 1
        if cnt<0: return False
    return True if cnt==0 else False