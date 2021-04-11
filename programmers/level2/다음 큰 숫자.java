class Solution {
    public int solution(int n) {
        String s = Integer.toBinaryString(n);
        int cnt = checkCnt(s);
        int answer = n+1;
        while(true)
            if(checkCnt(Integer.toBinaryString(answer++)) == cnt) return answer-1;
    }
    
    public int checkCnt(String s) {
        int cnt = 0;
        for(int i=0; i<s.length(); i++)
            if(s.charAt(i) == '1') cnt++;
        return cnt;
    }
}