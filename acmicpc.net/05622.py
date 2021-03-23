str = input()
cnt = 0
for ch in str:
    dif = (ord(ch) - ord('A'))
    if dif<15:
        dif = dif//3+3
    elif dif<19:
        dif = 8
    elif dif<22:
        dif = 9
    else: dif = 10
    cnt += dif
print(cnt)