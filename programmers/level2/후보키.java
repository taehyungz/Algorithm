import java.util.*;

class Solution {
    Set<String> candKeys;
    String[][] relation2;
    int result = 0;
    List<String> candidate = new ArrayList<>();
    
    public int solution(String[][] relation) {
        int tupleLength = relation[0].length;
        candKeys = new HashSet<>();
        
        relation2 = new String[relation[0].length][relation.length];
        for(int i=0; i<relation.length; i++)
            for(int j=0; j<relation[0].length; j++)
                relation2[j][i] = relation[i][j];
        
        // System.out.println(Arrays.deepToString(relation2));
        for(int i=0; i<relation2.length; i++) {
            dfs(""+i);
        }
        Collections.sort(candidate, (s1, s2) -> {
            if(s1.length() < s2.length()) return -1;
            else if(s1.length() == s2.length()) return 0;
            else return 1;
        });
        for(String s: candidate) {
            findKeys(s);
        }
        return result;
    }
    
    public void dfs(String colIdxs) {
        candidate.add(colIdxs);
        for(int i=colIdxs.charAt(colIdxs.length()-1)-'0'+1; i<relation2.length; i++) {
            dfs(colIdxs+i);
        }
    }
    
    public void findKeys(String colIdxs) { //조합한 컬럼idx가 키 역할을 하는지 식별
        Set<String> attrSets = new HashSet<>(); //튜플 각각의 컬럼조합들을 넣음
        int entities = 0;
        for(int tuple=0; tuple<relation2[0].length; tuple++) {
            StringBuilder sb = new StringBuilder();
            for(char ch: colIdxs.toCharArray()) { //컬럼들
                int colNo = ch - '0';
                sb.append(relation2[colNo][tuple]);
            }
            entities++;
            attrSets.add(sb.toString());
        }
        if(attrSets.size() == entities) {
            if(isMinimum(colIdxs)) {
                result++;
                candKeys.add(colIdxs);
            }
        }
    }
    
    public boolean isMinimum(String colIdxs) { //식별한 키가 최소키인지를 확인
        for(String candKey: candKeys) {
            boolean check = false;
            if(candKey.length() > colIdxs.length()) {
                for(char partKey: colIdxs.toCharArray()) {
                    if(!isIn(candKey, partKey)) {
                        check = true;
                    }
                }
            } else {
                for(char partKey: candKey.toCharArray()) {
                    if(!isIn(colIdxs, partKey)) {
                        check = true;
                    }
                }
            }
            if(!check) return false;
        }
        return true;
    }
    
    public boolean isIn(String originKey, char ch) {
        for(char keyCh: originKey.toCharArray()) {
            if(keyCh == ch) return true;
        }
        return false;
    }
}