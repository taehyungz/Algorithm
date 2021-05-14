def solution(left, right):
    def cnt_yak(number):
        cnt = 1
        for i in range(1, number//2+1):
            if number % i == 0:
                cnt += 1
        return cnt
    
    answer = 0
    for i in range(left, right+1):
        cnt = cnt_yak(i)
        if cnt % 2 == 0:
            answer += i
        else:
            answer -= i
    return answer