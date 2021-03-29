class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int halfRectLength = (brown-4)/2;
        for(int x=halfRectLength-1; x>=1; x--) {
            int y = halfRectLength - x;
            if(x * y == yellow) {
                answer[0] = x+2;
                answer[1] = y+2;
                break;
            }
        }
        return answer;
    }
}