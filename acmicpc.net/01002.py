import math
test_case = int(input())
for i in range(test_case):
    x1,y1,r1,x2,y2,r2 = map(int,input().split())
    r = math.sqrt((x2-x1)**2+(y2-y1)**2)
    maxr = max(r1,r2)
    minr = min(r1,r2)
    if r1==r2 and x1==x2 and y1==y2: #���� ��ĥ ��
        print("-1")
    elif r1+r2 > r and maxr-minr<r: #�� ������ ���� ��
        print("2")
    elif r1+r2 == r or maxr-minr == r: #�� ������ ���� ��(�ܺο���, ���ο���)
        print("1")
    else:
        print("0")