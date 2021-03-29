def solution(triangle):
    answer = 0
    dp = [[0 for i in range(j)] for j in range(1,len(triangle)+1)]
    dp[0][0] = triangle[0][0]
    for line in range(1,len(triangle)):
        for x in range(len(triangle[line])):
            if x==0: dp[line][x] = dp[line-1][x] + triangle[line][x]
            elif x==len(triangle[line])-1: dp[line][x] = dp[line-1][x-1] + triangle[line][x]
            else: dp[line][x] = max(dp[line-1][x-1], dp[line-1][x])+triangle[line][x]
    answer = max(dp[len(triangle)-1])
    return answer