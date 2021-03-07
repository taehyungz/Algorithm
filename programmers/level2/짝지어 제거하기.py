def solution(s):
    sarr = list(s)
    stack = []
    idx = 0
    for ch in sarr:
        if stack and stack[-1] == ch:
            stack.pop()
        else: stack.append(ch)
    return 1 if not stack else 0