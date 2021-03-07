import java.util.*;

class Solution {
    public int solution(int n) {
        int ans = n-1;
        int[] prime_numbers = new int[n+1];
        for(int i=0; i<=n; i++) {
            prime_numbers[i] = i;
        }
        for(int i=2; i<=(int)Math.pow(n,0.5)+1; i++){
            if(prime_numbers[i]!=0) {
                for(int j=i*2; j<=n; j += i) {
                    if(prime_numbers[j]==0) continue;
                    prime_numbers[j] = 0;
                    ans--;
                }
            }
        }
        return ans;
    }
}