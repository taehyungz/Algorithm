import java.util.*;

class Solution {
    Map<String, Integer> menuOrderCnt = new HashMap<>();
    Map<Integer, PriorityQueue<MenuInfo>> bestMenus = new HashMap<>(); //length, pq
    
    public String[] solution(String[] orders, int[] course) {
        for(String order: orders) {
            char[] chs = order.toCharArray();
            Arrays.sort(chs);
            for(int i=0; i<order.length()-1; i++) {
                dfs(chs, ""+chs[i], i, 1); //chs, 문자열, 인덱스, 길이
            }
        }
        for(Map.Entry<String, Integer> entry: menuOrderCnt.entrySet()) {
            if(entry.getValue() < 2) continue;
            MenuInfo menuInfo = new MenuInfo(entry.getValue(), entry.getKey());
            PriorityQueue<MenuInfo> pq = bestMenus.getOrDefault(menuInfo.menu.length(),
                                                                new PriorityQueue<MenuInfo>((MenuInfo a, MenuInfo b) -> {
                                                                    if(a.count > b.count) return -1;
                                                                    else if(a.count < b.count) return 1;
                                                                    else return a.menu.compareTo(b.menu);
                                                                }));
            pq.offer(menuInfo);
            bestMenus.put(menuInfo.menu.length(), pq);
        }
        ArrayList<String> arr = new ArrayList<>();
        for(int cnt: course) {
            PriorityQueue<MenuInfo> pq = bestMenus.getOrDefault(cnt, new PriorityQueue<MenuInfo>());
            int size = 0;
            if(!pq.isEmpty()) size = pq.peek().count;
            while(!pq.isEmpty()) {
                MenuInfo menuInfo = pq.poll();
                if(size != menuInfo.count) break;
                arr.add(menuInfo.menu);
            }
        }
        Collections.sort(arr);
        String[] answer = arr.toArray(new String[arr.size()]);
        return answer;
    }
    
    public void dfs(char[] chs, String menu, int idx, int length) {
        if(length>1) menuOrderCnt.put(menu, menuOrderCnt.getOrDefault(menu, 0) + 1);
        for(int i=idx+1; i<chs.length; i++) {
            dfs(chs, menu+chs[i], i, length+1);
        }
    }
    
    public class MenuInfo {
        int count;
        String menu;
        
        MenuInfo(int count, String menu) {
            this.count = count;
            this.menu = menu;
        }
    }
}