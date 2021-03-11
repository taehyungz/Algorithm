class Solution {
    public boolean solution(int x) {
        int temp = x;
        int eachNTotal = 0;
        while(temp>0) {
            eachNTotal += temp%10;
            temp /= 10;
        }
        if(x % eachNTotal == 0) return true;
        else return false;
    }
}