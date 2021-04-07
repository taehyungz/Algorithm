import java.util.*;

class Solution {
    static Map<String, ArrayList<Integer>> candidatesInfo;
    static String[] eachCandidateInfo;
    boolean[] visited = new boolean[4];
    
    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        candidatesInfo = new HashMap<>();
        
        for(String candidateString: info) {
            //문자열 정보를 문자열 배열로 변환
            candidateStringToStringArr(candidateString);
            //해시맵에 저장
            writeIntoHashMap(eachCandidateInfo);
            for(int i=0; i<4; i++) {
                dfs(eachCandidateInfo, i);   
            }
        }
        
        //정렬
        Set<String> keys = candidatesInfo.keySet();
        for(String key: keys) {
            if(candidatesInfo.containsKey(key)) {
                ArrayList<Integer> arr = candidatesInfo.get(key);
                Collections.sort(arr);
                candidatesInfo.put(key, arr);
            }
        }
        //쿼리 검색
        for(int i=0; i<query.length; i++) {
            String q = query[i];
            String[] convertedQuery = makeQuery(q);
            answer[i] = findCnt(convertedQuery);
        }
        return answer;
    }
    
    public int findCnt(String[] convertedQuery) { //개수 반환
        if(!candidatesInfo.containsKey(convertedQuery[0])) return 0;
        int cost = Integer.parseInt(convertedQuery[1]);
        ArrayList<Integer> arr = candidatesInfo.get(convertedQuery[0]);
        int underCnt = binarySearchCnt(arr, cost);
        return arr.size() - underCnt;
    }
    
    public int binarySearchCnt(ArrayList<Integer> arr, int cost) {
        int left = 0;
        int right = arr.size()-1;
        int mid = 0;
        while(left<=right) {
            mid = left + (right-left)/2;
            if(arr.get(mid) == cost) break;
            else if(arr.get(mid) > cost) right = mid - 1;
            else left = mid+1;
        }
        while(mid>=0 && (int)arr.get(mid) >= cost) mid--;
        return mid+1;
    }
    
    public String[] makeQuery(String q) { //쿼리를 저장한 문자열 형태로 변환
        StringBuilder sb = new StringBuilder();
        int lastIdx = 0;
        int idx = 0;
        for(int i=0; i<4; i++) {
            idx = q.indexOf(" ", lastIdx);
            sb.append(q.substring(lastIdx, idx));
            lastIdx = idx+5;
        }
        String[] ret = new String[2];
        ret[0] = sb.toString();
        ret[1] = q.substring(idx+1);
        return ret;
    }
    public void candidateStringToStringArr(String candidateString) { //지원자 정보 하나를 분리해서 배열에 담음
        ArrayList<String> candidate = new ArrayList<>();
        int lastIdx = 0;
        StringBuilder sb = new StringBuilder();

        for(int i=0; i<candidateString.length(); i++) {
            char ch = candidateString.charAt(i);
            if(ch == ' ') {
                String candidateInfoEach = candidateString.substring(lastIdx, i);
                candidate.add(candidateInfoEach);
                lastIdx = i+1;
            }
        }
        candidate.add(candidateString.substring(lastIdx));            
        this.eachCandidateInfo = candidate.toArray(new String[candidate.size()]);;
    }
    
    public void dfs(String[] eachCandidateInfo, int idx) {
        visited[idx] = true;
        String temp = eachCandidateInfo[idx];
        eachCandidateInfo[idx] = "-";
        writeIntoHashMap(eachCandidateInfo);
        for(int i = idx+1; i<4; i++) {
            if(!visited[i]) dfs(eachCandidateInfo, i);
        }
        visited[idx] = false;
        eachCandidateInfo[idx] = temp;
    }
    
    public void writeIntoHashMap(String[] strs) {
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<strs.length-1; i++) {
            sb.append(strs[i]);
        }
        ArrayList<Integer> arr = candidatesInfo.getOrDefault(sb.toString(), new ArrayList<Integer>());
        Integer score = Integer.parseInt(strs[strs.length-1]);
        arr.add(score);
        candidatesInfo.put(sb.toString(), arr);
    }
}