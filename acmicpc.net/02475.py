import math

a, b, c, d, e = map(int, input().split())
ans = math.pow(a,2) + math.pow(b,2) + math.pow(c,2) + math.pow(d,2) + math.pow(e,2)
ans = int(ans % 10)
print(ans)