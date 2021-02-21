def solution(a, b):
    day = -1
    for m in range(1, a):
        if m == 2: day += 29
        elif m in [2,4,6,9,11]: day += 30
        else: day += 31
    day += b
    day_name = ['FRI','SAT','SUN','MON','TUE','WED','THU']
    return day_name[day%7]