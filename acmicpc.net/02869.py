A, B, V = map(int,input().split())
# �Ϸ絿�� �ö󰡴� ���� : A-B, ������ ���� B���� ����
# n*A - n*B + B >= V -> (A-B)*n >= V-B
dif = A - B
res = V - B
if res%dif == 0:
    print(res//dif)
else:
    print(res//dif+1)