class Solution {
    int solution(int[][] land) {
        int answer = 0;
        int[][] dp = new int[land.length][land[0].length];
        for(int i=0; i<dp[0].length; i++) dp[0][i] = land[0][i];
        for(int line=1; line<dp.length; line++) {
            for(int pos=0; pos<dp[0].length; pos++) {
                for(int temp=0; temp<dp[0].length; temp++) {
                    if(pos==temp) continue;
                    dp[line][pos] = Math.max(dp[line][pos], land[line][pos] + dp[line-1][temp]);
                }
            }
        }
        for(int i=0; i<dp[0].length; i++)
            answer = Math.max(answer, dp[land.length-1][i]);
        return answer;
    }
}