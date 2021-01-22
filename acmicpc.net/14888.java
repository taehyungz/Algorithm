import java.io.*;
import java.util.Scanner;

public class Main {
    static int N;
    static int[] nums;
    static int[] symbols = new int[4];
    static long minn = 1000000000;
    static long maxn = -1000000000;
    static long ans = 0;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        nums = new int[N];

        for(int i=0;i<N;i++){
            nums[i] = sc.nextInt();
        }

        for(int i=0;i<4;i++){
            symbols[i] = sc.nextInt();
        }
        ans = nums[0];
        dfs(1);

        System.out.printf("%d\n%d\n", maxn, minn);
    }
    static void dfs(int level) throws IOException {
        if(level == N){
            if(minn > ans){
                minn = ans;
            }
            if(maxn < ans){
                maxn = ans;
            }
            return;
        }

        for(int i=0;i<4;i++){
            if(symbols[i] > 0){
                symbols[i] -= 1;
                long temp = ans;
                switch (i) {
                    case 0:
                        ans += nums[level];
                        break;
                    case 1:
                        ans -= nums[level];
                        break;
                    case 2:
                        ans *= nums[level];
                        break;
                    case 3:
                        if(ans < 0){
                            ans = (-ans)/nums[level];
                            ans = -ans;
                        } else {
                            ans /= nums[level];
                        }
                }
                dfs(level+1);
                symbols[i] += 1;
                ans = temp;
            }
        }
    }
}