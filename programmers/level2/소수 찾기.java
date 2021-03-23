import java.util.*;
class Solution {
    public int solution(String numbers) {
        int answer = 0;
        int max = 0;
        Set<Integer> hashArr = new HashSet<>();
        permutations(numbers, "", hashArr);
        for(int n: hashArr) if(max<n) max=n;
        boolean[] primes = new boolean[max+1];
        Arrays.fill(primes, Boolean.TRUE);
        primes[0] = false;
        primes[1] = false;
        
        for(int i=2; i< (int)Math.sqrt(max)+1; i++)
            if(primes[i])
                for(int j=i*2; j<= max; j+=i)
                    primes[j] = false;
        for(int n: hashArr) if(primes[n]) answer++;
        return answer;
    }
    
    public void permutations(String nums, String prefix, Set<Integer> arr) {
        if(!prefix.equals("")) arr.add(Integer.parseInt(prefix));
        for(int i=0; i<nums.length(); i++)
            permutations(nums.substring(0, i)+nums.substring(i+1,nums.length()), prefix+nums.charAt(i), arr);
    }
}