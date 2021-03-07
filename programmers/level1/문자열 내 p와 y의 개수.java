class Solution {
    boolean solution(String s) {
        s = s.toLowerCase();
        int cntp = 0;
        int cnty = 0;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == 'p') cntp++;
            else if(s.charAt(i) == 'y') cnty++;
        }
        return cntp==cnty;
    }
}