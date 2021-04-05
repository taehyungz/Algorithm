class Solution {
    static int[] answer = new int[2];
    int[][] arr;
    
    public int[] solution(int[][] arr) {
        this.arr = arr;
        int width = arr.length;
        
        dfs(0,0,width);
        return answer;
    }
    public void dfs(int y, int x, int length) {
        int n = arr[y][x];
        boolean check = false;
        for(int nowY=y; nowY<y+length; nowY++) {
            for(int nowX=x; nowX<x+length; nowX++) {
                if(arr[nowY][nowX] != n) {
                    check = true;
                    dfs(y, x, length/2);
                    dfs(y+length/2, x, length/2);
                    dfs(y, x+length/2, length/2);
                    dfs(y+length/2, x+length/2, length/2);
                    break;
                }
            }
            if(check) break;
        }
        if(!check) {
            answer[n]++;
        }
    }
}