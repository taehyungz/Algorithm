def solution(n):
    #124�� 012ó�� �����ؼ� 3���� ������ ��ȯ
    def get_decimal_3(temp_n):
        while temp_n>0:
            decimal_3.append(temp_n%3 if temp_n%3!=0 else 4)
            temp_n //= 3
            if decimal_3[-1]==4: temp_n -= 1
            # 3���� ������ ������ �ڸ����� �ö�.
            # �ڸ��� �ø� ��� -1�� �ؼ� �ڸ��� �ø� �߻� ����
    decimal_3 = []
    get_decimal_3(n)
    return ''.join(map(str,decimal_3[::-1]))