import java.util.*;

class Solution {
    public String solution(String p) {
        if(p.equals("")) return p;
        int cnt = 0;
        String u = "";
        String v = "";
        for(int i=0; i<p.length(); i++) {
            if(p.charAt(i)=='(') {
                cnt++;
            } else {
                cnt--;
            }
            if(cnt==0) {
                u = p.substring(0, i+1);
                v = p.substring(i+1, p.length());
                break;
            }            
        }
        if(isRight(u)) {
            return u + solution(v);
        } else {
            return "("+solution(v.toString())+")"+makeU(u);
        }
    }
    
    public String makeU(String u) {
        StringBuilder nsb = new StringBuilder();
        for(int i=1; i<u.length()-1; i++) {
            if(u.charAt(i)=='(') nsb.append(')');
            else nsb.append('(');
        }
        return nsb.toString();
    }
    
    public boolean isRight(String s) {
        int cnt = 0;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i)=='(') cnt++;
            else cnt--;
            if(cnt<0) return false;
        }
        return true;
    }
}