def solution(dirs):
    visited=set()
    posy, posx = 0, 0
    for d in dirs:
        if d=='U' and posy+1<=5:
            posy += 1
            visited.add((posy-1,posx,posy,posx))
            visited.add((posy,posx,posy-1,posx))
        elif d=='D' and posy-1>=-5:
            posy -= 1
            visited.add((posy+1,posx,posy,posx))
            visited.add((posy,posx,posy+1,posx))
        elif d=='L' and posx-1>=-5:
            posx -= 1
            visited.add((posy,posx+1,posy,posx))
            visited.add((posy,posx,posy,posx+1))
        elif d=='R' and posx+1<=5:
            posx += 1
            visited.add((posy,posx-1,posy,posx))
            visited.add((posy,posx,posy,posx-1))
        
    return len(visited)//2