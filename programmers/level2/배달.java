class Solution {
    private static final int MAX_DELIVERY = 500000;
    private int[] dist;
    private boolean[] visit;
    
    public int findDest() {//1번에서 방문하지 않은 가장 가까운 점 리턴
        int dest = 0;
        int minDist = MAX_DELIVERY;
        for(int i=1; i<dist.length; i++) {
            if(dist[i] < minDist && visit[i] == false) {
                minDist = dist[i];
                dest = i;
            }
        }
        return dest;
    }
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        dist = new int[N+1];
        visit = new boolean[N+1];
        for(int i=0; i<N+1; i++) {
            dist[i] = MAX_DELIVERY; //거리 최댓값 저장
        }
        
        dist[1] = 0; //1번에서 출발
        
        for(int i=0; i<N-1; i++) { //총 N개의 점이므로 1을 제외한 N-1개에 대해서
            int dest = findDest();
            for(int[] road_v: road) {
                if(road_v[0] == dest || road_v[1] == dest) {
                    int visitNode = road_v[0] == dest ? road_v[1] : road_v[0];
                    if(!visit[visitNode]) dist[visitNode] = Math.min(dist[visitNode], dist[dest] + road_v[2]);
                }
            }
            visit[dest] = true;
        }
        for(int i=1; i<dist.length; i++) {
            if(dist[i] <= K) answer++;
        }
        return answer;
    }
}