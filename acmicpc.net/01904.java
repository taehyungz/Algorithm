import java.io.*;
import java.util.Scanner;

public class Main {
    static int[] arr;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n==1) {
            System.out.println("1");
            return;
        }
        arr = new int[n+1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for(int i=3;i<=n;i++){
            arr[i] = (arr[i-1]+arr[i-2])%15746;
        }
        System.out.println(arr[n]);
    }
}