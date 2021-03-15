import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i=0; i<progresses.length; i++) {
            arr.add((int)(Math.ceil((double)(100-progresses[i])/speeds[i])));
        }
        ArrayList<Integer> answer = new ArrayList<Integer>();
        int minimum = arr.get(0);
        answer.add(1);
        for(int i=1; i<arr.size();i++) {
            if(arr.get(i)<=minimum) {
                int temp = answer.get(answer.size()-1) + 1;
                answer.remove(answer.size()-1);
                answer.add(temp);
            } else {
                answer.add(1);
                minimum = arr.get(i);
            }
        }
        int[] ansArr = new int[answer.size()];
        for(int i=0; i<answer.size(); i++) ansArr[i] = answer.get(i);
        return ansArr;
    }
}