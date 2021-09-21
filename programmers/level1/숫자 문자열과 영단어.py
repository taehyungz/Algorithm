def solution(s):
    word_dic = {
        'zero': '0', 'one': '1', 'two': '2', 'three': '3', 'four': '4',
        'five': '5', 'six': '6', 'seven': '7', 'eight': '8', 'nine': '9'
    }
    split_list = []
    start_idx = 0
    for i in range(len(s)):
        if s[i].isnumeric(): 
            split_list.append(s[i])
            start_idx = i + 1
        elif s[start_idx:i+1] in word_dic:
            split_list.append(word_dic[s[start_idx:i+1]])
            start_idx = i + 1
    return int(''.join(split_list))