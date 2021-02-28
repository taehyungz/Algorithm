import collections
import math
def solution(str1, str2):
    def get_jacquard(arr1, arr2):
        c1 = collections.Counter(arr1)
        c2 = collections.Counter(arr2)
        c3 = c1 - c2 + c2 # Counter객체는 음수인 것에 대해 자동으로 지운다. 따라서 A 합집합 B를 구할 수 있다.
        total = sum(c3.values())
        inter = set(arr1) & set(arr2)
        inter_cnt = 0
        for word in inter:
            inter_cnt += min(arr1.count(word), arr2.count(word)) #교집합은 다중집합에서 공통부분의 개수중 작은 것을 더한다
        return inter_cnt / total
        
        
    def fill_arr(string):
        arr = []
        cnt = 0
        idx = 0
        temp_str = ""
        while idx<len(string)-1:
            if string[idx].isalpha() and string[idx+1].isalpha():
                arr.append(string[idx:idx+2].lower())
            idx += 1
        return arr
                
    arr1 = fill_arr(str1)
    arr2 = fill_arr(str2)
    if not arr1 and not arr2: return 65536
    else:
        return math.floor(get_jacquard(arr1, arr2) * 65536)