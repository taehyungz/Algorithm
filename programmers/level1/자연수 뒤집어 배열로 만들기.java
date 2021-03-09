import java.util.*;

class Solution {
    public int[] solution(long n) {
        StringBuilder builder = new StringBuilder();
        builder.append(n).reverse();
        String ans = builder.toString();
        int[] arr = new int[ans.length()];
        for(int i=0; i<ans.length(); i++) {
            arr[i] = (int)ans.charAt(i) - (int)'0';
        }
        return arr;
    }
}