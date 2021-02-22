import collections
def solution(progresses, speeds):
    answer = []
    
    how_many_days = [0 for i in range(len(progresses))]
    for i in range(len(progresses)):
        how_many_days[i] = ((100-progresses[i])+speeds[i]-1)//speeds[i]
        #100 - progesses[i] : ���� ������
        #speeds[i]-1 �� ���ϴ� ���� : speeds[i]�� ������ ��, �������� ������ �Ϸ簡 �� �ɸ�
    
    minimum = how_many_days[0]
    for i in range(1, len(progresses)):
        how_many_days[i] = max(how_many_days[i-1], how_many_days[i])
    counter = collections.Counter(how_many_days)
    return list(counter.values())