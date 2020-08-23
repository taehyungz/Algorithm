import math
length = int(input())
strings = input()
ls = list()
sum = 0
for i in range(len(strings)):
    ls.append(ord(strings[i])-ord('a')+1)
for i in range(len(ls)):
    sum = sum + (math.pow(31,i)* ls[i])%1234567891
print(int(sum))