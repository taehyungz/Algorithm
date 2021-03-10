import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        ArrayList<Integer> ans = new ArrayList<>(arr.length-1);
        if(arr.length == 1) {
            arr[0] = -1;
            return arr;
        } else {
            int minNum = arr[0];
            for(int n: arr) {
                ans.add(n);
                minNum = Math.min(n, minNum);
            }
            for(int i=0; i<ans.size(); i++) {
                if(arr[i] == minNum) {
                    ans.remove(i);
                    break;
                }
            }
        }
        int[] intArr = new int[ans.size()];
        for(int i=0; i<ans.size(); i++) {
            intArr[i] = ans.get(i);
        }
        return intArr;
    }
}