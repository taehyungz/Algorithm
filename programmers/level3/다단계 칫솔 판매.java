import java.util.*;

class Solution {
    Map<String, String> empToRef;
    Map<String, Integer> earning;
    Map<String, Integer> salary;
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        List<Integer> answer = new ArrayList<>();
        empToRef = new HashMap<>();
        salary = new HashMap<>();
        for (int i=0; i<enroll.length; i++) { //직원-그 직원을 추천한 사람 저장
            empToRef.put(enroll[i], referral[i]);
        }
        for (int i=0; i<seller.length; i++) {
            dfs(amount[i]*100, seller[i]);
        }
        for (int i=0; i<enroll.length; i++) {
            answer.add(salary.getOrDefault(enroll[i], 0));
        }
        return answer.stream().mapToInt(i->i).toArray();
    }
    public void dfs(int totalGain, String ref) {
        if (ref.equals("-")) {
            return;
        }
        int fee = (int)(totalGain * 0.1);
        int gain = totalGain - fee;
        salary.put(ref, salary.getOrDefault(ref, 0) + gain);
        if (fee > 0) dfs(fee, empToRef.get(ref));
    }
}