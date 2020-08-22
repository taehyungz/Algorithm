T = int(input())
 
for test_case in range(1,T+1):
    ls = list(map(int,input().split()))
    minnum = sum(ls)/len(ls)
    if minnum>minnum*10//10:
        minnum = ((minnum*10)+5)//10
    else:
        minnum = minnum*10//10
    minnum = int(minnum)
    print('#{} {}'.format(test_case,minnum))