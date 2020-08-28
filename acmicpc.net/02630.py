import sys

N = int(sys.stdin.readline().rstrip())
papers = []

for i in range(N):
    line = list(map(int, sys.stdin.readline().rstrip().split()))
    papers.append(line)

color = [0,0]
def find_paper(size, papers, color, starty, startx):
    first = papers[starty][startx]
    check = False
    for i in range(starty, starty+size):
        for j in range(startx, startx+size):
            if first!=papers[i][j]:
                check = True
                break
        if check: break
    if check:
        new_size = size//2
        for i in range(2):
            for j in range(2):
                find_paper(new_size, papers, color, starty+i*new_size, startx+j*new_size)
    else:
        color[first] += 1

find_paper(N, papers, color, 0,0)
print(color[0])
print(color[1])