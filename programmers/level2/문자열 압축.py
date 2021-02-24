def solution(s):
    answer = []
    for n_repeated in range(1, len(s)//2+1):
        check = True
        sliced_s = [s[i:i+n_repeated] for i in range(0, len(s), n_repeated)]
        repeated_cnt = 1
        each_string = []
        for idx in range(1,len(sliced_s)):
            if sliced_s[idx-1]==sliced_s[idx]:
                repeated_cnt += 1
            elif repeated_cnt == 1:
                each_string.append(sliced_s[idx-1])
            else:
                each_string.append(str(repeated_cnt))
                each_string.append(sliced_s[idx-1])
                repeated_cnt = 1
        if repeated_cnt>1:
            each_string.append(str(repeated_cnt))
        each_string.append(sliced_s[-1])
        local_string = ''.join(each_string)
        answer.append(len(local_string))
    return min(answer) if len(answer)>0 else 1 #s가 한 글자이면 for문에 들어가지 못해서 min()을 적용할 수 없다