class Solution {
    private int[][] dungeons;
    private int answer;
    
    public int solution(int k, int[][] dungeons) {
        this.dungeons = dungeons;
        this.answer = 0;
        dfs(new boolean[dungeons.length], 0, k);
        return this.answer;
    }
    
    private void dfs(boolean[] visited, int cnt, int k) {
        for (int i=0; i<this.dungeons.length; i++) {
            this.answer = Math.max(this.answer, cnt);
            if (!visited[i] && this.dungeons[i][0] <= k) {
                visited[i] = true;
                k -= this.dungeons[i][1];
                dfs(visited, cnt+1, k);
                visited[i] = false;
                k += this.dungeons[i][1];
            }
        }
    }
}