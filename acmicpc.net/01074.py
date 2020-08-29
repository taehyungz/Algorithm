import sys

N, r, c = map(int,sys.stdin.readline().rstrip().split())

def getWhichArea(r,c,new_size,stx,sty):
    if c<stx+new_size and r<sty+new_size:
        return 1
    elif c>=stx+new_size and r<sty+new_size:
        return 2
    elif c<stx+new_size and r>=sty+new_size:
        return 3
    elif c>=stx+new_size and r>=sty+new_size:
        return 4

def find(r,c,size,stx,sty,idx):
    new_size = max(1, (size // 2))
    which = getWhichArea(r,c,new_size,stx,sty)
    if new_size==1 and which==1: # 해당위치로 옴
        return idx
    if which==1: return find(r, c, new_size, stx, sty, idx)
    elif which==2: return find(r, c, new_size, stx + new_size, sty, idx+new_size*new_size)
    elif which==3: return find(r, c, new_size, stx, sty + new_size, idx+new_size*new_size*2)
    elif which==4: return find(r, c, new_size, stx + new_size, sty + new_size, idx+new_size*new_size*3)

print(find(r,c,2**N,0,0,0))