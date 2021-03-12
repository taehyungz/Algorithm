import java.util.*;

class Solution {
    public int solution(int[] d, int budget) {
        Arrays.sort(d);
        int cnt = 0;
        for(int b: d) {
            budget -= b;
            if(budget >= 0) cnt ++;
            else break;
        }
        return cnt;
    }
}