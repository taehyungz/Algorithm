class Solution {
    static int[][] pictureCopy;
    static int m;
    static int n;
    static int[] px = {0,0,1,-1};
    static int[] py = {1,-1,0,0};
    public int[] solution(int m, int n, int[][] picture) {
        this.m = m;
        this.n = n;
        pictureCopy = new int[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                pictureCopy[i][j] = picture[i][j];
            }
        }
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        int[] answer = new int[2];
        
        for(int y=0; y<m; y++) {
            for(int x=0; x<n; x++) {
                if(pictureCopy[y][x] != 0) {
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea,dfs(y, x));
                    numberOfArea++;
                }
            }
        }
        
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
    
    public int dfs(int y, int x) {
        int color = pictureCopy[y][x];
        int cnt = 1;
        pictureCopy[y][x] = 0;
        for(int i=0; i<4; i++) {
            int nextY = y+py[i];
            int nextX = x+px[i];
            if(0<=nextY && nextY<m && 0<=nextX && nextX<n && pictureCopy[nextY][nextX]==color) {
                cnt += dfs(nextY, nextX);
            }
        }
        return cnt;
    }
}