class Solution {
    public int solution(String s) {
        int answer = 1000;
        
        for(int size=1; size<=s.length(); size++) {
            int idx = 0;
            StringBuilder sb = new StringBuilder();
            
            while(idx+size < s.length()) {
                int recur_cnt = 1;
                String now_str = s.substring(idx, idx+size);
                while(idx+size*2-1 < s.length()) {
                    String s2 = s.substring(idx+size, idx+size*2);
                    if(now_str.equals(s2)) {
                        recur_cnt++;
                        idx += size;
                    } else break;
                }
                if(recur_cnt>1) sb.append(""+recur_cnt+now_str);
                else sb.append(now_str);
                idx += size;
            }
            sb.append(s.substring(idx, s.length()));
            answer = Math.min(answer, sb.toString().length());
        }
        return answer;
    }
}