test_case = int(input())
for case in range(test_case):
    N, M = map(int,input().split())
    ls = list(map(int, input().split()))
    origin = M
    cnt = 0
    while len(ls)!=0:
        check = True
        for i in range(1,len(ls)):
            if ls[0]<ls[i]:
                if origin==0: origin = len(ls)-1
                else: origin -= 1
                temp = ls[0]
                ls.pop(0)
                ls.append(temp)
                check = False
                break
        if check:
            ls.pop(0)
            cnt += 1
            if origin==0:
                print(cnt)
                break
            else: origin -= 1