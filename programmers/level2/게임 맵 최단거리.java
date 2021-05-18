import java.util.*;

class Solution {
    public int solution(int[][] maps) {
        Queue<Point> q = new LinkedList<>();
        q.offer(new Point(0, 0, 1));
        int[] yMove = {1,-1,0,0};
        int[] xMove = {0,0,1,-1};
        int[][] visited = new int[maps.length][maps[0].length];
        visited[0][0] = 1;
        
        while(q.size() > 0) {
            Point myPos = q.poll();
            if(myPos.y == maps.length-1 && myPos.x == maps[0].length-1) return myPos.cnt;
            
            for(int i=0; i<4; i++) {
                int nextY = myPos.y + yMove[i];
                int nextX = myPos.x + xMove[i];
                int nextCnt = myPos.cnt + 1;
                boolean check = (0<=nextY && nextY<maps.length && 0<=nextX && nextX<maps[0].length && visited[nextY][nextX] == 0 && maps[nextY][nextX] == 1);
                if(check) {
                    Point nextPoint = new Point(nextY, nextX, nextCnt);
                    q.offer(nextPoint);
                    visited[nextY][nextX] = 1;
                }
            }
        }
        
        return -1;
    }
    
    class Point {
        int y;
        int x;
        int cnt;
        
        Point(int y, int x, int cnt) {
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }
    };
}