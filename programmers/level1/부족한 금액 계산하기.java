class Solution {
    public long solution(int price, int money, int count) {
        long total = 0;
        for (int fee = price; fee <= price * count; fee += price) {
            total += fee;
        }
        if (total > money) return total - money; 
        return 0;
    }
}