class Solution {
    private int[] numbers;
    private int target;
    private int answer = 0;
    public int solution(int[] numbers, int target) {
        this.numbers = numbers;
        this.target = target;
        dfs(0, numbers[0]);
        dfs(0, -numbers[0]);
        return answer;
    }
    
    public void dfs(int idx, int sum) {
        if(idx == numbers.length - 1 && sum == target) {
            answer += 1;
            return;
        }
        if(idx == numbers.length - 1) return;
        dfs(idx+1, sum+numbers[idx+1]);
        dfs(idx+1, sum-numbers[idx+1]);
    }
}