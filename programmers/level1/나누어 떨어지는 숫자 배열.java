import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        ArrayList<Integer> arrList = new ArrayList<>();
        for(int n: arr) {
            if(n%divisor == 0) {
                arrList.add(n);
            }
        }
        if(arrList.size() == 0) {
            int[] ans = {-1};
            return ans;
        } else {
            int[] ans = new int[arrList.size()];
            for(int i=0; i < arrList.size(); i++) {
                ans[i] = arrList.get(i);
            }
            Arrays.sort(ans);
            return ans;
        }
    }
}