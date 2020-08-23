K, N = map(int, input().split())
ls = []
for i in range(K):
    ls.append(int(input()))
right = max(ls)
left = 1
max = 0 # 최대길이
finded=[]
def find_ans(ls,left, right):
    mid = (left+right)//2
    finded.append(mid)
    sum = 0 # 개수
    for i in range(K):
       sum = sum + ls[i]//mid
    if sum>=N:
        if ((mid+1+right)//2) not in finded:
            return find_ans(ls, mid+1, right)
        else:
            return mid
    else:
        return find_ans(ls, left, mid-1)

print(find_ans(ls, left, right))