a,b,c = (map(int,input().split()))
# a는 고정비용 b는 한 대당 비용 c는 가격
n=1
if c<=b: print("-1")
else:
    print(a//(c-b)+1)