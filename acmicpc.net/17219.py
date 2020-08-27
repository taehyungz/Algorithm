import sys
N, M = map(int, input().split())
site_passwords = []
for i in range(N):
    site, password = sys.stdin.readline().rstrip().split()
    site_passwords.append((site, password))
site_passwords = sorted(site_passwords)
for i in range(M):
    st = sys.stdin.readline().rstrip()
    left = 0
    right = len(site_passwords)
    while left<=right:
        mid = (left+right)//2
        if st>site_passwords[mid][0]:
            left = mid + 1
        elif st<site_passwords[mid][0]:
            right = mid-1
        else:
            print(site_passwords[mid][1])
            break