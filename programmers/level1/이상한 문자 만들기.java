import java.util.*;

class Solution {
    public String solution(String s) {
        String[] strs = s.split(" ", -1);
        StringBuilder builder = new StringBuilder();
        StringBuilder answerBuilder = new StringBuilder();
        for(String word: strs) {
            builder.delete(0, builder.length());
            for(int i=0; i<word.length();i++) {
                if (i%2==0) builder.append((""+word.charAt(i)).toUpperCase());
                else builder.append((""+word.charAt(i)).toLowerCase());
            }
            answerBuilder.append(builder.toString());
            answerBuilder.append(" ");            
        }
        answerBuilder.delete(answerBuilder.length()-1, answerBuilder.length());
        return answerBuilder.toString();
    }
}