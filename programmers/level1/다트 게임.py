def solution(dartResult):
    idx = 0
    des = []
    while idx<len(dartResult):
        if dartResult[idx] == '*' and len(des)==1: des[0] *= 2
        elif dartResult[idx] == '*':
            des[-1] *= 2
            des[-2] *= 2
        elif dartResult[idx] == '#':
            des[-1] *= -1
        else:
            score = int(dartResult[idx])
            if dartResult[idx+1].isdigit():
                idx += 1
                score = score*10 + int(dartResult[idx])
            char_score = dartResult[idx+1]
            if char_score == 'S': des.append(score)
            elif char_score == 'D': des.append(score**2)
            else: des.append(score**3)
            idx += 1
        idx += 1
    return sum(des)