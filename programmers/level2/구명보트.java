import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        int leftIdx = 0;
        int rightIdx = people.length-1;
        int nowWeight = 0;
        while(leftIdx <= rightIdx) {
            while(leftIdx <= rightIdx && nowWeight+people[rightIdx] <= limit) {
                nowWeight += people[rightIdx--];
            }
            while(leftIdx <= rightIdx && nowWeight+people[leftIdx] <= limit) {
                nowWeight += people[leftIdx++];
            }
            answer++;
            nowWeight = 0;
        }
        return answer;
    }
}