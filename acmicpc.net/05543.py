ls = list()
ls2 = list()
for i in range(5):
    if i<3: ls.append(int(input()))
    else: ls2.append(int(input()))
print(min(ls)+min(ls2)-50)