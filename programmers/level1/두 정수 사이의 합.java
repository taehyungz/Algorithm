class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        int temp = Math.min(a, b);
        b = Math.max(a,b);
        a = temp;
        for(int i=a; i<=b; i++) {
            answer += i;
        }
        return answer;
    }
}