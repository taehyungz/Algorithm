import java.util.*;

class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] ans = new String[n];
        String bn1;
        String bn2;
        for(int i=0; i<n; i++) {
            StringBuilder sb = new StringBuilder();
            bn1 = Integer.toBinaryString(arr1[i]);
            bn2 = Integer.toBinaryString(arr2[i]);
            for(int j=0; j<n; j++) {
                if(bn1.length()-n+j<0 && bn2.length()-n+j<0) sb.append(" ");
                else if(bn1.length()-n+j<0 && bn2.charAt(bn2.length()-n+j) == '1') sb.append("#");
                else if(bn2.length()-n+j<0 && bn1.charAt(bn1.length()-n+j) == '1') sb.append("#");
                else if(bn1.length()-n+j<0 || bn2.length()-n+j<0) sb.append(" ");
                else if(bn1.charAt(bn1.length()-n+j) == '1' || bn2.charAt(bn2.length()-n+j) == '1') sb.append("#");
                else sb.append(" ");
            }
            ans[i] = sb.toString();
        }
        return ans;
    }
}