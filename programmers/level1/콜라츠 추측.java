class Solution {
    public int solution(int num) {
        if(num==1) return 0;
        int cnt = 0;
        long num2 = num;
        while(cnt++<500) {
            if(num2%2==0) num2/=2;
            else num2 = num2 * 3 + 1;
            if(num2==1) break;
        }
        return num2==1 ? cnt : -1;
    }
}