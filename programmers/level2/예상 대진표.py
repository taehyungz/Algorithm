def solution(n,a,b):
    rnd = 0
    while a != b:
        a = (a+1)//2
        b = (b+1)//2
        rnd += 1
        # a=2, b=3�� ��� ���� ����
        # a=3, b=4�� ��� ���� ����
    
    return rnd