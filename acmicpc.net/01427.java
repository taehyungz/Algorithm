import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        String str = Integer.toString(N);
        int len = str.length();
        int[] nums = new int[len];
        for(int i=0;i<len;i++){
            nums[i] = N%10;
            N = (int)(N/10);
        }

        for(int i=0;i<len-1;i++){
            for(int j=0;j<len-i-1;j++){
                if(nums[j]<nums[j+1]){
                    int temp = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        for(int num: nums){
            System.out.print(num);
        }
    }
}