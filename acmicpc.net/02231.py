num = int(input())
def check(i):
    strnum = str(i)
    sum = i
    for i in range(len(strnum)):
        sum = sum + int(strnum[i])
    return sum
tf=True
for i in range(num+1):
    if check(i)==num:
        print(i)
        tf=False
        break
if tf:
    print("0")