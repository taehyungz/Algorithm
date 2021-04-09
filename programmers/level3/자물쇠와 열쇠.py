def solution(key, lock):
    def rotate_key():
        for idx, target in enumerate(targets):
            # i,j => j, len(key)-1-i
            targets[idx] = (target[1], len(key)-1-target[0])
    targets = []
    holes = []
    for i in range(len(key)):
        for j in range(len(key[0])):
            if key[i][j]==1: targets.append((i,j))
    
    for i in range(len(lock)):
        for j in range(len(lock[0])):
            if lock[i][j]==0: holes.append((i,j))
    
    if len(holes)==0: return True #자물쇠의 홈이 없으면 자물쇠가 처음부터 열려있음
    for rotation_cnt in range(4):
        # print(rotation_cnt, targets)
        for move_y in range(-len(key)+1, len(lock)): #상하/좌우를 각각 움직여서 확인
            for move_x in range(-len(key[0])+1, len(lock[0])):
                targets2 = []
                check = True #돌기끼리 닿는지 검사
                for target in targets:
                    y, x = target
                    y, x = y+move_y, x+move_x
                    if 0<=y<len(lock) and 0<=x<len(lock[0]) and lock[y][x]==1:
                        check=False #돌기끼리 닿음
                        break
                    if 0<=y<len(lock) and 0<=x<len(lock[0]): targets2.append((y,x))
                
                if check and len(targets2) >= len(holes): #돌기끼리 닿는 것이 없음, 키가 비어있지 않음&키의 개수가 구멍 개수보다 같거나 많음
                    # print(f"회전 수: {rotation_cnt}, y이동: {move_y}, x이동: {move_x}, 키돌기: {targets2}, 구멍: {holes}")
                    checkHole = False
                    for hole in holes:
                        checkHole = False #구멍에 맞는 것이 있는지 검사
                        for target in targets2:
                            if target==hole:
                                checkHole = True
                                break
                        if not checkHole: break
                    if checkHole:
                        return True
        if rotation_cnt!=3: rotate_key()
    return False