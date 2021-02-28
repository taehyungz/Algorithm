import collections
def solution(n, words):
    answer = []
    dic = collections.defaultdict(int)
    p_idx = 0
    cycle = 1
    for idx, word in enumerate(words):
        if dic[word]==1 or (idx>0 and words[idx-1][-1] != word[0]):
            return [p_idx+1,cycle]
        dic[word] = 1
        p_idx = p_idx+1
        if p_idx == n:
            p_idx = 0
            cycle += 1

    return [0,0]