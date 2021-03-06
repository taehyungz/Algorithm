class Solution {
    public String solution(int a, int b) {
        String[] days = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
        int diffDays = 0;
        for(int i=1; i<a; i++) {
            if(i==2) diffDays += 29;
            else if(i<=7 && i%2==1) diffDays += 31;
            else if(i>7 && i%2==0) diffDays += 31;
            else diffDays += 30;
        }
        diffDays += b-1;
        diffDays = diffDays%7;
        return days[diffDays];
    }
}