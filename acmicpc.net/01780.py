import sys

N = int(sys.stdin.readline().rstrip())
papers = []
ans = [0, 0, 0] # -1, 0, 1 ±â·Ï
for i in range(N):
    line_paper = list(map(int,sys.stdin.readline().rstrip().split()))
    papers.append(line_paper)

def div_count(startx,starty,size):
    check = False
    first = papers[starty][startx]
    for i in range(starty,starty+size):
        for j in range(startx,startx+size):
            if first!=papers[i][j]:
                check = True
                break
        if check: break
    if check:
        new_size = int(size/3)
        for i in range(3):
            for j in range(3):
                div_count(startx+new_size*i,starty+new_size*j,new_size)
    else:
        ans[first+1] += 1

div_count(0,0,N)
print(ans[0])
print(ans[1])
print(ans[2])