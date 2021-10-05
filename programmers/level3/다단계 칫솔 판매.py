import collections

def solution(enroll, referral, seller, amount):
    def dfs(ref, total_gain):
        if ref == "-": return
        fee = int(total_gain * 0.1)
        gain = total_gain - fee
        salary[ref] += gain
        if fee > 0: dfs(emp_to_ref[ref], fee)
            
    answer = []
    emp_to_ref = {}
    salary = collections.defaultdict(int)
    
    for i in range(len(enroll)):
        emp_to_ref[enroll[i]] = referral[i]
    
    for i in range(len(seller)):
        dfs(seller[i], amount[i]*100)
    
    for i in range(len(enroll)):
        answer.append(salary[enroll[i]])
    return answer