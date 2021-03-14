import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int time = 1;
        int total = 0;
        Queue<BridgeInfo> q = new LinkedList<>();
        for(int i=0; i<truck_weights.length;) {
            if(q.size()>0 && q.peek().out_time<=time) {
                total = total - q.poll().weight;
            }
            if(total+truck_weights[i] <= weight) {
                System.out.println(time+bridge_length);
                q.offer(new BridgeInfo(truck_weights[i], time+bridge_length));
                total += truck_weights[i++];
                time += 1;
            } else time = q.peek().out_time;
        }
        while(q.size()>0) {
            time = q.poll().out_time;
        }
        return time;
    }
    
    public class BridgeInfo {
        int weight;
        int out_time;
        BridgeInfo(int weight, int out_time) {
            this.weight = weight;
            this.out_time = out_time;
        }
    }
}