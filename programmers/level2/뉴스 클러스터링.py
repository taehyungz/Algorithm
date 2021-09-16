import collections, math

def solution(str1, str2):
    str1, str2, counter = str1.lower(), str2.lower(), collections.Counter
    multi_list1 = [str1[i:i+2] for i in range(len(str1)-1) if str1[i].isalpha() and str1[i+1].isalpha()]
    multi_list2 = [str2[i:i+2] for i in range(len(str2)-1) if str2[i].isalpha() and str2[i+1].isalpha()]
    if not multi_list1 and not multi_list2: return 65536
    c1, c2 = counter(multi_list1), counter(multi_list2)
    c1_and_c2_mul2 = c1 + c2 - (c1-c2) - (c2-c1)
    c1_or_c2_mul2 = c1 + c1 + c2 + c2 - c1_and_c2_mul2
    return math.floor(sum(c1_and_c2_mul2.values()) / sum(c1_or_c2_mul2.values()) * 65536)
