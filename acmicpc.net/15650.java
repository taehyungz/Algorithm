import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] nums;
    static boolean[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] strs = br.readLine().split(" ");
        int N = Integer.parseInt(strs[0]);
        int M = Integer.parseInt(strs[1]);

        nums = new int[M];
        visited = new boolean[N+1];
        find(N, M, 0, 0);
        bw.flush();
        bw.close();
        br.close();
    }

    public static void find(int N, int M, int cnt, int minimum) throws IOException {
        if(cnt == M){
            for(int number: nums){
                bw.write(number+" ");
            }
            bw.write("\n");
            return;
        }

        for(int i=minimum+1;i<=N;i++){
            if(!visited[i]){
                visited[i] = !visited[i];
                nums[cnt] = i;
                find(N, M, cnt+1, i);
                visited[i] = !visited[i];
            }
        }
    }
}