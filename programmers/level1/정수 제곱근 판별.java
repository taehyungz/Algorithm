class Solution {
    public long solution(long n) {
        long answer = 0;
        long tempN = (long)Math.pow(n, 0.5);
        if(tempN * tempN == n) answer = (tempN+1)*(tempN+1);
        else answer = -1;
        return answer;
    }
}