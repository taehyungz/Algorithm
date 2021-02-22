import collections
def solution(progresses, speeds):
    answer = []
    
    how_many_days = [0 for i in range(len(progresses))]
    for i in range(len(progresses)):
        how_many_days[i] = ((100-progresses[i])+speeds[i]-1)//speeds[i]
        #100 - progesses[i] : 남은 진도율
        #speeds[i]-1 을 더하는 이유 : speeds[i]로 나눴을 때, 나머지가 있으면 하루가 더 걸림
    
    minimum = how_many_days[0]
    for i in range(1, len(progresses)):
        how_many_days[i] = max(how_many_days[i-1], how_many_days[i])
    counter = collections.Counter(how_many_days)
    return list(counter.values())