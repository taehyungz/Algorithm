import java.util.Scanner;

public class Main {

    public static int[] numbers;
    public static boolean[] visited; //False

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        numbers = new int[M];
        visited = new boolean[N];

        dfs(N, M, 0);

    }

    public static void dfs(int N, int M, int cnt) {
        if(cnt == M){
            for(int number: numbers){
                System.out.print(number + 1 + " ");
            }
            System.out.println();
            return;
        }

        for(int i=0;i<N;i++){
            if(!visited[i]){
                visited[i] = !visited[i];
                numbers[cnt] = i;
                dfs(N, M, cnt+1);
                visited[i] = !visited[i];
            }
        }
    }
}