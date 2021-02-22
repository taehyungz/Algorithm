def solution(prices):
    answer = [0] * len(prices)
    stack = []
    for time, pr in enumerate(prices):
        while stack and prices[stack[-1]] > pr: #지금 보고 있는 가격보다 더 높은 가격이 과거 가격에 있으면
            #주식 가격이 과거 한 시점의 관찰가격보다 하락함
			temp_time = stack.pop() #높은 가격이 나왔던 시간
            answer[temp_time] = time - temp_time
			#stack의 top만 봐도 상관 없는 이유는, 매 for문마다 검사하기 때문이다.
        stack.append(time)
    while stack:
        temp_time = stack.pop()
        answer[temp_time] = len(prices) - temp_time - 1
    return answer