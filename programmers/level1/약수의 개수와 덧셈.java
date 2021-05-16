class Solution {
    public int solution(int left, int right) {
        int answer = 0;
        for(int i = left; i <= right; i++) {
            if(cnt_yak(i) % 2 == 0) answer += i;
            else answer -= i;
        }
        return answer;
    }
    
    public int cnt_yak(int number) {
            int cnt = 1;
            for(int i=1; i<number/2+1; i++) {
                if(number % i == 0) cnt += 1;
            }
            return cnt;
        }
}