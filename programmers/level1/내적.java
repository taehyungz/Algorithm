class Solution {
    public int solution(int[] a, int[] b) {
        
        int total = 0;
        for(int i=0; i<a.length; i++) {
            a[i] *= b[i];
            total += a[i];
        }
        return total;
    }
}