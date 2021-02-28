def solution(arr1, arr2):
    def mul_arr(n1, n2):
        gob = 0
        for i1, i2 in zip(n1, n2):
            gob += i1*i2
        return gob
    answer = []
    for idx, arr1_ in enumerate(arr1):
        answer.append([])
        for idx2, arr2_ in enumerate(zip(*arr2)):
            answer[idx].append([])
            answer[idx][idx2] = mul_arr(arr1_, arr2_)
    return answer