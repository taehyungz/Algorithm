import sys

test_case = int(sys.stdin.readline().rstrip())
for i in range(test_case):
    d_nums = []
    d_types = []
    n = int(sys.stdin.readline().rstrip())
    for j in range(n):
        d_name, d_type = sys.stdin.readline().rstrip().split()
        if d_type not in d_types:
            d_types.append(d_type)
            d_nums.append(1)
        else:
            d_nums[d_types.index(d_type)] += 1
    total = sum(d_nums)
    if len(d_types)<2:
        print(total)
        continue
    gob = 1
    for j in range(len(d_nums)):
        gob *= (d_nums[j]+1)
    total = gob
    total = total -1
    print(total)