def solution(prices):
    answer = [0] * len(prices)
    stack = []
    for time, pr in enumerate(prices):
        while stack and prices[stack[-1]] > pr: #���� ���� �ִ� ���ݺ��� �� ���� ������ ���� ���ݿ� ������
            #�ֽ� ������ ���� �� ������ �������ݺ��� �϶���
			temp_time = stack.pop() #���� ������ ���Դ� �ð�
            answer[temp_time] = time - temp_time
			#stack�� top�� ���� ��� ���� ������, �� for������ �˻��ϱ� �����̴�.
        stack.append(time)
    while stack:
        temp_time = stack.pop()
        answer[temp_time] = len(prices) - temp_time - 1
    return answer