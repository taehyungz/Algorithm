import java.util.*;

class Solution {
    public String solution(String[] table, String[] languages, int[] preference) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < languages.length; i++) {
            String language = languages[i];
            int prefScore = preference[i];
            
            for (String companyInfo: table) {
                List<String> prefLanguages = List.of(companyInfo.split(" "));
                if (prefLanguages.contains(language)) map.put(prefLanguages.get(0), map.getOrDefault(prefLanguages.get(0), 0) + (6 - prefLanguages.indexOf(language)) * prefScore);
            }
        }
        List<Map.Entry<String, Integer>> entryList = new LinkedList(map.entrySet());
        Collections.sort(entryList, (a,b) -> {
            if (a.getValue() != b.getValue()) return b.getValue() - a.getValue();
            return a.getKey().compareTo(b.getKey());
        });
        return entryList.get(0).getKey();
    }
}