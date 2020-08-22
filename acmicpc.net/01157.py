str = input().upper()
ls = [0 for i in range(26)]
for i in range(len(str)):
    ls[ord(str[i])-ord('A')]+=1
maxnum = max(ls)
cnt = ls.count(maxnum)
if cnt==1:
    print(chr(ord('A')+ls.index(maxnum)))
else:
    print('?')