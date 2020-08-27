import sys

N = int(sys.stdin.readline().rstrip())
line = list(map(int, sys.stdin.readline().rstrip().split()))
converted_line = sorted(set(line))
new_num = {}
for i in range(len(converted_line)):
    new_num[converted_line[i]]=i
for i in line:
    print(new_num[i], end=' ')
