import collections

def solution(numbers):
    answer = []
    counter = collections.Counter
    for number in numbers:
        bin_num = list(bin(number)[2:])
        cnt1 = counter(bin_num)
        mc_0, mc_1 = cnt1['0'], cnt1['1']
        if mc_0 >= 1:
            for idx in range(len(bin_num)-1, -1, -1):
                if bin_num[idx] == '0':
                    bin_num[idx] = '1'
                    if idx != len(bin_num)-1:
                        bin_num[idx+1] = '0'
                    answer.append(int('0b' + ''.join(bin_num), 2))
                    break
        else:
            bin_num2 = '0b10'+'1'*(len(bin_num)-1)
            answer.append(int(bin_num2, 2))
            
    return answer