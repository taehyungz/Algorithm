def solution(x):
    sumeach = 0
    for ch in str(x):
        sumeach += int(ch)
    return x%sumeach == 0
        