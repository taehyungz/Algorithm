import collections

n = int(input())
answer = 0
for i in range(n):
    s = input()
    dic = collections.defaultdict(int)
    check = True
    for idx, ch in enumerate(s):
        if dic[ch]==0: dic[ch]=1
        elif s[idx]!=s[idx-1]:
            check = False
            break
    if check: answer += 1
print(answer)