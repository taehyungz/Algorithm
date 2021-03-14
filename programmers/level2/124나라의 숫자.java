import java.util.*;

class Solution {
    public String solution(int n) {
        String threestr = getThreenary(n);
        return threestr;
    }
    
    public String getThreenary(int n) {
        StringBuilder sb = new StringBuilder();
        Boolean check = n%3==0;
        while(n>0) {
            if(n%3!=0) sb.append(n%3);
            else sb.append(4);
            n /= 3;
            if(sb.charAt(sb.length()-1) == '4') n-=1;
        }
        return sb.reverse().toString();
    }
}