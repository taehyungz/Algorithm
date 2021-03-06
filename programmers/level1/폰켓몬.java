import java.util.HashMap;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        HashMap<Integer,Integer> hashMap = new HashMap<>();
        for(int n: nums) {
            hashMap.put(n, hashMap.getOrDefault(n, 0)+1);
        }
        return Math.min(hashMap.size(), nums.length/2);
    }
}