import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        int[] changeNeed = new int[name.length()];
        int total = 0;
        int idx = 0;
        for(int i=0; i<name.length(); i++) {
            changeNeed[i] = getChangeNum(name.charAt(i));
            total += changeNeed[i];
        }
        int deb = 0;
        while(total!=0) {
            int lMv = 0;
            int rMv = 1;
            if(changeNeed[idx]!=0) {
                answer += changeNeed[idx];
                total -= changeNeed[idx];
                changeNeed[idx] = 0;
            }
            if(total==0) break;
            int temp_idx = idx;
            while(changeNeed[temp_idx-lMv] == 0) {
                lMv++;
                if(temp_idx-lMv < 0) temp_idx += name.length();
            }
            while(idx+rMv < name.length() && changeNeed[idx+rMv] == 0)  rMv++;
            if(idx+rMv == name.length() || lMv < rMv) {
                idx = idx - lMv;
                if(idx<0) idx += name.length();
                answer += lMv;
            } else {
                idx = idx + rMv;
                answer += rMv;
            }
        }
        return answer;
    }
    
    public int getChangeNum(char ch) {
        return Math.min(ch-'A', 1+'Z'-ch);
    }
}