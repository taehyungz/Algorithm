def solution(arr):
    def dfs(posy, posx, line_len) :
        temp = arr[posy][posx]
        check = False
        for i in range(posy, posy+line_len):
            for j in range(posx, posx+line_len):
                if arr[i][j] != temp:
                    check = True
                    dfs(posy, posx, line_len//2)
                    dfs(posy+line_len//2, posx, line_len//2)
                    dfs(posy, posx+line_len//2, line_len//2)
                    dfs(posy+line_len//2, posx+line_len//2, line_len//2)
                    break
            if check: break
        if not check:
            ans[temp] += 1
    ans = [0,0]
    line_len = len(arr)
    posy, posx = 0, 0
    dfs(posy, posx, line_len)
    return ans