import java.util.*;

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        HashMap<Character, Integer> hashMap = new HashMap<>();
        for(int i=0; i<skill.length(); i++) {
            hashMap.put(skill.charAt(i), i);
        }
        for(String skills: skill_trees) {
            int minimum = -1;
            boolean check = false;
            for(int i=0; i<skills.length(); i++) {
                char ch = skills.charAt(i);
                int val = hashMap.getOrDefault(ch,-1);
                if(val==-1) continue;
                else if(val!=minimum+1) { //����� �ʾҴµ� ���� ��ų�� ����� ���
                    check = true;
                    break;
                } else {
                    minimum = val;
                }
            }
            if(!check) answer+=1;
        }
        return answer;
    }
}