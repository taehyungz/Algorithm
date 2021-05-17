import java.util.*;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        Map<Integer, Integer> lottoMap = new HashMap<>();
        for(int number: win_nums) {
            lottoMap.put(number, 1);
        }
        int hit = 0;
        int zeros = 0;
        for(int predict: lottos) {
            if(lottoMap.containsKey(predict)) {
                hit += 1;
            } else if(predict == 0) zeros++;
        }
        int rank = 7;
        int min_rank = Math.min(6, rank - hit);
        int max_rank = Math.max(Math.min(6, rank - hit - zeros), 1);
        int[] answer = {max_rank, min_rank};
        return answer;
    }
}