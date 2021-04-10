import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer;
        Map<Integer, Boolean> numberMap = new HashMap<>();
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        int idx = 1;
        while(idx < s.length()) { //배열에 잘라서 넣기
            int subFinishIdx = s.indexOf("}", idx);
            String subNumbers = s.substring(idx+1, subFinishIdx);
            
            int tempIdx = 0;
            ArrayList<Integer> temp = new ArrayList<>();
            while(tempIdx < subNumbers.length()) { //내부 집합을 배열에 넣기
                int last = subNumbers.indexOf(",", tempIdx);
                if(last==-1) {
                    temp.add(Integer.parseInt(subNumbers.substring(tempIdx)));
                    break;
                }
                else temp.add(Integer.parseInt(subNumbers.substring(tempIdx, last)));
                tempIdx = last+1;
            }
            arr.add(temp);
            idx = subFinishIdx+2;
        }
        //길이로 정렬
        Collections.sort(arr, (a,b) -> {
            if(a.size() < b.size()) return -1;
            else if(a.size() > b.size()) return 1;
            else return 0;
        });
        
        answer = new int[arr.size()];
        for(int i=0; i<arr.size(); i++) {
            ArrayList<Integer> temp_arr = arr.get(i);
            for(int j=0; j<temp_arr.size(); j++) {
                if(!numberMap.containsKey(temp_arr.get(j))) {
                    numberMap.put(temp_arr.get(j), true);
                    answer[i] = temp_arr.get(j);
                    break;
                }
            }
        }
        return answer;
    }
}