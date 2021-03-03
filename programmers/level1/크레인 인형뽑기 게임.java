import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> st = new Stack<>();
        for(int move: moves) {
            for(int h=0;h<board.length;h++) {
                if(st.empty() && board[h][move-1] != 0) { //������ ������� �ֱ�
                    st.push(board[h][move-1]);
                    board[h][move-1] = 0;
                    break;
                } else if(!st.empty() && board[h][move-1] == st.peek()) { //���ÿ� ���� �ְ�, ���� ã�� �Ͱ� ������ ���ÿ��� ����
                    board[h][move-1] = 0;
                    st.pop();
                    answer += 2;
                    break;
                } else if(board[h][move-1] != 0) { //���� ����
                    st.push(board[h][move-1]);
                    board[h][move-1] = 0;
                    break;
                }
            }
        }
        return answer;
    }
}