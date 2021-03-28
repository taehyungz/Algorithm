import java.util.*;

class Solution {
    Map<Integer, Integer> hashMap = new HashMap<>();
    List<Integer> keyList;
    
    public int solution(int[] citations) {
        int answer = 0;
        int cnt = citations.length;
        Arrays.sort(citations);
        for(int n: citations) {
            if(!hashMap.containsKey(n)) hashMap.put(n, cnt--);
            else cnt--;
        }
        keyList = new ArrayList(hashMap.keySet());
        Collections.sort(keyList, Comparator.reverseOrder());
        
        for(int citNum=citations.length; citNum>=0; citNum--) {
            int paperCnt = getPaperCnt(citNum); //citNum회 이상 인용된 논문의 수를 리턴
            if(paperCnt >= citNum) return citNum;
        }
        
        return answer;
    }
    public int getPaperCnt(int citNum) {
        int ret = 0;
        for(Integer n: keyList) {
            if(n>=citNum) ret = hashMap.get(n);
            else break;
        }
        return ret;
    }
}