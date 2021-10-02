class Solution {
    public int solution(int[][] sizes) {
        int bigLength = 0;
        int smallLength = 0;
        for (int[] size: sizes) {
            bigLength = Math.max(bigLength, Math.max(size[0], size[1]));
            smallLength = Math.max(smallLength, Math.min(size[0], size[1]));
        }
        return bigLength * smallLength;
    }
}