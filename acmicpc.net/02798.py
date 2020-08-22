N, M = map(int,input().split())
ls = list(map(int,input().split()))
diff=300000
ans = 300000
for i in range(N-1,1,-1):
    for j in range(i - 1, 0, -1):
        for k in range(j - 1, -1, -1):
            if i == j or j == k or j == i: continue
            diff = M - ls[i] - ls[j] - ls[k]
            if diff<0: continue
            elif diff<ans:
                ans = diff
print(M-ans)