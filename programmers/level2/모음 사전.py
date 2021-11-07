count = 0
def solution(word):
    global count
    def dfs(s):
        global count
        count += 1
        if s == word: return True
        for i in range(5):
            if len(s) < 5 and dfs(s + ch_list[i]): return True
        return False
    
    ch_list = ['A','E','I','O','U']
    for i in range(5):
        if dfs(ch_list[i]): return count