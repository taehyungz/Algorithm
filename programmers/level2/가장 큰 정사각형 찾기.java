class Solution {
    public int solution(int [][]board) {
        int maximum = board[0][0];
        for(int i=1; i<board.length; i++) {
            for(int j=1; j<board[0].length; j++) {
                if(board[i][j]>=1) {
                    board[i][j] = Math.min(board[i][j-1], Math.min(board[i-1][j], board[i-1][j-1])) + 1;
                    maximum = Math.max(maximum, board[i][j]);
                }
            }
        }
        return maximum*maximum;
    }
}