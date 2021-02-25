import collections
def solution(record):
    answer = []
    name_dic = collections.defaultdict(str) #uid에 따른 이름
    for rc in record:
        rc_arr = rc.split()
        if rc_arr[0]=="Enter": #Enter uid name
            answer.append([rc_arr[1],"님이 들어왔습니다."])
            name_dic[rc_arr[1]] = rc_arr[2]
        elif rc_arr[0]=="Leave": #Leave uid
            answer.append([rc_arr[1],"님이 나갔습니다."])
        else: #Change uid name
            name_dic[rc_arr[1]] = rc_arr[2]
    
    for idx, mes in enumerate(answer):
        answer[idx] = name_dic[mes[0]]+mes[1]
    return answer