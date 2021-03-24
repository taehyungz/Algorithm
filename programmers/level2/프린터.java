import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        int pr = priorities[location];
        Queue<PInfo> q = new LinkedList<>();
        PriorityQueue<PInfo> pq = new PriorityQueue<>();
        for(int i=0; i<priorities.length; i++) {
            pq.offer(new PInfo(priorities[i],i));
            q.offer(new PInfo(priorities[i],i));
        }
        while(true) {
            PInfo p = pq.poll();
            PInfo p2 = q.poll();
            if(p.priority!= p2.priority) {
                pq.offer(p);
                q.offer(p2);
            } 
            else if(p2.idx == location) return answer;
            else answer++;
        }
    }
    public class PInfo implements Comparable<PInfo> {
        private int priority;
        private int idx;
        
        PInfo(int priority, int idx) {
            this.priority = priority;
            this.idx = idx;
        }
        
        public int compareTo(PInfo b) {
            if(this.priority > b.priority) return -1;
            else if(this.priority < b.priority) return 1;
            else if(this.idx < b.idx) return -1;
            else if(this.idx > b.idx) return 1;
            else return 0;
        }
    }
}