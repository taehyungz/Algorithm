def solution(s):
    answer = []
    for word in s.split(' '): #공백이 있으면 하나의 원소로 인식
        if word and word[0].isalpha(): #공백이었으면 word는 빈 리스트. 문자로 시작한 경우
            answer.append(word[0].upper()+word[1:].lower())
        elif word: #숫자로 시작
            answer.append(word[0]+word[1:].lower())
        answer.append(' ') #단어사이는 공백을 넣어줌. 또는 공백이었던 경우
    answer.pop()
    return ''.join(answer)
    