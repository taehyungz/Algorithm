lennum = int(input())
ls = list(map(int,input().split()))
ls.sort()
print(ls[lennum//2])