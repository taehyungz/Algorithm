def solution(n):
    strn = ""
    while n>0:
        strn += str(n%3)
        n //= 3
    ans = 0
    for idx, ch in enumerate(strn[::-1]):
        ans += int(ch)*(3**idx)
    return ans