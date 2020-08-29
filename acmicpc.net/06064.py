import sys

def getGCD(M, N):
    while M!=0 and N!=0:
        if M>N: M=M%N
        else: N=N%M
    if M==0: return N
    else: return M

def get_ans():
    tempy = x
    while tempy<=lcm:
        if (tempy-y)%N == 0:
            return tempy
        tempy += M
    return -1
T = int(sys.stdin.readline().rstrip())
for tc in range(T):
    M, N, x, y = map(int,sys.stdin.readline().rstrip().split())
    gcd = getGCD(M, N)
    lcm = gcd * int(M//gcd) * int(N//gcd)
    print(get_ans())