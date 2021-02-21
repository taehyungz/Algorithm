def solution(s):
    ans = ""
    for word in s.lower().split(' '):
        for idx, ch in enumerate(word):
            if idx%2==0: ans += ch.upper()
            else: ans += ch
        ans += ' '
    return ans[:-1]
    