class Solution:
    def DFS(self, grid, py, px):
        grid[py][px] = '2'
        if py+1<len(grid) and grid[py+1][px]=='1': self.DFS(grid,py+1, px)
        if py-1>=0 and grid[py-1][px]=='1': self.DFS(grid,py-1, px)
        if px+1<len(grid[0]) and grid[py][px+1]=='1': self.DFS(grid,py, px+1)
        if px-1>=0 and grid[py][px-1]=='1': self.DFS(grid,py, px-1)
    def numIslands(self, grid: List[List[str]]) -> int:
        cnt = 0
        for py in range(len(grid)):
            for px in range(len(grid[0])):
                if grid[py][px]=='1':
                    self.DFS(grid, py, px)
                    cnt+=1
        return cnt