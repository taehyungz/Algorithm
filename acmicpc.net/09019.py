import sys
import collections
T = int(sys.stdin.readline())
for each_test in range(T):
    A, B = tuple(map(int,sys.stdin.readline().split()))
    Q = collections.deque()
    Q.append((int(A), ""))
    values = collections.defaultdict(int)
    values[A] = 1

    while Q:
        number, method = Q.popleft()
        numd = (number * 2) % 10000
        if numd == B:
            print(method+"D")
            break
        elif values[numd] == 0:
            Q.append((numd, method+"D"))
            values[numd] = 1

        nums = number - 1
        if nums == -1: nums = 9999
        if nums == B:
            print(method+"S")
            break
        elif values[nums] == 0:
            Q.append((nums, method+"S"))
            values[nums] = 1

        if number < 1000:
            numl = number*10
        else:
            numl = number//1000 + (number-number//1000*1000)*10
        numr = number//10 + (number-number//10*10)*1000
        if numl == B:
            print(method+"L")
            break
        elif values[numl] == 0:
            Q.append((numl, method+"L"))
            values[numl] = 1

        if numr == B:
            print(method+"R")
            break
        elif values[numr] == 0:
            Q.append((numr, method+"R"))
            values[numr] = 1