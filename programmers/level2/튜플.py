import collections
def solution(s):
    dic = collections.defaultdict(int)
    s2 = s.split('},')
    s2[0] = s2[0][1:]
    s2[-1] = s2[-1][:-2]
    s3 = sorted(s2, key=len)
    ans =[]
    for idx, arr in enumerate(s3):
        for number in arr[1:].split(','):
            if not dic[number]:
                dic[number]=1
                ans.append(int(number))
    return ans