import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> prq = new PriorityQueue<>();
        for(int n: scoville) prq.offer(n);
        while(prq.size() > 1 && prq.peek() < K) {
            int a = prq.poll();
            int b = prq.poll();
            prq.add(a+2*b);
            answer++;
        }
        if(prq.size() == 0 || (prq.size()>0 && prq.peek()<K)) return -1;
        else return answer;
    }
}