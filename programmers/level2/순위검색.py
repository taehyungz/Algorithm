from itertools import combinations
import collections
from bisect import *

def solution(info, query):
    answer = []
    people = collections.defaultdict(list)
    for person in info:
        person_info = person.split()
        person_strs = person_info[:-1]
        wage = int(person_info[-1])
        people[''.join(person_strs)].append(wage)
        for num in range(1,5):
            num_list = combinations(range(4), num)
            for idxs in num_list:
                tperson_strs = person_strs[:]
                for idx in idxs:
                    tperson_strs[idx] = '-'
                people[''.join(tperson_strs)].append(wage)
    
    for key in people.keys():
        people[key].sort()
    
    for q in query:
        ans = 0
        qsplit = q.split(" and ")
        qsplit.extend(qsplit.pop().split())
        wage = int(qsplit.pop())
        find = people[''.join(qsplit)]
        ans += len(find) - bisect_left(find, wage)
        answer.append(ans)
    return answer