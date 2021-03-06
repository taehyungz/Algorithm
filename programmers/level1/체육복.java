class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int[] clothes = new int[n];
        
        for(int lost_n: lost) clothes[lost_n-1]--;
        for(int reserve_n: reserve) clothes[reserve_n-1]++;
       
        for(int i=0; i<n; i++) {
            if(clothes[i] == -1) {
                if(i>0 && clothes[i-1]==1) {                    clothes[i]++;
                    clothes[i-1]--;
                } else if(i<n-1 && clothes[i+1]==1) {
                    clothes[i]++;
                    clothes[i+1]--;
                }
            }
        }
        
        int answer = 0;
        for(int i=0; i<n; i++) {
            if(clothes[i]>= 0) answer++;
        }
        return answer;
    }
}