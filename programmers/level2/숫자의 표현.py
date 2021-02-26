def solution(n):
    def dfs(i, total):
        if total == n: return 1
        elif total > n: return 0
        else: return dfs(i+1, total+i+1)
        
    cnt = 0
    for i in range(1, n//2+1):
        cnt += dfs(i, i)
    return cnt+1