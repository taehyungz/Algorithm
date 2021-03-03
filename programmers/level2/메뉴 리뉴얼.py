import collections
from itertools import combinations
def solution(orders, course):
    ods = []
    counter = collections.Counter
    dic = collections.defaultdict(list)
    for od in orders:
        for length in course:
            cmb = combinations(sorted(od), length)
            for each_od in cmb:
                ods.append(tuple(each_od))
    counter = counter(ods)
    for each_cnt in counter.most_common():
        if each_cnt[1] <2: break
        if dic[len(each_cnt[0])] and dic[len(each_cnt[0])][-1][1] > each_cnt[1]: continue
        else: dic[len(each_cnt[0])].append((''.join(each_cnt[0]), each_cnt[1]))
    ans = []
    for c_l in course:
        ans.extend(list(map(lambda x: x[0],dic[c_l])))
    return sorted(ans)