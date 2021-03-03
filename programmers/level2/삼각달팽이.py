def solution(n):
    posy = posx = 0 #현재 위치
    total = (n+1)*n // 2 #블록 개수
    cnt = 1 #수
    idx = 0 #배열 인덱스
    ans = [0 for i in range((n+1)*n//2)] #배열
    round_cnt = n #해당 라운드에 채울 수 개수
    while cnt <= total:
        round_cnt, temp = round_cnt-1, round_cnt
        while temp>0: #아래로
            idx = (posy+1)*posy//2 + posx
            ans[idx] = cnt
            posy, cnt, temp = posy+1, cnt+1, temp-1
        posy, posx = posy-1, posx+1
        round_cnt, temp = round_cnt-1, round_cnt
        
        while temp>0: #오른쪽으로
            idx = (posy+1)*posy//2 + posx
            ans[idx] = cnt
            posx, cnt, temp = posx+1, cnt+1, temp-1
        round_cnt, temp = round_cnt-1, round_cnt
        posy, posx = posy-1, posx-2
        
        while temp>0: #위쪽으로
            idx = (posy+1)*posy//2 + posx
            ans[idx] = cnt
            posy, posx, cnt, temp = posy-1, posx-1, cnt+1, temp-1
        posy, posx = posy+2, posx+1
    return ans