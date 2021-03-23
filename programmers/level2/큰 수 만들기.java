import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        int length = number.length()-k;
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<number.length(); i++) {
            int n = number.charAt(i) - '0';
            while(!st.empty() && st.peek()<n && k>0) {
                st.pop();
                k--;
            }
            st.push(n);
        }
        StringBuilder sb = new StringBuilder();
        while(!st.empty()) sb.append(st.pop());
        return sb.reverse().toString().substring(0,length);
    }
}