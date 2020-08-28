import sys
import collections
T = int(sys.stdin.readline().rstrip())

for test_case in range(T):
    p = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline().rstrip())
    fr_check = True # True이면 앞에서부터 삭제, False이면 뒤에서부터 삭제
    err_check = False #error여부 저장
    lenp = len(p)
    if n>0: xlist = collections.deque(map(int,sys.stdin.readline().rstrip()[1:-1].split(',')))
    else:
        temp = sys.stdin.readline().rstrip()
        xlist = []
    for i in range(lenp):
        order = p[i]
        if p[i]=='D' and len(xlist)==0:
            print("error")
            err_check = True
            break
        elif p[i]=='D':
            if fr_check: xlist.popleft()
            else: xlist.pop()
        else:
            fr_check = not fr_check
    if err_check: continue
    if len(xlist)==0:
        print("[]")
    elif fr_check:
        print("[", end='')
        lenxlist = len(xlist)
        for i in range(lenxlist-1): print(xlist[i], end=',')
        print(f"{xlist[lenxlist-1]}]")
    else:
        print("[", end='')
        lenxlist = len(xlist)
        for i in range(lenxlist-1,0,-1): print(xlist[i],end=',')
        print(f"{xlist[0]}]")