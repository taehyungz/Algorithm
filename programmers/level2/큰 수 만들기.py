def solution(number, k):
    idx = 0
    answer = []
    for i in range(len(number)-k):
        temp_n = "0"
        temp_idx = idx
        for j in range(idx, idx+1+k): #지워야 되는 개수+1만큼 반복해서 지울 수 있는 k개 탐색
            if number[j]>temp_n:
                temp_n = number[j]
                temp_idx = j
                if temp_n=='9': break #더이상 확인하지 않아도 된다
        k -= (temp_idx-idx)
        idx = temp_idx+1
        answer.append(temp_n)
    return ''.join(answer)