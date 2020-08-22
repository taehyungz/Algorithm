test_case = int(input())
for i in range(test_case):
    R, str = input().split()
    R = int(R)
    for j in range(len(str)):
        for k in range(R):
            print(str[j], end='')
    print()