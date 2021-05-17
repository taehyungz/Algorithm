import java.util.*;

class Solution {
    public int solution(String s) {
        List<Character> arr = new ArrayList<>();
        for(char ch: s.toCharArray()) {
            if(arr.size() > 0 && arr.get(arr.size()-1) == ch) arr.remove(arr.size()-1);
            else arr.add(ch);
        }
        if(arr.size()==0) return 1;
        else return 0;
    }
}