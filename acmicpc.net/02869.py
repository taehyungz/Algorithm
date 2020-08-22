A, B, V = map(int,input().split())
# 하루동안 올라가는 높이 : A-B, 마지막 날은 B감소 없음
# n*A - n*B + B >= V -> (A-B)*n >= V-B
dif = A - B
res = V - B
if res%dif == 0:
    print(res//dif)
else:
    print(res//dif+1)