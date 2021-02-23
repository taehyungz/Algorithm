from itertools import permutations
def solution(numbers):
    maked_num = set()
    for length in range(1, len(numbers)+1):
        maked_num.update(set(map(int,map(''.join, permutations(numbers, length)))))
		#permutations�� ���� ���� �� �ִ� ��� ���ڿ��� �����, int()�� ���� 0�� ù�ڸ��� �ִ� ��츦 ���ش�. set���� �ߺ��� ���� ���ش�.
    maxnum = max(maked_num)
    prime_num = set(i for i in range(2, maxnum+1)) #�����佺�׳׽��� ü �̿�
    for i in range(2, maxnum+1):
        if i in prime_num:
            prime_num -= set(j for j in range(i*2, maxnum+1, i))
    cnt = 0
    for n in maked_num:
        if n in prime_num: cnt += 1
    return cnt