def solution(numbers, target):
    if len(numbers) == 0 and target==0: return 1
    elif len(numbers)==0: return 0
    return solution(numbers[1:], target-numbers[0]) + solution(numbers[1:], target+numbers[0]) #재귀함수로 앞에서부터 타겟넘버에서 더하거나 뺀다