def solution(s):
    st_dic = {')': '(', '}': '{', ']': '['}
    
    def is_right(s2):
        cnt1 = cnt2 = cnt3 = 0
        st = []
        if len(s2) % 2 == 1: return 0
        for ch in s2:
            if ch in ['(', '{', '[']: st.append(ch)
            elif len(st)==0: return 0
            elif st[-1] == st_dic[ch]: st.pop()
            else: return 0
        return 1

    answer = 0
    for i in range(len(s)):
        s2 = s[i:] + s[:i]
        answer += is_right(s2)
    return answer