def solution(number, k):
    idx = 0
    answer = []
    for i in range(len(number)-k):
        temp_n = "0"
        temp_idx = idx
        for j in range(idx, idx+1+k): #������ �Ǵ� ����+1��ŭ �ݺ��ؼ� ���� �� �ִ� k�� Ž��
            if number[j]>temp_n:
                temp_n = number[j]
                temp_idx = j
                if temp_n=='9': break #���̻� Ȯ������ �ʾƵ� �ȴ�
        k -= (temp_idx-idx)
        idx = temp_idx+1
        answer.append(temp_n)
    return ''.join(answer)