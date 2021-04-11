class Solution {
    boolean solution(String s) {
        int cnt = 0;
        for(char ch: s.toCharArray()) {
            if(ch=='(') cnt++;
            else cnt--;
            if(cnt<0) return false;
        }
        if(cnt==0) return true;
        return false;
    }
}