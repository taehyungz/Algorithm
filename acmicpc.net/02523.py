max = int(input())

for line in range(1,max+1):
    for star in range(1,line+1):
        print("*", end='')
    print()
for line in range(max-1,0,-1):
    for star in range(1,line+1):
        print("*", end='')
    print()