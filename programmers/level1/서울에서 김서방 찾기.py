def solution(seoul):
    idx = 0
    for i,s in enumerate(seoul):
        if s=="Kim": idx=i
    return "김서방은 "+str(idx)+"에 있다"