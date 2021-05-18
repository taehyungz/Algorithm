import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        List<String> arr = new ArrayList<>();
        List<Integer> inOut = new ArrayList<>(); //0: out, 1: in
        Map<String, String> nameMap = new HashMap<>();
        
        for(String each_record: record) {
           String[] splits = each_record.split(" ");
            if(splits[0].equals("Enter")) {
                arr.add(splits[1]);
                inOut.add(1);
                nameMap.put(splits[1], splits[2]);
            } else if(splits[0].equals("Leave")) {
                arr.add(splits[1]);
                inOut.add(0);
            } else { //change
                nameMap.put(splits[1], splits[2]);
            }
        }
        
        String[] result = new String[arr.size()];
        
        for(int i=0; i<arr.size(); i++) {
            String uid = arr.get(i);
            if(inOut.get(i) == 0) {
                result[i] = nameMap.get(uid) + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            } else {
                result[i] = nameMap.get(uid) + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            }
        }
        return result;
    }
}