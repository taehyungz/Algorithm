def solution(answers):
    p1 = [1,2,3,4,5]
    p2 = [2,1,2,3,2,4,2,5]
    p3 = [3,3,1,1,2,2,4,4,5,5]
    counts = [0,0,0]
    i1, i2, i3 = 0,0,0
    for ans in answers:
        if p1[i1]==ans: counts[0] += 1
        if p2[i2]==ans: counts[1] += 1
        if p3[i3]==ans: counts[2] += 1
        i1, i2, i3 = i1+1, i2+1, i3+1
        if i1>len(p1)-1: i1 = 0
        if i2>len(p2)-1: i2 = 0
        if i3>len(p3)-1: i3 = 0
    ans = [i+1 for i in range(3) if counts[i]==max(counts)]
    return ans