import collections
def solution(nums):
    dic = collections.defaultdict(int)
    for n in nums:
        dic[n] += 1
    return min(len(dic.keys()), len(nums)//2)