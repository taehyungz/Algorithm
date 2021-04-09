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
    
    if len(holes)==0: return True #�ڹ����� Ȩ�� ������ �ڹ��谡 ó������ ��������
    for rotation_cnt in range(4):
        # print(rotation_cnt, targets)
        for move_y in range(-len(key)+1, len(lock)): #����/�¿츦 ���� �������� Ȯ��
            for move_x in range(-len(key[0])+1, len(lock[0])):
                targets2 = []
                check = True #���Ⳣ�� ����� �˻�
                for target in targets:
                    y, x = target
                    y, x = y+move_y, x+move_x
                    if 0<=y<len(lock) and 0<=x<len(lock[0]) and lock[y][x]==1:
                        check=False #���Ⳣ�� ����
                        break
                    if 0<=y<len(lock) and 0<=x<len(lock[0]): targets2.append((y,x))
                
                if check and len(targets2) >= len(holes): #���Ⳣ�� ��� ���� ����, Ű�� ������� ����&Ű�� ������ ���� �������� ���ų� ����
                    # print(f"ȸ�� ��: {rotation_cnt}, y�̵�: {move_y}, x�̵�: {move_x}, Ű����: {targets2}, ����: {holes}")
                    checkHole = False
                    for hole in holes:
                        checkHole = False #���ۿ� �´� ���� �ִ��� �˻�
                        for target in targets2:
                            if target==hole:
                                checkHole = True
                                break
                        if not checkHole: break
                    if checkHole:
                        return True
        if rotation_cnt!=3: rotate_key()
    return False