def solution(s, n):
    ans = ""
    for ch in s:
        if ch==" ": ans += ch
        elif ord('A') <= ord(ch) <= ord('Z') and ord(ch)+n>ord('Z'): ans += chr(ord(ch)+n-ord('Z')+ord('A')-1)
        elif ord('a') <= ord(ch) <= ord('z') and ord(ch)+n>ord('z'): ans += chr(ord(ch)+n-ord('z')+ord('a')-1)
        else: ans += chr(ord(ch)+n)
    return ans