class Solution {
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        int minN = Math.min(n, m);
        n = Math.max(n,m);
        answer[0] = get_gcd(n, minN);
        answer[1] = get_lcm(answer[0], n, minN);
        return answer;
    }
    public int get_gcd(int maxN, int minN) {
        if(minN==0) return maxN;
        else {
            int temp = maxN % minN;
            
            return temp > minN ? get_gcd(temp, minN) : get_gcd(minN, temp);
        }
    }
    public int get_lcm(int gcd, int maxN, int minN) {
        return maxN * minN / gcd;
    }
}