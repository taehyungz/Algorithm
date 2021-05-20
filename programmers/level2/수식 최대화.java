import java.util.*;

class Solution {
    public long solution(String expression) {
        StringTokenizer stk = new StringTokenizer(expression, "+*-", true);
        List<Long> arr = new ArrayList<>();
        List<Character> ops = new ArrayList<>();
        boolean check = true;
        String[] opRanks = {"*+-", "*-+", "+*-", "+-*", "-*+", "-+*"};
        long maxValue = 0;
        
        while(stk.hasMoreTokens()) {
            if(check) arr.add(Long.parseLong(stk.nextToken()));
            else ops.add(stk.nextToken().charAt(0));
            check = !check;
        }
        for(String opRank: opRanks) { //이번 턴 연산자 순위
            List<Long> eachArr = new ArrayList<>(arr);
            List<Character> eachOps = new ArrayList<>(ops);
            // System.out.println("opRank : " + opRank);
            // System.out.println(arr);
            // System.out.println(ops);
            for(char op: opRank.toCharArray()) { //연산자
                List<Long> stack = new ArrayList<>();
                List<Character> tempOp = new ArrayList<>();
                int idx = 0;
                int opIdx = 0;
                stack.add(eachArr.get(idx++));
                while(opIdx < eachOps.size()) {
                    if(eachOps.get(opIdx++) == op) {
                        long numberA = stack.remove(stack.size()-1);
                        long numberB = eachArr.get(idx++);
                        if(op == '*') stack.add(numberA * numberB);
                        else if(op == '+') stack.add(numberA + numberB);
                        else stack.add(numberA - numberB);
                    } else {
                        stack.add(eachArr.get(idx++));
                        tempOp.add(eachOps.get(opIdx-1));
                    }
                    // System.out.println(stack);
                    // System.out.println(tempOp);
                }
                eachArr = stack;
                eachOps = tempOp;   
            }
            maxValue = Math.max(maxValue, Math.abs(eachArr.get(0)));
        }
        return (long)maxValue;
    }
}