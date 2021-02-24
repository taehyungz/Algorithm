def solution(n):
    #124를 012처럼 생각해서 3진법 문제로 변환
    def get_decimal_3(temp_n):
        while temp_n>0:
            decimal_3.append(temp_n%3 if temp_n%3!=0 else 4)
            temp_n //= 3
            if decimal_3[-1]==4: temp_n -= 1
            # 3으로 나누기 때문에 자릿수가 올라감.
            # 자릿수 올림 대신 -1을 해서 자릿수 올림 발생 막음
    decimal_3 = []
    get_decimal_3(n)
    return ''.join(map(str,decimal_3[::-1]))