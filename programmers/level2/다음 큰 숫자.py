def solution(n):
    def find_n(number, cnt): #n+1부터 탐색
        while True:
            if get_bin_one_cnt(number)==cnt: return number
            else: number += 1
    def get_bin_one_cnt(n): #이진수에서 1개수 세기
        binnum = bin(n)[2:]
        cnt = binnum.count('1')
        return cnt
    
    return find_n(n+1, get_bin_one_cnt(n))