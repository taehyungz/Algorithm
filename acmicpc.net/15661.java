import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N, M;
    static int[] nums;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        nums = new int[N];
        DFS(0);
        bw.flush();
        bw.close();
    }

    static void DFS(int level) throws IOException {
        if(level == M){
            for(int i = 0;i < M;i++){
                bw.write(nums[i]+ " ");
            }
            bw.write("\n");
            return;
        }
        for(int i=1;i<=N;i++){
            nums[level] = i;
            DFS(level+1);
        }
    }
}