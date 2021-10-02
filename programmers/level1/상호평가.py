def solution(scores):
    def get_grade(average_score):
        if average_score >= 90: return 'A'
        elif average_score >= 80: return 'B'
        elif average_score >= 70: return 'C'
        elif average_score >= 50: return 'D'
        else: return 'F'
    
    answer = []
    for idx, score in enumerate(zip(*scores)):
        average_score = 0
        if (max(score) == score[idx] and score.count(score[idx]) == 1) or (min(score) == score[idx] and score.count(score[idx]) == 1):
            average_score = (sum(score)-score[idx]) / (len(score) - 1)
        else: average_score = sum(score) / len(score)
        answer.append(get_grade(average_score))
    return ''.join(answer)