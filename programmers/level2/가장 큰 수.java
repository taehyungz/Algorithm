import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        ArrayList<Integer> arr = new ArrayList<>();
        for(int n: numbers) arr.add(n);
        Collections.sort(arr, (a,b) -> {
            String sa = ""+a;
            String sb = ""+b;
            if(Integer.parseInt(sa+sb) < Integer.parseInt(sb+sa)) return 1;
            else if(Integer.parseInt(sa+sb) > Integer.parseInt(sb+sa)) return -1;
            else return 0;
        });
        StringBuilder sb = new StringBuilder();
        for(int n: arr) sb.append(n);
        answer = sb.toString();
        if(answer.charAt(0) == '0') return "0";
        else return answer;
    }
}