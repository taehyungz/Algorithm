import collections
def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        dic = collections.defaultdict(lambda:-1)
        for idx, ch in enumerate(skill_tree):
            dic[ch] = idx
        flag = True
        for i in range(1,len(skill)):
            for j in range(i):
                front = skill[i]
                rear = skill[j]
                print(dic[front], dic[rear])
                if (dic[front] != -1 and dic[rear] == -1) or\
                (dic[front]!=-1 and dic[rear]!=-1 and dic[front]<dic[rear]):
                    #���� ��ų �� ��� or ������ų�� ���߿� ���
                    flag=False
                    break
            if not flag: break
        if flag: answer += 1
        print(flag, skill_tree)
    return answer
                