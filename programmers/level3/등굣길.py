def solution(m, n, puddles):
    dp = [[0 for i in range(m)] for j in range(n)]
    dp[0][0] = 1
    
    for y in range(0,n):
        for x in range(0,m):
            if [x+1,y+1] in puddles: continue
            if x-1 >= 0 and [x,y+1] not in puddles: dp[y][x] = (dp[y][x] + dp[y][x-1])%1000000007
            if y-1 >= 0 and [x+1,y] not in puddles: dp[y][x] = (dp[y][x] + dp[y-1][x])%1000000007
    return dp[n-1][m-1]