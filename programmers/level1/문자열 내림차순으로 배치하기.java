import java.util.*;

class Solution {
    public String solution(String s) {
        char[] charr = s.toCharArray();
        Arrays.sort(charr);
        StringBuilder builder = new StringBuilder();
        for(int i=charr.length-1; i>=0; i--) {
            builder.append(charr[i]);
        }
        return builder.toString();
    }
}