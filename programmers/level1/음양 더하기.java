class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int total = 0;
        
        for(int i=0; i < absolutes.length; i++) {
            total += signs[i] == true ? absolutes[i] : -absolutes[i];
        }
        return total;
    }
}