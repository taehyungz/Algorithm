import java.util.*;

class Solution {
    public int[] solution(String msg) {
        Map<String, Integer> dict = new HashMap<>();
        int lastDictIdx = (int)('Z'-'A') + 1;
        List<Integer> answer = new ArrayList<>();
        int startIdx = 0;
        final int lastMsgIdx = msg.length() - 1;
        
        for (int i=0; i<'Z'-'A'+1; i++) { dict.put(""+(char)('A' + i), i+1);}
        while (startIdx <= lastMsgIdx) {
            for (int lastIdx = lastMsgIdx; lastIdx >= startIdx; lastIdx--) {
                String temp_w = msg.substring(startIdx, lastIdx+1);
                if (dict.containsKey(temp_w)) {
                    answer.add(dict.get(temp_w));
                    dict.put(msg.substring(startIdx, Math.min(lastMsgIdx, lastIdx+2)), ++lastDictIdx);
                    startIdx = lastIdx+1;
                    break;
                }
            }
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }
}