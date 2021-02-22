def solution(n, arr1, arr2):
    arr = []
    for n1, n2 in zip(arr1, arr2):
        string = ""
        binn1 = bin(n1)[2:]
        binn1 = '0'*(n-len(binn1)) + binn1
        binn2 = bin(n2)[2:]
        binn2 = '0'*(n-len(binn2)) + binn2
        for ch1, ch2 in zip(binn1, binn2):
            if ch1=='1' or ch2=='1': string += '#'
            else: string += ' '
        arr.append(string)
    return arr