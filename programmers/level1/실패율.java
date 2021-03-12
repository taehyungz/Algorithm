import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        double[] failure = new double[N];
        int[] answer = new int[N];
        int[] inStageNotCleared = new int[N+1];
        int[] stageReached = new int[N+1];
        PriorityQueue<Failure> priorityQueue = new PriorityQueue<>();
        for(int i=0; i<stages.length; i++ ){
            inStageNotCleared[stages[i]-1] += 1;
        }
        stageReached[N] = inStageNotCleared[N];
        for(int i=N-1; i>=0; i--) {
            stageReached[i] = stageReached[i+1] + inStageNotCleared[i];
        }
        for(int i=0; i<N; i++) {
            failure[i] = (double)inStageNotCleared[i]/stageReached[i];
        }
        System.out.println(Arrays.toString(failure));
        for(int i=0; i<N; i++) {
            priorityQueue.offer(new Failure(i+1, failure[i]));
        }
        int i = 0;
        while (!priorityQueue.isEmpty())
            answer[i++] = priorityQueue.poll().idx;
        return answer;
    }
    
    public class Failure  implements Comparable<Failure> {
        double percentage;
        int idx;
        
        Failure(int idx, double percentage) {
            this.idx = idx;
            this.percentage = percentage;
        }
        
        @Override
        public int compareTo(Failure f) {
            if (this.percentage < f.percentage ) {
                return 1;
            } else if (this.percentage > f.percentage ) {
                return -1;
            } else if(this.idx > f.idx) {
                return 1;
            } else return -1;
        }
    }
}