class Solution {
    public String solution(String[] seoul) {
        for(int i=0; i<seoul.length; i++) {
            if(seoul[i].equals("Kim")) {
                String str = "�輭���� "+i+"�� �ִ�";
                return str;
            }
        }
        return "";
    }
}