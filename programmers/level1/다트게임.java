import java.util.*;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<dartResult.length(); i++) {
            char ch = dartResult.charAt(i);
            if(ch >= '0' && ch <='9') {
                int temp = (int)ch-(int)'0';
                if(i<dartResult.length()-1 && '0'<=dartResult.charAt(i+1) && dartResult.charAt(i+1)<='9') {
                    temp = 10;
                    i++;
                }
                st.push(temp);
            } else if(ch=='S') continue;
            else if(ch=='D') {
                int temp_score = st.pop();
                st.push(temp_score*temp_score);
            } else if(ch=='T') {
                int temp_score = st.pop();
                st.push(temp_score*temp_score*temp_score);
            } else if(ch=='*') {
                int temp1 = st.pop();
                if(!st.empty()) {
                    int temp2 = st.pop();
                    st.push(temp2*2);
                }
                st.push(temp1*2);
            } else if(ch=='#') {
                int temp_score = st.pop();
                st.push(-temp_score);
            }
        }
        while(!st.empty()) {
            answer += st.pop();
        }
        return answer;
    }
}