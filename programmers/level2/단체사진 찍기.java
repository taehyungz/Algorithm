class Solution {
    static char[] characters = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    static boolean[] visited = new boolean[8];
    static String[] data;
    static int answer;
    
    public int solution(int n, String[] data) {
        this.data = data;
        this.answer = 0;
        for(int i=0; i<characters.length; i++) {
            visited[i] = true;
            dfs(i, ""+characters[i]);
            visited[i] = false;
        }
        
        return answer;
    }
    
    public void dfs(int idx, String line) {
        if(line.length() == characters.length) {
            boolean isAllRight = check(line);
            if(isAllRight) answer++;
        }
        for(int i=0; i<characters.length; i++) {
            if(!visited[i]) {
                visited[i] = true;
                dfs(i, line+characters[i]);
                visited[i] = false;
            }
        }
    }
    
    public boolean check(String line) {
        boolean isRight = true;
        for(String query: data) {
            char first = query.charAt(0);
            char second = query.charAt(2);
            char op = query.charAt(3);
            int diff = (int)(query.charAt(4)-'0');
            int firstPos = line.indexOf(first);
            int secondPos = line.indexOf(second);
            int posDiff = Math.abs(firstPos-secondPos)-1;
            if(op=='=') isRight = posDiff == diff;
            else if(op=='<') isRight = posDiff < diff;
            else isRight = posDiff > diff;
            if(!isRight) return false;
        }
        return true;
    }
}