K = int(input())
ls = []
for i in range(K):
    n = int(input())
    if n==0:
        ls.pop(-1)
    else:
        ls.append(n)
print(sum(ls))