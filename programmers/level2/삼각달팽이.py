def solution(n):
    posy = posx = 0 #���� ��ġ
    total = (n+1)*n // 2 #��� ����
    cnt = 1 #��
    idx = 0 #�迭 �ε���
    ans = [0 for i in range((n+1)*n//2)] #�迭
    round_cnt = n #�ش� ���忡 ä�� �� ����
    while cnt <= total:
        round_cnt, temp = round_cnt-1, round_cnt
        while temp>0: #�Ʒ���
            idx = (posy+1)*posy//2 + posx
            ans[idx] = cnt
            posy, cnt, temp = posy+1, cnt+1, temp-1
        posy, posx = posy-1, posx+1
        round_cnt, temp = round_cnt-1, round_cnt
        
        while temp>0: #����������
            idx = (posy+1)*posy//2 + posx
            ans[idx] = cnt
            posx, cnt, temp = posx+1, cnt+1, temp-1
        round_cnt, temp = round_cnt-1, round_cnt
        posy, posx = posy-1, posx-2
        
        while temp>0: #��������
            idx = (posy+1)*posy//2 + posx
            ans[idx] = cnt
            posy, posx, cnt, temp = posy-1, posx-1, cnt+1, temp-1
        posy, posx = posy+2, posx+1
    return ans