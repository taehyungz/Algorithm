def solution(numbers, hand):
    def get_distance(lt, rt, n):
        ld = abs((lt-1)//3 - (n-1)//3)
        rd = abs((rt-1)//3 - (n-1)//3)
        if lt in [1,4,7,10]: ld += 1
        if rt in [3,6,9,12]: rd += 1
        return ld, rd
    
    ans, lt, rt = "", 10, 12
    
    for n in numbers:
        if n==0: n=11
        if n in [1,4,7]:
            ans += "L"
            lt = n
        elif n in [3,6,9]:
            ans += "R"
            rt = n
        else:
            ld, rd = get_distance(lt, rt, n)
            if (ld==rd and hand=="left") or ld<rd:
                ans += "L"
                lt = n
            else:
                ans += "R"
                rt = n
    return ans