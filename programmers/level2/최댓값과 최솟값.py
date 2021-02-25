def solution(s):
    sarr = list(map(int, s.split()))
    return str(min(sarr))+" "+str(max(sarr))