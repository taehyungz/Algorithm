import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int diffsum = Integer.MAX_VALUE;
    static int N;
    static int[][] board;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        visited = new boolean[N];

        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for(int j=0;j<N;j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        combination(0, 0);
        System.out.println(diffsum);
    }

    public static void combination(int idx, int cnt){
        if(cnt == N/2){
            getDiff();
            return;
        }

        for(int i=idx;i<N;i++){
            if(!visited[i]){
                visited[i] = true;
                combination(i+1, cnt+1);
                visited[i] = false;
            }
        }
    }

    public static void getDiff(){
        int tstart = 0;
        int tlink = 0;

        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                if(visited[i] && visited[j]){
                    tstart += board[i][j];
                    tstart += board[j][i];
                } else if(!visited[i] && !visited[j]){
                    tlink += board[i][j];
                    tlink += board[j][i];
                }
            }
        }

        int temp_diff = Math.abs(tstart - tlink);

        if(temp_diff == 0){
            System.out.println(temp_diff);
            System.exit(0);
        }
        diffsum = Math.min(diffsum, temp_diff);
    }
}