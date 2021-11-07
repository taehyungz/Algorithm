import java.util.*;

class Solution {
    public int solution(String word) {
        int answer = 0;
        Map<Character, Integer> chs = Map.of('E', 1, 'I', 2, 'O', 3, 'U', 4);
        for (int i=0; i<word.length(); i++) {
            char ch = word.charAt(i);
            if (ch == 'A') answer += 1;
            else {
                for (int j=4; j>=i; j--) {
                    answer += Math.pow(5, (j-i)) * chs.get(ch);
                }
                answer += 1;
            }
        }
        return answer;
    }
}