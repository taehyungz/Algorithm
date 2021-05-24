import java.util.*;

class Solution {
    public int solution(int N, int[][] road, int K) {
        Map<Integer, List<DestWithValue>> map = new HashMap<>();
        for(int[] road_v: road) {
            if(map.containsKey(road_v[0])) {
                map.get(road_v[0]).add(new DestWithValue(road_v[1], road_v[2]));
            } else {
                ArrayList<DestWithValue> arr = new ArrayList<>();
                arr.add(new DestWithValue(road_v[1], road_v[2]));
                map.put(road_v[0], arr);
            }
            if(map.containsKey(road_v[1])) {
                map.get(road_v[1]).add(new DestWithValue(road_v[0], road_v[2]));
            } else {
                ArrayList<DestWithValue> arr = new ArrayList<>();
                arr.add(new DestWithValue(road_v[0], road_v[2]));
                map.put(road_v[1], arr);
            }
        }
        Queue<DestWithValue> queue = new LinkedList<>();
        queue.offer(new DestWithValue(1,0));
        Set<Integer> answer = new HashSet<>();
        Map<Integer, Integer> times = new HashMap<>();
        
        
        while(queue.size() != 0) {
            DestWithValue dv = queue.poll();
            int dest = dv.dest;
            int time = dv.time;
            answer.add(dest);
            times.put(dest, Math.min(times.getOrDefault(dest, 500000), time));
            List<DestWithValue> arr = map.get(dest);
            for(int i=0; i<arr.size(); i++) {
                DestWithValue nextDv = arr.get(i);
                int nextTime = time + nextDv.time;
                int nextOriginalTime = times.getOrDefault(nextDv.dest, 500000);
                
                if(nextTime <= K && nextTime < nextOriginalTime) {
                    queue.offer(new DestWithValue(nextDv.dest, nextTime));
                }
            }
        }
        // printMap(map);
        // System.out.println(answer);
        return answer.size();
    }
    
    public void printMap(Map<Integer, List<DestWithValue>> map) {
        Set<Integer> keys = map.keySet();
        Iterator<Integer> iter = keys.iterator();
        while(iter.hasNext()) {
            int key = iter.next();
            List<DestWithValue> list = map.get(key);
            for(int i=0; i<list.size(); i++) {
                System.out.println(""+key+" -> "+list.get(i).dest+" : "+list.get(i).time);
            }
        }
    }
    
    class DestWithValue {
        public int dest;
        public int time;
        
        public DestWithValue(int dest, int time) {
            this.dest = dest;
            this.time = time;
        }
    }
}