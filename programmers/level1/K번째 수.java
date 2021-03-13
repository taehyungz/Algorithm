import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int ansIdx = 0;
        for(int[] com: commands) {
            int[] temp = new int[com[1]-com[0]+1];
            int idx = 0;
            for(int i=com[0]-1; i<com[1]; i++) {
                temp[idx++] = array[i];
            }
            Arrays.sort(temp);
            answer[ansIdx++] = temp[com[2]-1];
        }
        return answer;
    }
}