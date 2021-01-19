import java.io.*;
import java.util.Scanner;

public class Main {
    static int[][] board;
    static int N;
    static int cnt;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        board = new int[N][N];
        cnt = 0;

        DFS(0);

        System.out.println(cnt);
    }

    public static void DFS(int depth){
        if(depth==N) {
            cnt += 1;
            return;
        }
        for(int i=0;i<N;i++){
            if(check(depth, i)){
                board[depth][i] = 1;
                DFS(depth+1);
                board[depth][i] = 0;
            }
        }
    }

    private static boolean check(int depth, int i) {
        for(int row = 0; row < depth; row++){
            if(board[row][i]==1) return false;
        }
        for(int minus = 1;i-minus>=0 && depth-minus >= 0;minus++){
            if(board[depth-minus][i-minus] == 1) return false;
        }
        for(int plus = 1;i+plus<N && depth-plus>=0;plus++){
            if(board[depth-plus][i+plus] == 1) return false;
        }
        return true;
    }
}