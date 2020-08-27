import sys

M = int(sys.stdin.readline().rstrip())
S = set()
for i in range(M):
    order = sys.stdin.readline().rstrip()
    if order=="all":
       S = set([i for i in range(1,21)])
    elif order == "empty":
        S = set()
    elif order[0]=='a':
        s_order, n = order.split()
        n = int(n)
        S.add(n)
    elif order[0]=='r':
        s_order, n = order.split()
        n = int(n)
        if n in S: S.remove(n)
    elif order[0]=='c':
        s_order, n = order.split()
        n = int(n)
        if n in S: print("1")
        else: print("0")
    elif order[0]=='t':
        s_order, n = order.split()
        n = int(n)
        if n in S: S.remove(n)
        else: S.add(n)