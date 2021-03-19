import java.util.*;

class Solution {
    public int[] solution(int n) {
        int lastN = n*(n+1)/2;
        int[] answer = new int[lastN];
        int nowH = 0;
        int nowW = 0;
        int maxCnt = n;
        int number = 1;
        ArrayList<Integer[]> arr = new ArrayList<>();
        for(int line = 0; line < n; line ++) {
            arr.add(new Integer[line+1]);
        }
        while(number <= lastN) {
            int cnt = 0;
            while(cnt++ < maxCnt) {
                arr.get(nowH++)[nowW] = number++;
            }
            nowH--;
            nowW++;
            maxCnt--;
            cnt = 0;
            while(cnt++ < maxCnt) {
                arr.get(nowH)[nowW++] = number++;
            }
            nowW-=2;
            nowH--;
            maxCnt--;
            cnt = 0;
            while(cnt++ < maxCnt) {
                arr.get(nowH--)[nowW--] = number++;
            }
            nowH+=2;
            nowW++;
            maxCnt--;
        }
        int idx = 0;
        for(int i=0; i<arr.size();i++) {
            for(int j=0; j<arr.get(i).length; j++) {
                answer[idx++] = arr.get(i)[j];
            }
        }
        return answer;
    }
}