def solution(nums):
    cnt = 0
    nums = sorted(nums)
    maximum = nums[-1]+nums[-2]+nums[-3]
    primes = set(i for i in range(2, maximum+1))
    for i in range(2,int(maximum**0.5)+1):
        if i in primes: primes -= set(i for i in range(2*i, maximum+1, i))
    
    for i in range(len(nums)-2):
        for j in range(i+1, len(nums)-1):
            for k in range(j+1, len(nums)):
                if nums[i]+nums[j]+nums[k] in primes:
                    cnt += 1
    return cnt