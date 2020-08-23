length = int(input())
strings = input()
ls = list()
sum = 0
mul = 1
MOD = 1234567891
for i in range(len(strings)):
    sum = (sum + (ord(strings[i])-ord('a')+1)*mul)%MOD
    mul = (mul*31)%MOD
print(int(sum))