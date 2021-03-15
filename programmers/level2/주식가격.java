import java.util.*;
class Solution {
    public int[] solution(int[] prices) {
        ArrayList<PriceInfo> arr = new ArrayList<>();
        int[] answer = new int[prices.length];
        PriceInfo pi;
        for(int i=0; i<prices.length; i++) {
            int j = arr.size()-1;
            while(j>=0) {
                pi = arr.get(j--);
                if(pi.price > prices[i]) {
                    answer[pi.idx] = i-pi.idx;
                    arr.remove(j+1);
                }
            }
            arr.add(new PriceInfo(i, prices[i]));
        }
        while(arr.size()>0) {
            int idx = arr.get(arr.size()-1).idx;
            answer[idx] = prices.length-idx-1;
            arr.remove(arr.size()-1);
        }
        return answer;
    }
    
    class PriceInfo {
        int idx;
        int price;
        PriceInfo(int idx, int price) {
            this.idx = idx;
            this.price = price;
        }
    }
}