def solution(s):
    answer = []
    for word in s.split(' '): #������ ������ �ϳ��� ���ҷ� �ν�
        if word and word[0].isalpha(): #�����̾����� word�� �� ����Ʈ. ���ڷ� ������ ���
            answer.append(word[0].upper()+word[1:].lower())
        elif word: #���ڷ� ����
            answer.append(word[0]+word[1:].lower())
        answer.append(' ') #�ܾ���̴� ������ �־���. �Ǵ� �����̾��� ���
    answer.pop()
    return ''.join(answer)
    