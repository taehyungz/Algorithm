def solution(brown, yellow):
    y_wh = (brown-4)//2 #노란색의 둘레 길이//2
    for y_w in range(y_wh, 0, -1): #가로*세로 = 개수
        y_h = y_wh - y_w
        if y_h*y_w == yellow:
            return [y_w+2, y_h+2] 