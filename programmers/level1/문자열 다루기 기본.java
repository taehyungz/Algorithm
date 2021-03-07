class Solution {
    public boolean solution(String s) {
        if(s.length()!=4 && s.length()!=6) return false;
        for(char ch: s.toCharArray()) {
            if(ch<'0' || ch>'9') return false;
        }
        return true;
    }
}