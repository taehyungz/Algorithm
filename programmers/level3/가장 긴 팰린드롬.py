def solution(s):
    for size in range(len(s), 0, -1):
        for start in range(len(s)-size+1):
            if s[start:start+size] == s[start+size-1:start:-1]+s[start]:
                return size