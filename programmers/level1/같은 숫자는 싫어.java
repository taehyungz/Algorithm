import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> arrList = new ArrayList<>(arr.length);
        for(int n: arr) {
            if(arrList.size()>0 && arrList.get(arrList.size()-1) != n) arrList.add(n);
            else if(arrList.size()==0) arrList.add(n);
        }
        int[] answer = new int[arrList.size()];
        for(int i=0; i < arrList.size(); i++) {
            answer[i] = arrList.get(i);
        }
        return answer;
    }
}