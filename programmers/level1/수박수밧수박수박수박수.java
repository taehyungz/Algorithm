import java.util.*;

class Solution {
    public String solution(int n) {
        StringBuilder builder = new StringBuilder();
        char[] chs = {'��', '��'};
        for(int i=0;i<n;i++) {
            builder.append(chs[i%2]);
        }
        return builder.toString();
    }
}