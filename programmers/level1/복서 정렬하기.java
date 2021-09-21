import java.util.*;
import java.util.stream.Collectors;

class Solution {
    int[] weights;
    String[] head2head;
    
    public int[] solution(int[] weights, String[] head2head) {
        this.weights = weights;
        this.head2head = head2head;
        //½Â·ü, ¸ö¹«°Ô´Ù ½Â¼ö, ¸ö¹«°Ô¹«, ¹øÈ£ÀÛ
        List<Info> list = new ArrayList<>();
        for (int i=0; i<weights.length; i++) {
            list.add(new Info(getWinRatio(i), getWinHeavier(i), weights[i], i+1));
        }
        return list.stream().sorted((a,b) -> {
            if (a.winRatio > b.winRatio) return -1;
            else if (a.winRatio < b.winRatio) return 1;
            else if (a.winHeavier > b.winHeavier) return -1;
            else if (a.winHeavier < b.winHeavier) return 1;
            else if (a.weight > b.weight) return -1;
            else if (a.weight < b.weight) return 1;
            else if (a.number < b.number) return -1;
            else return 1;
        }).mapToInt(Info::getNumber).toArray();
    }
    
    double getWinRatio(int number) {
        int winCnt = 0;
        int loseCnt = 0;
        for (int i=0; i<head2head.length; i++) {
            if (head2head[number].charAt(i) == 'W') winCnt++;
            else if (head2head[number].charAt(i) == 'L') loseCnt++;
        }
        if (winCnt + loseCnt == 0) return 0;
        return (double) winCnt / (winCnt + loseCnt);
    }
    
    int getWinHeavier(int number) {
        int winCnt = 0;
        for (int i=0; i<weights.length; i++) {
            if (head2head[number].charAt(i) == 'W' && weights[i] > weights[number]) winCnt++;
        }
        return winCnt;
    }
    
    class Info {
        double winRatio;
        int winHeavier;
        int weight;
        int number;
        
        public Info(double winRatio, int winHeavier, int weight, int number) {
            this.winRatio = winRatio;
            this.winHeavier = winHeavier;
            this.weight = weight;
            this.number = number;
        }
        
        public int getNumber() {
            return this.number;
        }
    }
}