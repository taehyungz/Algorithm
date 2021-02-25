import collections
def solution(record):
    answer = []
    name_dic = collections.defaultdict(str) #uid�� ���� �̸�
    for rc in record:
        rc_arr = rc.split()
        if rc_arr[0]=="Enter": #Enter uid name
            answer.append([rc_arr[1],"���� ���Խ��ϴ�."])
            name_dic[rc_arr[1]] = rc_arr[2]
        elif rc_arr[0]=="Leave": #Leave uid
            answer.append([rc_arr[1],"���� �������ϴ�."])
        else: #Change uid name
            name_dic[rc_arr[1]] = rc_arr[2]
    
    for idx, mes in enumerate(answer):
        answer[idx] = name_dic[mes[0]]+mes[1]
    return answer