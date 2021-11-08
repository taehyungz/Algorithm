import java.util.*;

class Solution {
    
    private String[] grid;
    private boolean[][][] visited;
    private int col, row;
    private int[] moveY = {1,0,-1,0}, moveX = {0,-1,0,1};
    
    public int[] solution(String[] grid) {
        List<Integer> answer = new ArrayList<>();
        this.grid = grid;
        this.row = grid.length;
        this.col = grid[0].length();
        this.visited = new boolean[this.row][this.col][4];
        
        for (int y=0; y<this.row; y++) {
            for (int x=0; x<this.col; x++) {
                for (int i=0; i<4; i++) { //╩С, ©Л, го, аб
                    if (!this.visited[y][x][i]) {
                        answer.add(getCycle(y, x, i));
                    }
                }
            }
        }
        return answer.stream().mapToInt(i->i).sorted().toArray();
    }
    
    private int getCycle(int y, int x, int i) {
        int cnt = 0;
        while (true) {
            char ch = this.grid[y].charAt(x);
            if (this.visited[y][x][i]) break;
            cnt++;
            this.visited[y][x][i] = true;
            
            //L from->to: ╩С -> ©Л -> го -> аб -> ╩С
            //R from->to: ╩С -> аб -> го -> ©Л -> ╩С
            if (ch == 'L') i = i==0 ? 3 : i-1;
            else if (ch == 'R') i = i==3 ? 0 : i+1;
            y = (this.row + y + this.moveY[i]) % this.row;
            x = (this.col + x + this.moveX[i]) % this.col;
        }
        
        return cnt;
    }
}