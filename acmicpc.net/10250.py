tc = int(input())
for i in range(tc):
    H,W,N = map(int, input().split())
    width = N//H + 1
    if N%H==0:
        width -= 1
    height = N%H
    if height==0:
        height = H
    if width<10:
        width = '0'+str(width)
    print(f'{height}{width}')
