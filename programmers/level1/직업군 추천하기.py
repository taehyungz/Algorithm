import collections

def solution(table, languages, preference):
    total_score = {}
    for scores in table:
        info = scores.split()
        for lang, pref in zip(languages, preference):
            if lang in info:
                total_score[info[0]] = total_score.get(info[0], 0) + (6 - info.index(lang)) * pref
    return sorted(total_score.items(), key = lambda x: (-x[1], x[0]))[0][0]