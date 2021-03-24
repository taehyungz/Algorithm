class Solution {
    public long solution(int w, int h) {
        int gcd = getGcd(Math.max(w,h), Math.min(w,h));
        int miniW = w/gcd;
        int miniH = h/gcd;
        double leaning = (double)miniH/miniW;
        long miniAns = 0;
        for(int i=1; i<=miniW; i++) {
            double left = leaning * (i-1);
            double right = leaning * i;
            long leftH = (long)left;
            long rightH = (long)Math.ceil(right);
            miniAns+=rightH-leftH;
        }
        
        return (long)w*h - miniAns*gcd;
    }
    
    public int getGcd(int w, int h) {
        if(h==0) return w;
        return getGcd(h, w%h);
    }
}