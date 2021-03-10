class Solution {
    public String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        int nowLeft = 9;
        int nowRight = 11;
        for(int n: numbers) {
            if(n==0) n = 10;
            else n = n-1;
            if(n==0 || n==3 || n==6) {
                sb.append("L");
                nowLeft = n;
            } else if(n==2 || n==5 || n==8) {
                sb.append("R");
                nowRight = n;
            } else if(getLDistance(nowLeft, n) < getRDistance(nowRight, n)) {
                sb.append("L");
                nowLeft = n;
            } else if(getLDistance(nowLeft, n) > getRDistance(nowRight, n)) {
                sb.append("R");
                nowRight = n;
            } else if(hand.equals("left")) {
                sb.append("L");
                nowLeft = n;
            } else if(hand.equals("right")) {
                sb.append("R");
                nowRight = n;
            }
        }
        return sb.toString();
    }
    
    public int getLDistance(int nowLeft, int n) {
        int ret = Math.abs(nowLeft/3 - n/3);
        if(nowLeft == 1 || nowLeft==4 || nowLeft==7 || nowLeft==10) {
            return ret;
        } else {
            return ret+1;
        }
    }
    
    public int getRDistance(int nowRight, int n) {
        int ret = Math.abs(nowRight/3 - n/3);
        if(nowRight == 1 || nowRight==4 || nowRight==7 || nowRight==10) {
            return ret;
        } else {
            return ret+1;
        }
    }
}