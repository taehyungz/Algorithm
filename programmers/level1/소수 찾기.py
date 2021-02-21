import math
def solution(n):
    prime_number = []
    for i in range(2, n+1):
        flag = True
        for j in prime_number:
            if j>math.sqrt(i): break
            if i%j==0:
                flag = False
                break
        if flag: prime_number.append(i)
    return len(prime_number)