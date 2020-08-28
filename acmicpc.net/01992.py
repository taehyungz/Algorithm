import sys

N = int(sys.stdin.readline().rstrip())
video = []
for i in range(N):
    line = list(map(int,sys.stdin.readline().rstrip()))
    video.append(line)

def condensed(video, startx, starty, size):
    first = video[starty][startx]
    unmatch = False
    for i in range(starty, starty+size):
        for j in range(startx, startx+size):
            if first != video[i][j]:
                unmatch = True
                break
        if unmatch:
            break
    if unmatch:
        new_size = size//2
        print("(",end='')
        for i in range(2):
            for j in range(2):
                condensed(video, startx+j*new_size, starty+i*new_size, new_size)
        print(")",end='')
    else:
        print(first, end= '')
condensed(video, 0, 0, N)