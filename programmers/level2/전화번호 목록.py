def solution(phone_book):
    for ph in phone_book:
        candidate = [i for i in phone_book if i!=ph and len(ph)<len(i)] #자신보다 긴 번호들을 후보집합에 넣는다.
        for cand in candidate: #후보집합을 검사한다
            if cand[:len(ph)]==ph:
                return False
    return True