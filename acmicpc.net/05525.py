import sys

def get_failure(pattern, len_pattern, fails):
    fails[0] = 0
    max_match = 0 # ���� �ֱٿ� ���� ���� �� ���λ� ����
    i = 1

    while i<len_pattern:
        if pattern[i]==pattern[max_match]:
            max_match += 1
            fails[i] = max_match
            i += 1
        else:
            if max_match!=0:
                max_match = fails[max_match-1]
            else:
                fails[i] = 0
                i += 1
def KMPSearch(patern, S):
    lenS = len(S)
    len_pattern = len(pattern)
    fails = [0] * len_pattern
    get_failure(pattern, len_pattern, fails)
    i=0 # ���ڿ��� �ε���
    j=0 # ������ �ε���
    sum=0
    while i<lenS:
        if pattern[j]==S[i]: #���� �߰� Ȯ����
            i+=1
            j+=1
        if j==len_pattern: #���� ������ ��ġ, ���� j�� pattern�� �� �ε���+1 (�� ����)
            #print (f"index: {i-j}")
            sum += 1
            j = fails[j-1] # �����Լ��� ���� fails[j-1]��ŭ �̵��� �ĺ��� ���ص� �ȴٴ� ����� ��
        elif i<lenS and pattern[j] != S[i]:
            # mismatch
            if j!=0:
                j=fails[j-1] #�����Լ��� ���� ��ġ�� ���� ���� �� �� �������� �� ��ġ�Ǵ� ������ Ȯ��, j=0�̸� ��ġ�Ǵ� �κ��� �����Ƿ� ���ڿ��� �� ĭ �����ʺ��� �ٽ� ����
            else:
                i+=1
    print(sum)

N = int(input())
M = int(input()) # ���ڿ� ����
S = sys.stdin.readline().rstrip()
pattern = "I"+"OI"*N

KMPSearch(pattern, S)