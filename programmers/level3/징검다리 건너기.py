import collections

def solution(stones, k):
    left, right = 1, max(stones)
    answer = 1
    while left <= right:
        mid = left + (right-left) // 2
        zero_cnt = 0
        
        for i in stones:
            if i < mid: zero_cnt += 1
            else: zero_cnt = 0
            if zero_cnt == k: break
            
        if zero_cnt < k:
            left = mid + 1
            answer = max(answer, mid)
        else:
            right = mid - 1
    return answer