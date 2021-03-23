import collections

def solution(msg):
    dic = collections.defaultdict(int)
    ch = 'A'
    max_dic_idx = 26
    ans = []
    for i in range(1, 27):
        dic[ch] = i
        ch = chr(ord(ch)+1)
    idx = 0
    check = 0
    while idx<len(msg):
        temp_idx = idx+1
        while temp_idx <= len(msg) and dic[msg[idx:temp_idx]] != 0: #temp_idx는 len(msg)와 같을 때까지
            temp_idx += 1
        ans.append(dic[msg[idx:temp_idx-1]])
        max_dic_idx += 1
        dic[msg[idx:temp_idx]] = max_dic_idx
        idx = temp_idx-1
        check += 1
    
    return ans