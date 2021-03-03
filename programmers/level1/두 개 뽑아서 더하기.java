import java.util.HashSet;
import java.util.Set;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] numbers) {
        ArrayList<Integer> arr = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < numbers.length; i++) {
            for(int j = 0; j < numbers.length; j++) {
                if(i != j) {
                    set.add(numbers[i] + numbers[j]);
                }
            }
        }
        int[] answer = new int[set.size()];
        int i = 0;
        for(int n: set) {
            answer[i++] = n;
        }
        Arrays.sort(answer);
        return answer;
    }
}