import java.util.HashMap;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> hashMap = new HashMap<>();
        for(String part: participant) {
            hashMap.put(part, hashMap.getOrDefault(part,0)+1);
        }
        for(String comp: completion) {
            int cnt = hashMap.get(comp);
            hashMap.remove(comp);
            hashMap.put(comp, cnt-1);
        }
        for(String key: hashMap.keySet()){
            if(hashMap.get(key)!=0) {
                answer = key;
                break;
            }
        }
        return answer;
    }
}