def solution(phone_book):
    for ph in phone_book:
        candidate = [i for i in phone_book if i!=ph and len(ph)<len(i)] #�ڽź��� �� ��ȣ���� �ĺ����տ� �ִ´�.
        for cand in candidate: #�ĺ������� �˻��Ѵ�
            if cand[:len(ph)]==ph:
                return False
    return True