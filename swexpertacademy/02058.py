number = int(input())
sum = 0
ls = [1000,100,10,1]
cn = 0
while number>0:
    sum = sum + number//ls[cn]
    number = number - number // ls[cn] * ls[cn]
    cn = cn + 1
print(sum)