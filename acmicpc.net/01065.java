import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int sum = 0;
        if(N < 100) {
            System.out.println(N);
        } else {
            sum += 99;
            if(N==1000) N=999;
            for(int i = 100; i<=N; i++){
                int f = (int)(i/100);
                int s = (int)(i/10) % 10;
                int t = i%10;
                if(s-f == t-s){
                    sum += 1;
                }
            }
            System.out.println(sum);
        }
    }
}