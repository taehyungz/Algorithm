num = int(input())

for line in range(1, num+1):
    for star in range((num-1)//2): print("* ", end='')
    print("*")
    for star in range(num//2): print(" *", end='')
    print()