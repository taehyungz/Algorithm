def solution(seoul):
    idx = 0
    for i,s in enumerate(seoul):
        if s=="Kim": idx=i
    return "�輭���� "+str(idx)+"�� �ִ�"