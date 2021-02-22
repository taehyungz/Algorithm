def solution(arr1, arr2):
    for idx, each_arr in enumerate(arr2):
        for j in range(len(each_arr)):
            arr1[idx][j] += arr2[idx][j]
    return arr1