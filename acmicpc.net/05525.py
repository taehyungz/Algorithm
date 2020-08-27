import sys

def get_failure(pattern, len_pattern, fails):
    fails[0] = 0
    max_match = 0 # 가장 최근에 구한 가장 긴 접두사 길이
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
    i=0 # 문자열의 인덱스
    j=0 # 패턴의 인덱스
    sum=0
    while i<lenS:
        if pattern[j]==S[i]: #패턴 중간 확인중
            i+=1
            j+=1
        if j==len_pattern: #패턴 끝까지 일치, 현재 j는 pattern의 끝 인덱스+1 (즉 길이)
            #print (f"index: {i-j}")
            sum += 1
            j = fails[j-1] # 실패함수를 통해 fails[j-1]만큼 이동한 후부터 구해도 된다는 사실을 앎
        elif i<lenS and pattern[j] != S[i]:
            # mismatch
            if j!=0:
                j=fails[j-1] #실패함수를 통해 매치가 되지 않을 때 그 다음으로 긴 매치되는 구간을 확인, j=0이면 매치되는 부분이 없으므로 문자열의 한 칸 오른쪽부터 다시 시작
            else:
                i+=1
    print(sum)

N = int(input())
M = int(input()) # 문자열 길이
S = sys.stdin.readline().rstrip()
pattern = "I"+"OI"*N

KMPSearch(pattern, S)