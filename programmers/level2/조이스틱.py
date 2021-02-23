def solution(name):
    change_needed = [0]*len(name)
    for idx, ch in enumerate(name):
        change_needed[idx] = min(ord(ch)-ord('A'), ord('Z')-ord(ch)+1)
    total = sum(change_needed)
    idx = ans = 0
    while total:
        ans += change_needed[idx]
        total -= change_needed[idx]
        if total == 0: return ans
        change_needed[idx] = 0
        
        left_midx = right_midx = 1
        while change_needed[idx-left_midx] == 0:
            left_midx += 1
        while idx+right_midx < len(change_needed) and change_needed[idx+right_midx] == 0:
            right_midx += 1
        if left_midx < right_midx: #가까운 거리로 이동
            idx -= left_midx
            ans += left_midx
        else:
            idx += right_midx
            ans += right_midx