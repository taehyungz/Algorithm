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
            # str[i]는 닫는 괄호
            # 이것의 여는 괄호가 ls에 있는지 검사
            ch = sets1[sets2.index(str[i])] #존재해야 하는 여는 괄호
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