import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        HashMap<String, Integer> hashMap = new HashMap<>();
        for(String[] cloth: clothes) {
            if(hashMap.containsKey(cloth[1])) hashMap.put(cloth[1], hashMap.get(cloth[1])+1);
            else hashMap.put(cloth[1], 1);
        }
        Set<String> keySet = hashMap.keySet();
        int[] arr = new int[keySet.size()];
        int idx = 0;
        Iterator iter = keySet.iterator();
        while(iter.hasNext()) {
            arr[idx++] = hashMap.get(iter.next());
        }
        answer = 1;
        for(int i=0; i<arr.length; i++) {
            answer *= (arr[i]+1); //�� ǰ�� ���ؼ� ������� / �� ���� ���
        }
        return answer-1; //��� ǰ�� �� �Դ� ��� ����
    }
}