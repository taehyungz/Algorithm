class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int position = 1;
        int sIdx = 0;
        
        while(position <= n) {
            if(sIdx < stations.length && stations[sIdx] - w <= position) {
                position = stations[sIdx++] + w + 1;
            } else {
                answer += 1;
                position += w*2 + 1;
            }
        }
        return answer;
    }
}