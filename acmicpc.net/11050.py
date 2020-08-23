a, b = map(int,input().split())
up = 1
down = 1
for i in range(a,a-b,-1):
    up = up * i
for i in range(1,b+1):
    down = down * i
print(int(up/down))