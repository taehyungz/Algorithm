def solution(files):
    names = []
    for file in files:
        temp = []
        for idx, ch in enumerate(file):
            if ch.isdigit():
                temp.append(file[:idx])
                for i in range(idx+1, len(file)):
                    if not file[i].isdigit():
                        temp.append(file[idx:i])
                        temp.append(file[i:])
                        break
                if len(temp)==1: temp.append(file[idx:])
                break
        names.append(temp)
    return list(map(''.join,sorted(names, key = lambda x: (x[0].lower(), int(x[1])))))