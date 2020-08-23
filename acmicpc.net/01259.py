number = input()
while int(number)!=0:
    check=False
    length = len(number)
    for i in range(length//2):
        if number[i]!=number[length-1-i]:
            check=True
    if check: print("no")
    else: print("yes")
    number = input()