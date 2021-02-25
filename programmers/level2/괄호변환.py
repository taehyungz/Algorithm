def solution(p):
    def check_right(string_u): #�ùٸ� ���ڿ����� �˻�
        st = []
        for ch in string_u:
            if ch=='(':
                st.append('(')
            elif len(st)==0:
                return False
            else: st.pop()
        return True
    
    def make_u(string_u): #u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ �ݴ�� �ٲ�
        new_u = list(string_u)[1:-1]
        for i in range(len(new_u)):
            if new_u[i]=='(': new_u[i] = ')'
            else: new_u[i] = '('
        return ''.join(new_u)
    
    if not p: return p #1
    left = right = 0
    u = ""
    v = ""
    for i in range(len(p)):
        if p[i]=='(': left += 1
        else: right += 1
        if left == right:
            u = p[:left+right]
            v = p[left+right:]
            break
    if check_right(u):
        return u+solution(v)
    else:
        return "("+solution(v)+")"+make_u(u)