import java.util.*;

class Solution {
    public String solution(String s, int n) {
        String answer = "";
        StringBuilder builder = new StringBuilder();
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            int temp;
            if(ch>='a' && ch<='z') {
                temp = (int)ch+n;
                if(temp>(int)'z') temp -= 26;
            } else if(ch>='A' && ch<='Z') {
                temp = (int)ch+n;
                if(temp>(int)'Z') temp -= 26;
            } else {
                builder.append(" ");
                continue;
            }
            builder.append(""+(char)temp);
        }
        answer = builder.toString();
        return answer;
    }
}