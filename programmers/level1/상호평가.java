import java.util.*;
class Solution {
    public String solution(int[][] scores) {
        StringBuilder sb = new StringBuilder();
        
        for (int col = 0; col < scores[0].length; col++) {
            int maxScore = 0;
            int minScore = 100;
            double sum = 0;
            int myCnt = 0;
            for (int row = 0; row < scores.length; row++) {
                sum += scores[row][col];
                if (maxScore < scores[row][col]) maxScore = scores[row][col];
                else if (minScore > scores[row][col]) minScore = scores[row][col];
                if (scores[row][col] == scores[col][col]) myCnt++;
            }
            if (myCnt == 1 && (maxScore == scores[col][col] || minScore == scores[col][col])) sb.append(getGrade((sum-scores[col][col])/(scores.length-1)));
            else sb.append(getGrade(sum/scores.length));
        }
        return sb.toString();
    }
    
    public String getGrade(double score) {
        if (score >= 90) return "A";
        else if (score >= 80) return "B";
        else if (score >= 70) return "C";
        else if (score >= 50) return "D";
        else return "F";
    }
}