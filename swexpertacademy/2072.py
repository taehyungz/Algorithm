T = int(input())
for test_case in range(1,T+1):
    nums = list(map(int, input().split()))
    total = 0
    for n in nums:
        if n % 2 != 0:
            total += n
  
    print("#{} {}".format(test_case, total))