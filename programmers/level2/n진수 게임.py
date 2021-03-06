import collections

def solution(n, t, m, p):
    def get_number(number, n):
        arr = collections.deque()
        while number>0:
            input_n = number % n
            if input_n>9:
                input_n = hexarr[input_n-10]
                
            arr.appendleft(str(input_n))
            number //= n
        return ''.join(arr) if len(arr)>0 else "0"        
    
    hexarr = ['A','B','C','D','E','F']
    answer = []
    number = 0
    idx = 0
    
    while len(answer) != t:
        num_str = get_number(number, n)
        for each_num in num_str:
            idx += 1 # idx - each_num
            if idx%m == p%m:
                answer.append(each_num)
            if len(answer) == t: break
        number += 1
    return ''.join(answer)