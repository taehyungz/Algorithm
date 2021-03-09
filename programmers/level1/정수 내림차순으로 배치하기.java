import java.util.*;
class Solution {
    public long solution(long n) {
        long answer = 0;
        String s = ""+n;
        int[] arr = new int[s.length()];
        for(int i=0; i<s.length(); i++) {
            arr[i] = (int)s.charAt(i)-(int)'0';
        }
        Arrays.sort(arr);
        StringBuilder builder = new StringBuilder();
        for(int i=arr.length-1; i>=0; i--) {
            builder.append(arr[i]);
        }
        answer = Long.parseLong(builder.toString());
        return answer;
    }
}