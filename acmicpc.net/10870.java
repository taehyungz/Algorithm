import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] fibos = new int[N+1];
        fibos[0] = 0;
        if(N>0){
            fibos[1] = 1;
        }
        for(int i=2;i<=N;i++){
            fibos[i] = fibos[i-1]+fibos[i-2];
        }
        System.out.println(fibos[N]);
    }
}