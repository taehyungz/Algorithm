import sys

sets1 = ['(', '{', '[']
sets2 = [')', '}', ']']
str = sys.stdin.readline().rstrip()

while str!=".":
    ls = []
    check = True

    for i in range(len(str)):
        if str[i] in sets1:
            ls.append(str[i])
        elif str[i] in sets2:
            # str[i]�� �ݴ� ��ȣ
            # �̰��� ���� ��ȣ�� ls�� �ִ��� �˻�
            ch = sets1[sets2.index(str[i])] #�����ؾ� �ϴ� ���� ��ȣ
            if len(ls)>0 and ch == ls[-1]:
                ls.pop(-1)
            else:
                check = False
                print("no")
                break
    if check:
        if len(ls) == 0:
            print("yes")
        else:
            print("no")
    str = sys.stdin.readline().rstrip()