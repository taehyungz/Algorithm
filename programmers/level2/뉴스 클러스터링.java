import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        Map<String, Integer> hashMap1 = new HashMap<>();
        Map<String, Integer> hashMap2 = new HashMap<>();
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        
        for(int i=0; i<str1.length()-1; i++) {
            if(!isCharacter(str1.charAt(i)) || !isCharacter(str1.charAt(i+1))) continue;
            String s = str1.substring(i, i+2);
            hashMap1.put(s, hashMap1.getOrDefault(s,0) + 1);
        }
        for(int i=0; i<str2.length()-1; i++) {
            if(!isCharacter(str2.charAt(i)) || !isCharacter(str2.charAt(i+1))) continue;
            String s = str2.substring(i, i+2);
            hashMap2.put(s, hashMap2.getOrDefault(s,0) + 1);
        }
        
        int sameCnt = 0;
        int unionCnt = 0;
        for(String s: hashMap1.keySet()) {
            sameCnt += Math.min(hashMap1.get(s), hashMap2.getOrDefault(s, 0));
            unionCnt += hashMap1.get(s);
        }
        for(String s: hashMap2.keySet()) {
            unionCnt += hashMap2.get(s);
        }
        unionCnt -= sameCnt;
        if(unionCnt == 0 && sameCnt == 0) return 65536;
        return (int)(((double)sameCnt/unionCnt)*65536);
    }
    
    public boolean isCharacter(char ch) {
        if('A' <= ch && ch <= 'Z') return true;
        else if('a' <= ch && ch <= 'z') return true;
        else return false;
    }
}