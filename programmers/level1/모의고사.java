class Solution {
    public int[] solution(int[] answers) {
        int[] person1 = {1,2,3,4,5};
        int[] person2 = {2,1,2,3,2,4,2,5};
        int[] person3 = {3,3,1,1,2,2,4,4,5,5};
        int[] score = {0,0,0};
        for(int i=0; i<answers.length;i++) {
            if(answers[i]==person1[i%person1.length]) score[0]++;
            if(answers[i]==person2[i%person2.length]) score[1]++;
            if(answers[i]==person3[i%person3.length]) score[2]++;
        }
        int maxScore = Math.max(score[0], Math.max(score[1], score[2]));
        int cnt=0;
        for(int sc: score) if(sc==maxScore) cnt++;
        int[] answer = new int[cnt];
        int idx = 0;
        for(int i=0; i<3; i++) if(score[i]==maxScore) answer[idx++] = i+1;
        return answer;
    }
}