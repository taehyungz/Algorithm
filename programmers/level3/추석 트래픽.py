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
        #시작시간과 끝시간+0.999초를 같은 배열에 넣는다.
        #1초동안의 최대 요청 수를 세므로, 처음부터 끝시간 + 0.999초를 넣는다.
        #시작시간이었으면 현재 개수+1을, 끝시간+0.999초였으면 현재 개수-1을 한다.
        log_converted.append((start_time, 1)) #시간
        log_converted.append((check_time, 2)) #끝
    
    log_converted.sort(key = lambda x: (x[0], x[1]))
    temp_answer = 0
    for i in range(len(log_converted)):
        if log_converted[i][1] == 1:
            temp_answer += 1
        else:
            temp_answer -= 1
        
        answer = max(answer, temp_answer)
    return answer