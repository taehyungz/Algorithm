def solution(s):
    cnt_bin, cnt_remove0 = 0, 0
    while True:
        cnt_remove0, cnt_bin = cnt_remove0 + s.count('0'), cnt_bin + 1
        s = bin(len("1" * s.count("1")))[2:]
        if s=="1": return [cnt_bin, cnt_remove0]