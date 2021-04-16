import datetime as dt

def solution(lines):
    answer = 0
    log_converted = []
    for line in lines:
        idx = line.rfind(' ')
        temp_end_time = line[:idx]
        end_time = dt.datetime.strptime(temp_end_time, "%Y-%m-%d %H:%M:%S.%f")
        during_time = line[idx+1:-1]
        start_time = end_time - dt.timedelta(seconds=float(during_time)) + dt.timedelta(seconds=0.001)
        check_time = end_time + dt.timedelta(seconds=0.999)
        #���۽ð��� ���ð�+0.999�ʸ� ���� �迭�� �ִ´�.
        #1�ʵ����� �ִ� ��û ���� ���Ƿ�, ó������ ���ð� + 0.999�ʸ� �ִ´�.
        #���۽ð��̾����� ���� ����+1��, ���ð�+0.999�ʿ����� ���� ����-1�� �Ѵ�.
        log_converted.append((start_time, 1)) #�ð�
        log_converted.append((check_time, 2)) #��
    
    log_converted.sort(key = lambda x: (x[0], x[1]))
    temp_answer = 0
    for i in range(len(log_converted)):
        if log_converted[i][1] == 1:
            temp_answer += 1
        else:
            temp_answer -= 1
        
        answer = max(answer, temp_answer)
    return answer