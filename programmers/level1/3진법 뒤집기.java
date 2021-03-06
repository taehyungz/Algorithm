import java.util.*;

class Solution {
    public int solution(int n) {
        ArrayList<Integer> arr = new ArrayList<>(20);
        while(n>0) {
            arr.add(n%3);
            n /= 3;
        }
        int answer = 0;
        int mul = 0;
        for(int i=arr.size()-1;i>=0;i--) {
            answer += arr.get(i)*(Math.pow(3,mul++));
        }
        return answer;
    }
}