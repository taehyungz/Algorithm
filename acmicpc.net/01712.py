a,b,c = (map(int,input().split()))
# a�� ������� b�� �� ��� ��� c�� ����
n=1
if c<=b: print("-1")
else:
    print(a//(c-b)+1)