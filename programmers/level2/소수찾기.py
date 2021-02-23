from itertools import permutations
def solution(numbers):
    maked_num = set()
    for length in range(1, len(numbers)+1):
        maked_num.update(set(map(int,map(''.join, permutations(numbers, length)))))
		#permutations를 통해 만들 수 있는 모든 문자열을 만들고, int()를 통해 0이 첫자리에 있는 경우를 없앤다. set으로 중복된 수를 없앤다.
    maxnum = max(maked_num)
    prime_num = set(i for i in range(2, maxnum+1)) #에라토스테네스의 체 이용
    for i in range(2, maxnum+1):
        if i in prime_num:
            prime_num -= set(j for j in range(i*2, maxnum+1, i))
    cnt = 0
    for n in maked_num:
        if n in prime_num: cnt += 1
    return cnt